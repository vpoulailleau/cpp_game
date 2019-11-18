#include <iostream>
#include <ctime>
using namespace std;

#include "archer.h"
#include "farmer.h"
#include "knight.h"
#include "giant.h"
#include "kamikaze.h"
#include "game.h"

int main(void)
{
    srand(time(nullptr));
    cout << "\n        === My best game... ===\n"
         << endl;
    game_init();
    game_play();
    return 0;
}