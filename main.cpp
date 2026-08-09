#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void play(char yourChoice, int &u, int &me, int &draw)
{
    string myChoice;
    int myChoiceNum;
    myChoiceNum = rand() % 3;
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

int main()
{
    cout << "Your choice: r/p/s and q to quit: ";

    int u = 0;
    int me = 0;
    int draw = 0;
    char yourChoice;
    cin >> yourChoice;
    while (yourChoice != 'q')
    {
        play(yourChoice, u, me, draw);
        cout << "Your choice: r/p/s and q to quit: ";
        cin >> yourChoice;
    }
    play(yourChoice, u, me, draw);
    cout << endl;
}
