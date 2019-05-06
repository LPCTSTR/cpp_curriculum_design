
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



