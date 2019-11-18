#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "person.h"

#define KNIGHT_COST (300)

class Knight : public Person
{
public:
    Knight() { _health = get_initial_health(); }

    virtual int get_cost(void) { return KNIGHT_COST; }
    virtual int get_initial_health(void) { return 60; }
    virtual int get_force(void) { return 3; }
    virtual int get_skill(void) { return 4; }
    virtual string get_name(void) { return "Knight"; }
    virtual void shout(void) { cout << "SWIIIIP!"; }
};

#endif // __KNIGHT_H__