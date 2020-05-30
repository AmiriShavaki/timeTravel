#include "People.h"
#include <iostream>
#include <algorithm>

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
                            cout << "Philsoofodole:\nAlahazrata bande dar fahme darkhastetan ajezam.\n";
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
                        cout << "Philsoofodole:\nAlahazrata bande dar fahme darkhastetan ajezam.\n";
                    }
                } else { //Not a number input
                    cout << "Philsoofodole:\nAlahazrata bande dar fahme darkhastetan ajezam.\n";
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
