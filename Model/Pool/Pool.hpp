
#include "../pch.h"
using namespace std;

template<class T>
class Object_Pool {
public:
    using DeleterType = function<void(T *)>;
    void Init(int num) {
        for (int i = 0; i < num; i++)
            pool_.push_back(unique_ptr<T>(new T()));
    }

    void add(std::unique_ptr<T> t) {
        pool_.push_back(std::move(t));
    }

    std::unique_ptr<T, DeleterType> Get() {
        if (pool_.empty())
            throw std::logic_error("Pool is empty.");

        std::unique_ptr<T, DeleterType> ptr(pool_.back().release(), [this](T *t) {
                                                pool_.push_back(unique_ptr<T>(t));
                                            }
        );
        pool_.pop_back();
        return std::move(ptr);
    }

    bool empty() const {
        return pool_.empty();
    }

    size_t size() const {
        return pool_.size();
    }
private:
    std::vector<std::unique_ptr<T>> pool_;
};


/* cmd_test
 *        Object_Pool<BT> pool;
    pool.Init(2);
    vector<shared_ptr<BT>> p;
    p.push_back(pool.Get());
    p[0]->setType(123);
    auto ps=pool.Get();
    cout<<ps->type<<endl;
    p.pop_back();
    auto qs=pool.Get();
    cout<<qs->type<<endl;
    pool.Init(1);
    qs.reset();
    auto kqs=pool.Get();
    cout<<kqs->type<<endl;
    auto k2qs=pool.Get();
 *
// ObjectPool.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

//



#include "pch.h"

#include <iostream>

#include <string>

#include <functional>

#include <memory>

#include <map>



using namespace std;

const int MaxObjectNum = 10;



class NonCopyable

{

protected:

	NonCopyable() = default;

	~NonCopyable() = default;

	// 禁用复制构造

	NonCopyable(const NonCopyable&) = delete;

	// 禁用赋值构造

	NonCopyable& operator = (const NonCopyable&) = delete;

};



template<typename T>

class ObjectPool :NonCopyable

{

	template<typename...Args>

	using Constructor = function<shared_ptr<T>(Args...)>;

public:

	// 默认创建多少个对象

	template<typename... Args>

	void Init(size_t num, Args&&...args)

	{

		if (num <=0 || num>MaxObjectNum)

		{

			throw logic_error("object num out of range.");

		}

		// 不区分引用

		auto constructName = typeid(Constructor<Args...>).name();

		for (size_t i =0;i<num;i++)

		{

			m_object_map.emplace(constructName, shared_ptr<T>(new T(forward<Args>(args)...), [this, constructName](T*p) {

				//删除器中不直接删除对象，而是回收到对象池中，以供下次使用

				m_object_map.emplace(move(constructName), shared_ptr<T>(p));

			}));



		}

	}

	// 从对象池中获取一个对象

	template<typename... Args>

	shared_ptr<T> Get()

	{

		string constructName = typeid(Constructor<Args...>).name();

		auto range = m_object_map.equal_range(constructName);

		for (auto it = range.first; it != range.second;++it)

		{

			auto ptr = it->second;

			m_object_map.erase(it);

			return ptr;

		}

		return nullptr;

	}

private:

	multimap<string,shared_ptr<T>> m_object_map;

};



struct BigObject

{

	BigObject() {}

	BigObject(int a) {}



	BigObject(const int& a, const int&b) {}

	void Print(const string& str)

	{

		cout << str << endl;

	}

};



void Print(shared_ptr<BigObject>p, const string& str)

{

	if (p != nullptr)

	{

		p->Print(str);

	}

}



void TestObjPool()

{

	ObjectPool<BigObject> pool;

	pool.Init(2);

	{

		auto p = pool.Get();

		Print(p, "p");

		auto p2 = pool.Get();

		Print(p2, "p2");

		// 出了作用哉之后，对象池返回出来的对象又会自动回收

	}

	auto p = pool.Get();

	Print(p, "p");

	auto p2 = pool.Get();

	Print(p2, "p2");



	// 对象池支持重载构造函数

	pool.Init(2, 1);

	auto p4 = pool.Get<int>();

	Print(p4, "p4");

	pool.Init(2, 1, 2);

	auto p5 = pool.Get<int, int>();

	Print(p5, "p5");

}

int main()

{

	TestObjPool();

}






 */
