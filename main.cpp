#include <iostream>
#include "play.h"
#include <vector>
using namespace std;

int main()
{
    cout << "Your choice: r/p/s and q to quit: ";

    int u = 0;
    int me = 0;
    int draw = 0;
    char yourChoice;
    cin >> yourChoice;
    vector<int> count(3, 0);
    while (yourChoice != 'q')
    {

        Play(yourChoice, u, me, draw, count);
        cout << "Your choice: r/p/s and q to quit: ";
        cin >> yourChoice;
    }
    Play(yourChoice, u, me, draw, count);
    cout << endl;
}
