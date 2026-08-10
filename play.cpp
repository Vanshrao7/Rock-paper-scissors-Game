#include "play.h"
#include "rand.h"
#include <string>
#include <iostream>
using namespace std;
void play(char yourChoice, int &u, int &me, int &draw)
{
    string myChoice;
    int myChoiceNum;
    myChoiceNum = Rand();
    if (myChoiceNum == 0)
    {
        myChoice = "Rock";
    }
    else if (myChoiceNum == 1)
    {
        myChoice = "Paper";
    }
    else
    {
        myChoice = "Scissors";
    }
    if ((myChoice == "Rock" && yourChoice == 'p') || (myChoice == "Paper" && yourChoice == 's') || (myChoice == "Scissors" && yourChoice == 'r'))
    {
        u = u + 1;
        cout << "I played " << myChoice << ", you won" << "             [you - " << u << " me - " << me << " draw - " << draw << "]" << endl;
    }
    else if ((myChoice == "Rock" && yourChoice == 's') || (myChoice == "Paper" && yourChoice == 'r') || (myChoice == "Scissors" && yourChoice == 'p'))
    {
        me = me + 1;
        cout << "I played " << myChoice << ", I won" << "             [you - " << u << " me - " << me << " draw - " << draw << "]" << endl;
    }
    else if ((myChoice == "Rock" && yourChoice == 'r') || (myChoice == "Paper" && yourChoice == 'p') || (myChoice == "Scissors" && yourChoice == 's'))
    {
        draw = draw + 1;
        cout << "I played " << myChoice << ", It's a draw" << "             [you - " << u << " me - " << me << " draw - " << draw << "]" << endl;
    }

    else if (yourChoice == 'q')
    {
        cout << "Final: you = " << u << " me = " << me << " draw = " << draw << endl;
    }

    else
    {
        cout << "something went wrong" << endl;
    }
}