#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
public:
    Person();

    enum Geschlecht{
        Unbekannt,
        Maennlich,
        Weiblich
    };

    std::string  vorname = "";
    std::string  name = "";
    int alter = 0;
    Geschlecht geschlecht;
};

#endif // PERSON_H
