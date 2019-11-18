#ifndef __KAMIZKAZE_H__
#define __KAMIZKAZE_H__

#include "person.h"

#define KAMIKAZE_COST (50)

class Kamikaze : public Person
{
public:
    Kamikaze() { _health = get_initial_health(); }

    virtual int get_cost(void) { return KAMIKAZE_COST; }
    virtual int get_initial_health(void) { return 10; }
    virtual int get_force(void) { return 4; }
    virtual int get_skill(void) { return 6; }
    virtual string get_name(void) { return "Kamikaze"; }
    virtual void shout(void) { cout << "YAAAHHH!"; }
};

#endif // __KAMIZKAZE_H_