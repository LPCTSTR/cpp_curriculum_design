
#include "Model/pch.h"
#include<windows.h>
#include "Controller/MainController.h"
using namespace std;


int main() {
    vector<pCard> Player;
    CardDispatcher *inst = CardDispatcher::GetInstance();
//    inst->build(
//            {{"A",  "Spade"},
//             {"2",  "Diamond"},
//             {"10", "Heart"}},2);
    inst->SetDefaultAndBuild();
//    筛选器增加
//            .AddInterceptCard({"A", "Spade"})
//            .AddInterceptCard({"Q", "Club"})
//            .AddInterceptCard({"3", "Spade"})
//            .EXcludeInterceptCard({"A", "Spade"});
    return MainController::GetInstance()->run();
}

