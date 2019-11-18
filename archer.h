#ifndef __ARCHER_H__
#define __ARCHER_H__

#include "person.h"

#define ARCHER_COST (200)

class Archer : public Person
{
public:
    Archer() { _health = get_initial_health(); }

    virtual int get_cost(void) { return ARCHER_COST; }
    virtual int get_initial_health(void) { return 50; }
    virtual int get_force(void) { return 5; }
    virtual int get_skill(void) { return 3; }
    virtual string get_name(void) { return "Archer"; }
    virtual void shout(void) { cout << "PFFFFFF!"; }
};

#endif // __ARCHER_H__