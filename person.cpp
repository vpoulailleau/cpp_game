#include "person.h"

void Person::fight(Person &other)
{
    _fight_once(other);
    other._fight_once(*this);
}

void Person::_fight_once(Person &other)
{
    cout << "        - " << get_name() << " launching the attack: ";
    shout();
    cout << endl;
    int dice = rand() % 6 + 1;
    cout << "            - dice: " << dice << endl;
    if (dice <= get_skill())
    {
        cout << "            - ATTACK" << endl;
        other.loose_health(get_force());
    }
    else
    {
        cout << "            - missed attack" << endl;
    }
}