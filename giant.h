#ifndef __GIANT_H__
#define __GIANT_H__

#include "person.h"

#define GIANT_COST (500)

class Giant : public Person
{
public:
    Giant() { _health = get_initial_health(); }

    virtual int get_cost(void) { return GIANT_COST; }
    virtual int get_initial_health(void) { return 20; }
    virtual int get_force(void) { return 4; }
    virtual int get_skill(void) { return 5; }
    virtual string get_name(void) { return "Giant"; }
    virtual void shout(void) { cout << "BOING!"; }
};

#endif // __GIANT_H__