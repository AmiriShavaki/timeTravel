#include "Mixtures.h"
#include <iostream>
#include <cstdlib>

const bool Mixture::kimiaPreferation() {
    string command;
    cin >> command;
    if (command == "Maayel-Hastim") {
        cout << "Philsoofodole:\nAlahazrata dar in safar sene homayooni va hamrah(an) taghir nakhahad kard.\n";
        return true;
    } else if (command == "Maayel-Nistim") {
        cout << "Philsoofodole:\nFarmane homayooni etaat khahad shod.\n";
        return false;
    } else {
        cout << "Philsoofodole:\nAlahazrata bande dar fahme darkhastetan ajezam.\n";
    }
}

vector < char* > Mixture::getConsequences() const {
    return consequences;
}

const int Mixture::getCurT() const {
    return curT;
}

Mixture::Mixture(string color, string name, const vector < char* > givenConsequences): curT(1245), consequences(givenConsequences) {
    this -> color = color;
    this -> name = name;
}

Mokhamer::Mokhamer(string color, int timeDir, string name, const vector < char* > consequences): Mixture(color, name, consequences) {
    this -> timeDir = timeDir;
}

MokhamerJolosoo::MokhamerJolosoo(): Mokhamer("mesi", 1, "Mokhamer jolosoo", {"bozorg", NULL, NULL, NULL}) {}

int MokhamerJolosoo::calculate(const Dream dream, const bool kimiaFlg) const {
    return dream.getYear() - getCurT() > 0;
}

MokhamerAghabsoo::MokhamerAghabsoo(): Mokhamer("zomorodi", -1, "Mokhamer aghabsoo", {NULL, "bi moo", NULL, NULL}) {}

int MokhamerAghabsoo::calculate(const Dream dream, const bool kimiaFlg) const {
    return dream.getYear() - getCurT() < 0;
}

OsareKhasolkhas::OsareKhasolkhas(): Mixture("taje khoroosi", "Osare khasolkhas", {NULL, NULL, "taje khoroosi", NULL}) {}

int OsareKhasolkhas::calculate(const Dream dream, const bool kimiaFlg) const {
    return 1;
}

AfshoreKimia::AfshoreKimia(): Mixture("talaee", "Afshore kimia", {NULL, NULL, NULL, NULL}) {}

int AfshoreKimia::calculate(const Dream dream, const bool kimiaFlg) const {
    return kimiaFlg ? 1 : 0;
}

MarhamAlhaal::MarhamAlhaal(): Mixture("doodi", "Marham alhaal", {NULL, NULL, NULL, "increase"}) {}

int MarhamAlhaal::calculate(const Dream dream, const bool kimiaFlg) const {
    return 0;
}

jooshande::jooshande(string color, int t, string name, const vector < char* > consequences): Mixture(color, name, consequences) {
    this -> t = t;
}

jooshande1::jooshande1(): jooshande("aaji", 1, "Jooshande 1 sale", {NULL, NULL, NULL, NULL}) {}

int jooshande1::calculate(const Dream dream, const bool kimiaFlg) const {
    return abs(dream.getYear() - getCurT()) % 5;
}

jooshande5::jooshande5(): jooshande("kahrobaee", 5, "Jooshande 5 sale", {NULL, NULL, NULL, NULL}) {}

int jooshande5::calculate(const Dream dream, const bool kimiaFlg) const {
    return (abs(dream.getYear() - getCurT()) % 50) / 5;
}

jooshande50::jooshande50(): jooshande("lajevardi", 50, "Jooshande 50 sale", {NULL, NULL, NULL, NULL}) {}

int jooshande50::calculate(const Dream dream, const bool kimiaFlg) const {
    return (abs(dream.getYear() - getCurT()) % 100) / 50;
}

jooshande100::jooshande100(): jooshande("onabi", 100, "Jooshande 100 sale", {NULL, NULL, NULL, NULL}) {}

int jooshande100::calculate(const Dream dream, const bool kimiaFlg) const {
    return abs(dream.getYear() - getCurT()) / 100;
}

const string Mixture::getName() const {
    return name;
}

const vector < int > Mixture::calculateCombination(const Dream dream, const bool kimiaFlg, const bool print) {
    if (print) {
        cout << "Philsoofodole:\n";
    }
    vector < int > ans;
    for (int i = 0; i < 9; i++) {
        if (i && print) {
            cout << " + ";
        }
        ans.push_back(mixtures[i] -> calculate(dream, kimiaFlg));
        if (print) {
            cout << ans[i] << " peymane \"" << mixtures[i] -> getName() << "\"";
        }
    }
    if (print) {
        cout << endl;
    }
    return ans;
}
