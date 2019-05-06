//
// Created by LPCTSTR_MSR on 2019/4/18.
//


#include "CardFactory.h"

CardFactory &CardFactory::setCardMap(const vector<pair<string, string>> &CardMap) {
    CardFactory::CardMap = CardMap;
    return *this;
}

CardFactory &CardFactory::SetSingleCardNum(int num) {
    SingleCardNum = num;
    return *this;
}

void CardFactory::PoolShuffle(Object_Pool<Card> &pool) {
    vector<pCard> tmp;
    if (CardMap.size() != 0) {
        for (int i = 0; i < CardMap.size(); i++)
            for (int j = 0; j < SingleCardNum; j++) {
                auto p = pool.Get();
                p->setAattr(CardMap[i].first);
                p->setBattr(CardMap[i].second);
                tmp.push_back(move(p));
            }
    } else {
        for (int i = 0; i < CardMapEx.size(); i++)
            for (int j = 0; j < CardMapEx[i].second; j++) {
                auto p = pool.Get();
                p->setAattr(CardMapEx[i].first.first);
                p->setBattr(CardMapEx[i].first.second);
                tmp.push_back(move(p));
            }
    }
    //以时间为种子进行随机排序
    long long int seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(tmp.begin(), tmp.end(), default_random_engine(seed));
}

/**
 * 设置默认牌库类型 扑克
 */
void CardFactory::SetDefault() {
    CardMap.clear();
    CardMapEx = {
            {{"A",           "Spade"},   1},
            {{"A",           "Heart"},   1},
            {{"A",           "Diamond"}, 1},
            {{"A",           "Club"},    1},
            {{"2",           "Spade"},   1},
            {{"2",           "Heart"},   1},
            {{"2",           "Diamond"}, 1},
            {{"2",           "Club"},    1},
            {{"3",           "Spade"},   1},
            {{"3",           "Heart"},   1},
            {{"3",           "Diamond"}, 1},
            {{"3",           "Club"},    1},
            {{"4",           "Spade"},   1},
            {{"4",           "Heart"},   1},
            {{"4",           "Diamond"}, 1},
            {{"4",           "Club"},    1},
            {{"5",           "Spade"},   1},
            {{"5",           "Heart"},   1},
            {{"5",           "Diamond"}, 1},
            {{"5",           "Club"},    1},
            {{"6",           "Spade"},   1},
            {{"6",           "Heart"},   1},
            {{"6",           "Diamond"}, 1},
            {{"6",           "Club"},    1},
            {{"7",           "Spade"},   1},
            {{"7",           "Heart"},   1},
            {{"7",           "Diamond"}, 1},
            {{"7",           "Club"},    1},
            {{"8",           "Spade"},   1},
            {{"8",           "Heart"},   1},
            {{"8",           "Diamond"}, 1},
            {{"8",           "Club"},    1},
            {{"9",           "Spade"},   1},
            {{"9",           "Heart"},   1},
            {{"9",           "Diamond"}, 1},
            {{"9",           "Club"},    1},
            {{"10",          "Spade"},   1},
            {{"10",          "Heart"},   1},
            {{"10",          "Diamond"}, 1},
            {{"10",          "Club"},    1},
            {{"J",           "Spade"},   1},
            {{"J",           "Heart"},   1},
            {{"J",           "Diamond"}, 1},
            {{"J",           "Club"},    1},
            {{"Q",           "Spade"},   1},
            {{"Q",           "Heart"},   1},
            {{"Q",           "Diamond"}, 1},
            {{"Q",           "Club"},    1},
            {{"K",           "Spade"},   1},
            {{"K",           "Heart"},   1},
            {{"K",           "Diamond"}, 1},
            {{"K",           "Club"},    1},
            {{"Joker",       "-"},        1},
            {{"Extra Joker", "-"},        1}
    };
}
