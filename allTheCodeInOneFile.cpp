#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class StringUtility {
    public:

    //Change type of given string to integer
    inline static int convertStringToNumber(string s);

    //Determine all characters of given string are digit or not
    inline static bool isAllDigit(string s);

    //Determine all characters of given string are letter/space or not
    inline static bool isAllLetters(string s);

    inline static char makeLower(char c);

    inline static bool subStr(const string s1, const string s2);//Is string s2 one of subStrings of string s1?
};

inline bool StringUtility::subStr(const string s1, const string s2) {
    for (int i = 0; i < s1.size() - s2.size() + 1; i++) {
        bool res = true;
        for (int j = 0; j < s2.size(); j++) {
            if (s1[i + j] != s2[j]) {
                res = false;
            }
        }
        if (res) {
            return true; //Found
        }
    }
    return false; //Not found
}

inline char StringUtility::makeLower(char c) {
    return (c < 'Z' && c > 'A') ? c - 'A' + 'a' : c;
}

inline int StringUtility::convertStringToNumber(string s) {
    int n = s.size(), ans = 0;
    for (int i = n - 1, j = 1; i >= 0; i--, j *= 10) {
        ans += (s[i] - '0') * j;
    }
    return ans;
}

inline bool StringUtility::isAllDigit(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] < '0' || s[i] > '9') {
            return false;
        }
    }
    return s.size();
}

inline bool StringUtility::isAllLetters(string s) {
    bool ans = true;
    for (int i = 0; i < s.size(); i++) {
        ans &= s[i] <= 'Z' && s[i] >= 'A' || s[i] <= 'z' && s[i] >= 'a' || s[i] == ' ';
    }
    return ans;
}

class Person {
    public:
    Person(char* name, char* skinColor, int height, int age, char* noseSize = "motevaset", char* hairCondition = "ba moo");
    const string getName() const;
    static void calculateAge(const vector < int > combination, const vector < Person > companions, const int timeDiff);
    const int getAge() const;
    static void showChanges(vector < Person > companions, const vector < vector < char* > >, int dreamInd, const vector < int >);
    const string getSkinColor() const;
    const string getNoseSize() const;
    const string getHairCondition() const;
    const int getHeight() const;
    void setAge(int newAge);
    void infect();
    void cure();
    static void handleInfections(const vector < Person > companions);
    static void cureProcess(const vector < Person >);

    private:
    string name;
    string skinColor;
    string noseSize;
    string hairCondition;
    int height;
    int age;
    bool infected;
};

static Person people[7] = {
    Person("Naseredinshah", "sabze", 170, 35),
    Person("Adibosaltane", "sefid", 165, 48),
    Person("Philsoofodole", "sorkh", 168, 74),
    Person("Etemadodole", "sabze", 180, 56),
    Person("Jeyran", "sefid", 172, 21),
    Person("Malijack", "siah", 150, 19),
    Person("Ghodratodole", "sefid", 190, 43)
};

const string Person::getName() const {
    return name;
}

const bool operator==(const Person l, const Person r) {
    return l.getName() == r.getName();
}

void Person::handleInfections(const vector < Person > companions) {
    people[0].infect();
    for (int i = 1; i < 7; i++) {
        for (int j = 0; j < companions.size(); j++) {
            if (companions[j] == people[i]) {
                people[i].infect();
            }
        }
    }
}

const bool operator!=(Person l, Person r) {
    return !(l == r);
}

void Person::infect() {
    infected = true;
}

void Person::cure() {
    infected = false;
}

void affectConsequences(const vector < char* > consequences, string& noseSize, string& hairCondition, string& skinColor, int& height) {
    if (consequences[0] != NULL) { //nose
        noseSize = consequences[0];
    }
    if (consequences[1] != NULL) { //hair
        hairCondition = consequences[1];
    }
    if (consequences[2] != NULL) { //skin
        skinColor = consequences[2];
    }
    if (consequences[3] != NULL) { //height
        height += 5;
    }
}

void Person::showChanges(vector < Person > companions, const vector < vector < char* > > consequencesList, int dreamInd,
                         const vector < int > calculated) { //Result of calculateCombination
    string ind;
    cin >> ind; //1-based string
    if (StringUtility::isAllDigit(ind) && StringUtility::convertStringToNumber(ind) <= 7) {
        Person person = people[StringUtility::convertStringToNumber(ind) - 1];
        bool found = person == people[0]; //In the not found case this will remain false
        for (int i = 0; i < companions.size(); i++) {
            if (companions[i] == person) {
                found = true;
            }
        }
        if (!found) {
            cout << "Philsoofodole:\n" << '\"' << person.getName();
            cout << "\" dar in safar saadate hamrahi padshah ra nadashte ast.\n";
        } else {
            string name = person.getName();
            string skinColor = person.getSkinColor();
            string noseSize = person.getNoseSize();
            string hairCondition = person.getHairCondition();
            int height = person.getHeight();
            int age = person.getAge();
            if (person.infected) {
                for (int i = 0; i < calculated.size(); i++) {
                    if (calculated[i] || i == 8) { //i-th mixture is used or it is Marham alhaal
                        affectConsequences(consequencesList[i], noseSize, hairCondition, skinColor, height);
                    }
                }
            }
            cout << name << ":\nRange poost::" << skinColor << " - Size bini::" << noseSize;
            cout << " - Moo::" << hairCondition << " - Ghad::" << height << " cm - Sen::";
            cout << age << endl;
        }
    } else {
        cout << "Philsoofodole:\nAlahazrata bande dar fahme darkhastetan ajezam.\n";
    }
}

void Person::cureProcess(const vector < Person > companions) {
    string command;
    cin >> command;
    if (command == "Maayel-Hastim") {
        string command2;
        cin >> command2;
        if (StringUtility::isAllDigit(command2)) {
            int n = StringUtility::convertStringToNumber(command2);
            for (int i = 0; i < n; i++) {
                string command3;
                cin >> command3;
                if (StringUtility::isAllDigit(command3)) {
                    int personInd = StringUtility::convertStringToNumber(command3) - 1;
                    if (personInd < 7) {

                        //Search for the person in the companions
                        int foundInd = personInd ? -1 : 0; //In case of not found will remain -1
                        for (int j = 0; j < companions.size(); j++) {
                            if (companions[j] == people[personInd]) {
                                foundInd = j;
                            }
                        }

                        if (foundInd == -1) { //Not found
                            cout << "Philsoofodole:\nAlahazrata bande dar fahme darkhastetan ajezam.\n"; break;
                        } else {
                            people[personInd].cure();
                            string name = people[personInd].getName();
                            string skinColor = people[personInd].getSkinColor();
                            string noseSize = people[personInd].getNoseSize();
                            string hairCondition = people[personInd].getHairCondition();
                            int height = people[personInd].getHeight();
                            int age = people[personInd].getAge();
                            cout << name << ":\nRange poost::" << skinColor << " - Size bini::" << noseSize;
                            cout << " - Moo::" << hairCondition << " - Ghad::" << height << " cm - Sen::";
                            cout << age << endl;
                        }

                    } else { //Invalid number
                        cout << "Philsoofodole:\nAlahazrata bande dar fahme darkhastetan ajezam.\n"; break;
                    }
                } else { //Not a number input
                    cout << "Philsoofodole:\nAlahazrata bande dar fahme darkhastetan ajezam.\n"; break;
                }
            }
        } else { //Not a number input
            cout << "Philsoofodole:\nAlahazrata bande dar fahme darkhastetan ajezam.\n";
        }
    } else if (command == "Maayel-Nistim") {
        cout << "Philsoofodole:\nFarmane homayooni etaat khahad shod.\n";
    } else {
        cout << "Philsoofodole:\nAlahazrata bande dar fahme darkhastetan ajezam.\n";
    }
}

const int Person::getHeight() const {
    return height;
}

const string Person::getHairCondition() const {
    return hairCondition;
}

const string Person::getNoseSize() const {
    return noseSize;
}

const string Person::getSkinColor() const {
    return skinColor;
}

void Person::calculateAge(const vector < int > combination, const vector < Person > companions, const int timeDiff) {
    string ind;
    cin >> ind; //1-based string
    if (StringUtility::isAllDigit(ind) && StringUtility::convertStringToNumber(ind) <= 7) {
        Person person = people[StringUtility::convertStringToNumber(ind) - 1];
        bool found = person == people[0]; //In the not found case this will remain false
        for (int i = 0; i < companions.size(); i++) {
            if (companions[i] == person) {
                found = true;
            }
        }
        if (!found) {
            cout << "Philsoofodole:\nAlahazrata bande dar fahme darkhastetan ajezam.\n";
        } else {
            cout << "Philsoofodole:\nSene \"" << person.getName() << "\" dar in safar ";
            bool kimiaFlg = combination[7];
            if (kimiaFlg) {
                cout << person.getAge();
            } else {
                cout << max(18, person.getAge() + timeDiff);
                //person.setAge(max(18, person.getAge() + timeDiff));
            }
            cout << " mibashad.\n";
        }
    } else {
        cout << "Philsoofodole:\nAlahazrata bande dar fahme darkhastetan ajezam.\n";
    }
}

void Person::setAge(int newAge) {
    for (int i = 0; i < 7; i++) {
        if (*this == people[i]) {
            people[i].age = newAge;
        }
    }
}

const int Person::getAge() const {
    return age;
}

Person::Person(char* name, char* skinColor, int height, int age, char* noseSize /*= "motevaset"*/, char* hairCondition /*= "ba moo"*/) {
    this -> name = name;
    this -> skinColor = skinColor;
    this -> height = height;
    this -> age = age;
    this -> noseSize = noseSize;
    this -> hairCondition = hairCondition;
    infected = false;
}

const int DREAMSLEN = 6;

class Dream {
    public:
    static const Dream chooseADream(int& dreamInd);
    Dream(char* placeName, int year, vector < Person > companions);
    const int getYear() const;
    Dream();
    const string getPlaceName() const;
    const vector < Person > getCompanions() const;

    private:
    string placeName;
    int year;
    vector < Person > companions;
};

static const Dream dreams[6] = {
    Dream("cinema chandbodi", 1396, {people[3]}), //Etemadodole
    Dream("keshti titanic", 1290, {people[4], people[5]}), //Jeyran, MalijackM
    Dream("nejat \"Babrikhan\"", 1223, {people[6]}), //Ghodratodole
    Dream("didar ba picasso", 1279, {people[1]}), //Adibosaltane
    Dream("daneshgah Harward", 1370, {people[6]}), //Ghodratodole
    Dream("restooran Sobrino de Botin", 1105, {people[3], people[4]}) //Etemadodole, Jeyran
};

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

class Mixture {
    public:
    static const bool kimiaPreferation();
    static const vector < int > calculateCombination(const Dream dream, const bool kimiaFlg, const bool print = true);
    Mixture(string color, string name, const vector < char* > consequences);
    virtual int calculate(const Dream dream, const bool kimiaFlg) const = 0;
    const string getName() const;
    const int getCurT() const;
    vector < char* > getConsequences() const;

    private:
    string color;
    string name;
    const int curT;
    const vector < char* > consequences;
};

class jooshande: public Mixture {
    public:
    jooshande(string color, int t, string name, const vector < char* > consequences);
    virtual int calculate(const Dream dream, const bool kimiaFlg) const = 0;

    private:
    int t;
};

class jooshande1: public jooshande {
    public:
    jooshande1();
    virtual int calculate(const Dream dream, const bool kimiaFlg) const;
};

class jooshande5: public jooshande {
    public:
    jooshande5();
    virtual int calculate(const Dream dream, const bool kimiaFlg) const;
};

class jooshande50: public jooshande {
    public:
    jooshande50();
    virtual int calculate(const Dream dream, const bool kimiaFlg) const;
};

class jooshande100: public jooshande {
    public:
    jooshande100();
    virtual int calculate(const Dream dream, const bool kimiaFlg) const;
};

class Mokhamer: public Mixture {
    public:
    Mokhamer(string color, int timeDir, string name, const vector < char* > consequences);
    virtual int calculate(const Dream dream, const bool kimiaFlg) const = 0;

    private:
    int timeDir; //1 shows us they wanna travel to future otherwise -1 shows us they wanna travel to past
};

class MokhamerJolosoo: public Mokhamer {
    public:
    MokhamerJolosoo();
    virtual int calculate(const Dream dream, const bool kimiaFlg) const;
};

class MokhamerAghabsoo: public Mokhamer {
    public:
    MokhamerAghabsoo();
    virtual int calculate(const Dream dream, const bool kimiaFlg) const;
};

class OsareKhasolkhas: public Mixture {
    public:
    OsareKhasolkhas();
    virtual int calculate(const Dream dream, const bool kimiaFlg) const;
};

class AfshoreKimia: public Mixture {
    public:
    AfshoreKimia();
    virtual int calculate(const Dream dream, const bool kimiaFlg) const;
};

class MarhamAlhaal: public Mixture {
    public:
    MarhamAlhaal();
    virtual int calculate(const Dream dream, const bool kimiaFlg) const;
};

static const Mixture* mixtures[9] = {new jooshande1, new jooshande5, new jooshande50, new jooshande100,
new MokhamerJolosoo, new MokhamerAghabsoo, new OsareKhasolkhas, new AfshoreKimia, new MarhamAlhaal};

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
        }
        }
    }
}