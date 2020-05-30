#ifndef PEOPLE_H
#define PEOPLE_H

#include <string>
#include <vector>
#include "StringUtility.h"

using namespace std;

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

#endif // PEOPLE_H

