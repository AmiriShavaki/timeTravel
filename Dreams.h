#ifndef DREAMS_H
#define DREAMS_H

#include "People.h"
#include <string>
#include <vector>

using namespace std;

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
    Dream("keshti titanic", 1290, {people[4], people[5]}), //Jeyran, Malijack
    Dream("nejat \"Babrikhan\"", 1223, {people[6]}), //Ghodratodole
    Dream("didar ba picasso", 1279, {people[1]}), //Adibosaltane
    Dream("daneshgah Harward", 1370, {people[6]}), //Ghodratodole
    Dream("restooran Sobrino de Botin", 1105, {people[3], people[4]}) //Etemadodole, Jeyran
};

#endif // DREAMS_H
