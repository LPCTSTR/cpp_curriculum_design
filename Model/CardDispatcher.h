//
// Created by LPCTSTR_MSR on 2019/4/18.
//

#ifndef CURRICULUM_WORK_CARDDISPATCHER_H
#define CURRICULUM_WORK_CARDDISPATCHER_H


#include "Pool_Proxy.h"

class CardDispatcher {
public:
    static CardDispatcher* GetInstance();
    CardDispatcher& AddInterceptCard(CardSpec spec);
    CardDispatcher& EXcludeInterceptCard(CardSpec spec);
    bool DrawCard(vector<pCard>& in);
    void build(const vector<pair<string, string>> &CardTypeMap,int num);
    bool IsBlack(pCard);
    CardDispatcher& SetDefaultAndBuild();
    void static SortCard(vector<pCard> &p);
    void static SortCard_F(vector<pCard> &p);
    size_t GetPoolSize();
    vector<string >GetPoolList();
private:
    vector<CardSpec > BlackList;
    vector<pCard > Intercept_array;
    vector<pCard > OutBoundBuffer;
    Pool_Proxy proxy;
    CardDispatcher();
};


#endif //CURRICULUM_WORK_CARDDISPATCHER_H
