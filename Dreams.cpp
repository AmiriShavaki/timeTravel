#include "Dreams.h"
#include <iostream>

using namespace std;

const int Dream::getYear() const {
    return year;
}

const string Dream::getPlaceName() const {
    return placeName;
}

const vector < Person > Dream::getCompanions() const {
    return companions;
}

const Dream Dream::chooseADream(int& dreamInd) {
    string ind;
    cin >> ind; //1-based string
    if (StringUtility::isAllDigit(ind) && StringUtility::convertStringToNumber(ind) <= 6) {
        dreamInd = StringUtility::convertStringToNumber(ind) - 1;
        Dream ans = dreams[dreamInd];
        cout << "Philsoofodole:\nAlahazrata dar safar be saal " << ans.getYear() << " - " << ans.getPlaceName() <<
        " oghate khoshi barayetan arezoo daram.\n";
        const vector < Person > comps = ans.getCompanions();
        for (int i = 0; i < comps.size(); i++) {
            if (i) {
                cout << ',';
            }
            cout << '\"' << comps[i].getName() << '\"';
        }
        cout << " shoma ra hamrahi khahad(nd) kard.\n";
        return ans; //0-based integer
    } else {
        cout << "Philsoofodole:\nAlahazrata bande dar fahme darkhastetan ajezam.\n";
        return Dream();
    }
}

Dream::Dream() {}

Dream::Dream(char* placeName, int year, vector < Person > companions) {
    this -> placeName = placeName;
    this -> year = year;
    this -> companions = companions;
}
