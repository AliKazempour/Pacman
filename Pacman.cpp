#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include <time.h>
#include "Map.h"

using namespace std;
int main()
{
    colorfulPrint("pacmanLogo.txt");
    sleep(2);
    system("CLS");
    loadingBar();
    bool play = true;
    while (play == true)
    {
        system("CLS");
        replay();
        cout << "Do you want to play again? :)" << endl;
        cin >> play;
    }
}