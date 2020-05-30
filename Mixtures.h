#ifndef MIXTURES_H
#define MIXTURES_H

#include "Dreams.h"

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

#endif // MIXTURES_H
