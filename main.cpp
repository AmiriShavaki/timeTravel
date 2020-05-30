#include <iostream>
#include "Dreams.h"
#include "Mixtures.h"

using namespace std;

const int curT = 1245;

const vector < vector < char* > > getAllConsequences() { //List of consequences of all mixtures
    vector < vector < char* > > ans;
    for (int i = 0; i < 9; i++) {
        ans.push_back(mixtures[i] -> getConsequences());
    }
    return ans;
}

int main() {
    Dream dream;
    bool kimiaFlg = false; //A flag shows us Allahazrat wanted to use kimia or not
    bool firstOp = false; //A flag shows us first operation run before or not
    int dreamInd;
    char op;
    while (cin >> op) {
        switch (op) {
        case '1': {
            dream = Dream::chooseADream(dreamInd);
            firstOp = true;
            Person::handleInfections(dream.getCompanions());
        } break;
        case '2': {
            if (!firstOp) {
                string _; //Just to ignore useless input
                cin >> _;
                cout << "Philsoofodole:\nAlahazrata bande dar fahme darkhastetan ajezam.\n";
            } else {
                kimiaFlg = Mixture::kimiaPreferation();
            }
        } break;
        case '3': {
            Mixture::calculateCombination(dream, kimiaFlg);
        } break;
        case '4': {
            //Inner called calculateCombination function won't print anything
            Person::calculateAge(Mixture::calculateCombination(dream, kimiaFlg, false), dream.getCompanions(),
                                 dream.getYear() - curT);
        } break;
        case '5': {
            //Inner called calculateCombination function won't print anything
            Person::showChanges(dream.getCompanions(), getAllConsequences(), dreamInd,
                                Mixture::calculateCombination(dream, kimiaFlg, false));
        } break;
        case '6': {
            Person::cureProcess(dream.getCompanions());
        } break;
        default: {
            cout << "Philsoofodole:\nAlahazrata bande dar fahme darkhastetan ajezam.\n";
        } break;
        }
    }
}
