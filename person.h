#ifndef __PERSON_H__
#define __PERSON_H__

#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    Person() { _health = get_initial_health(); }
    int get_health(void) { return _health; }
    void loose_health(int loss) { _health -= loss; }
    virtual void fight(Person &other);

    virtual int get_cost(void) { return 0; }
    virtual int get_initial_health(void) { return 0; }
    virtual int get_force(void) { return 0; }
    virtual int get_skill(void) { return 0; }
    virtual string get_name(void) { return "Person"; }
    virtual void shout(void) { cout << "AAAAHHHH!"; }

protected:
    int _health;
    void _fight_once(Person &other);
};

#endif // __PERSON_H__