//
// Created by LPCTSTR_MSR on 2019/4/18.
//

#include "pch.h"
#ifndef CURRICULUM_WORK_CARD_H
#define CURRICULUM_WORK_CARD_H

class Card {
private:
    string Aattr;
    string Battr;
public:
    string GetGeneral();
    const string &getAattr() const;

    void setAattr(const string &Aattr);

    const string &getBattr() const;

    void setBattr(const string &Battr);

public:
};
using pCard= unique_ptr<Card,std::function<void(Card*)>>;
using CardSpec = pair<string,string>;
#endif //CURRICULUM_WORK_CARD_H
