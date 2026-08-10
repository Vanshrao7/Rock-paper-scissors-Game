#include <iostream>
#include "play.h"
using namespace std;

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
