#include "play.h"
#include "rand.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;
void Play(char yourChoice, int &u, int &me, int &draw, vector<int> &count)
{
    if (yourChoice == 'r')
    {
        count.at(0) = count.at(0) + 1;
    }
    else if (yourChoice == 'p')
    {
        count.at(1) = count.at(1) + 1;
    }
    else if (yourChoice == 's')
    {
        count.at(2) = count.at(2) + 1;
    }

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
        cout << "Final: you = " << u << " me = " << me << "draw = " << draw << endl;
        cout << "You played: rock " << count.at(0) << ", paper " << count.at(1) << ", scissors " << count.at(2) << endl;
    }

    else
    {
        cout << "something went wrong" << endl;
    }
}