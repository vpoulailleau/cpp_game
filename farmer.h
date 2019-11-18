#ifndef __FARMER_H__
#define __FARMER_H__

#include "person.h"

#define FARMER_COST (50)

class Farmer : public Person
{
public:
    Farmer() { _health = get_initial_health(); }

    virtual int get_cost(void) { return FARMER_COST; }
    virtual int get_initial_health(void) { return 20; }
    virtual int get_force(void) { return 1; }
    virtual int get_skill(void) { return 1; }
    virtual string get_name(void) { return "Farmer"; }
    virtual void shout(void) { cout << "GRRRRRR!"; }
};

#endif // __FARMER_H__