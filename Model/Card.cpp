//
// Created by LPCTSTR_MSR on 2019/4/18.
//

#include "Card.h"
const string &Card::getAattr() const {
    return Aattr;
}

void Card::setAattr(const string &Aattr) {
    Card::Aattr = Aattr;
}

const string &Card::getBattr() const {
    return Battr;
}

void Card::setBattr(const string &Battr) {
    Card::Battr = Battr;
}

string Card::GetGeneral() {
    return Aattr+" "+Battr+" ";
}
