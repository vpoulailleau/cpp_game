#include <vector>
#include "person.h"
#include "archer.h"
#include "farmer.h"
#include "giant.h"
#include "kamikaze.h"
#include "knight.h"
using namespace std;

static vector<Person *> teams[2] = {{}, {}};

static void team_display(int player_id)
{
    cout << "    - team: " << player_id + 1 << endl;
    for (auto person : teams[player_id])
    {

        cout << "        - " << person->get_name() << ": ";
        for (int i = 0; i < person->get_health() / 2; i++)
            cout << "#";
        cout << endl;
    }
}

static int team_random_person(int player_id)
{
    return rand() % teams[player_id].size();
}

static void create_team_member(int player_id, int &gold)
{
    int choice;
    cout << "    - remaining gold: " << gold << endl;
    cout << "    - possible purchases:" << endl;
    if (gold >= GIANT_COST)
        cout << "        - 1) giant: cost " << GIANT_COST << endl;
    if (gold >= KNIGHT_COST)
        cout << "        - 2) knight: cost " << KNIGHT_COST << endl;
    if (gold >= ARCHER_COST)
        cout << "        - 3) archer: cost " << ARCHER_COST << endl;
    if (gold >= FARMER_COST)
        cout << "        - 4) farmer: cost " << FARMER_COST << endl;
    if (gold >= KAMIKAZE_COST)
        cout << "        - 5) kamikaze: cost " << KAMIKAZE_COST << endl;

    cout << "        - what is your choice ? ";
    cin >> choice;
    if ((choice == 1) and (gold >= GIANT_COST))
    {
        teams[player_id].push_back(new Giant());
        gold -= GIANT_COST;
    }
    if ((choice == 2) and (gold >= KNIGHT_COST))
    {
        teams[player_id].push_back(new Knight());
        gold -= KNIGHT_COST;
    }
    if ((choice == 3) and (gold >= ARCHER_COST))
    {
        teams[player_id].push_back(new Archer());
        gold -= ARCHER_COST;
    }
    if ((choice == 4) and (gold >= FARMER_COST))
    {
        teams[player_id].push_back(new Farmer());
        gold -= FARMER_COST;
    }
    if ((choice == 5) and (gold >= KAMIKAZE_COST))
    {
        teams[player_id].push_back(new Kamikaze());
        gold -= KAMIKAZE_COST;
    }
    team_display(player_id);
}

static void create_team(int player_id, int gold)
{
    cout << "Team creation for player " << player_id + 1 << endl;
    while (gold > KAMIKAZE_COST) // TODO > min cost
    {
        create_team_member(player_id, gold);
    }
}

void game_init(void)
{
    int initial_gold = 500 + rand() % 1000;
    create_team(0, initial_gold);
    create_team(1, initial_gold);
}

void game_play(void)
{
    int fight_index = 1;
    string dustbin;
    while (teams[0].size() && teams[1].size())
    {
        cout << "Fight number " << fight_index++ << endl;
        team_display(0);
        team_display(1);
        int player0_index = team_random_person(0);
        int player1_index = team_random_person(1);
        Person *player0 = teams[0][player0_index];
        Person *player1 = teams[1][player1_index];
        cout << "    - fight:" << endl;
        player0->fight(*player1);
        if (player0->get_health() <= 0)
        {
            cout << "    - death of first player fighter" << endl;
            teams[0].erase(teams[0].begin() + player0_index);
        }
        if (player1->get_health() <= 0)
        {
            cout << "    - death of second player fighter" << endl;
            teams[1].erase(teams[1].begin() + player1_index);
        }
        cout << "Press enter to continue.  " << endl;
        getline(cin, dustbin);
    }
    if (teams[0].size())
        cout << "First player wins!!!" << endl;
    else if (teams[1].size())
        cout << "Second player wins!!!" << endl;
    else if (teams[0].size() == teams[1].size())
        cout << "Draw game" << endl;
}