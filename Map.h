#include <iostream>
#include <unistd.h>
#include <windows.h>
#include <conio.h>
#include "Ghost.h"
#include <fstream>
#include <time.h>

using namespace std;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
void mapStorage(string arr[20][20])
{
    int x, y;
    for (x = 0; x < 20; x++)
    {
        for (y = 0; y < 20; y++)
        {
            cout << arr[x][y];
        }
    }
}
void mapDesign(string arr[20][20])
{
    srand(time(0));
    int x, y;
    for (x = 0; x < 20; x++)
    {
        for (y = 0; y < 20; y++)
        {
            if (x == 0 || x == 19)
            {
                arr[x][y] = '#';
            }
            else if (y == 0 || y == 19)
            {
                arr[x][y] = '#';
            }
            else if ((x == 2 || x == 3 || x == 4 || x == 5) && y > 1 && y < 6)
            {
                arr[x][y] = '#';
            }
            else if ((x == 7 || x == 8) && y > 1 && y < 10)
            {
                arr[x][y] = '#';
            }
            else if (x == 10 && y > 1 && y < 10)
            {
                arr[x][y] = '#';
            }
            else if ((x == 16 || x == 17) && y > 1 && y < 10)
            {
                arr[x][y] = '#';
            }
            else if ((x == 8 || x == 9 || x == 10 || x == 11) && y > 11 && y < 17)
            {
                arr[x][y] = '#';
            }
            else if ((x == 17 || x == 16 || x == 15 || x == 14) && y > 10 && y < 14)
            {
                arr[x][y] = '#';
            }
            else if ((x == 2 || x == 4 || x == 5 || x == 6) && y > 13 && y < 18)
            {
                arr[x][y] = '#';
            }
            else if (y == 2 && (x == 12 || x == 13))
            {
                arr[x][y] = '#';
            }
            else if ((x == 2 || x == 3 || x == 4 || x == 5) && y > 6 && y < 13)
            {
                arr[x][y] = '#';
            }
            else if ((x == 14 || x == 12) && y > 3 && y < 10)
            {
                arr[x][y] = '#';
            }
            else if ((x == 15 || x == 17) && y > 14 && y < 18)
            {
                arr[x][y] = '#';
            }
            else
            {
                arr[x][y] = ".";
            }
        }
    }
    for (x = 0; x < 20; x++)
    {
        for (y = 0; y < 20; y++)
        {
            if (arr[x][y] == "#")
            {
                int p = rand() % 2;
                if (p == 1)
                {
                    arr[x][y] = ".";
                }
            }
        }
    }
    for (x = 0; x < 20; x++)
    {
        for (y = 0; y < 20; y++)
        {
            if ((x == 19 || x == 0) || (y == 0 || y == 19))
            {
                arr[x][y] = "#";
            }
        }
    }
    arr[0][9] = arr[19][9] = " ";
    for (x = 0; x < 20; x++)
    {
        for (y = 0; y < 20; y++)
        {
            if (arr[x][y] == "." || arr[x][y] == "0")
            {
                if (arr[x][y - 1] == "#" && arr[x][y + 1] == "#" && arr[x + 1][y] == "#" && arr[x - 1][y] == "#")
                {
                    arr[x][y] = "#";
                }
            }
        }
    }
}
void colorGame(string arr[20][20], int xGhosts[4], int yGhosts[4], int xPacman, int yPacman)
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (i == xPacman && j == yPacman)
            {
                cout << "\033[1;43m^^\033[0m";
            }
            else if (i == xGhosts[0] && j == yGhosts[0])
            {
                cout << "\033[1;41m**\033[0m";
            }
            else if (i == xGhosts[1] && j == yGhosts[1])
            {
                cout << "\033[1;42m**\033[0m";
            }
            else if (i == xGhosts[2] && j == yGhosts[2])
            {
                cout << "\033[1;44m**\033[0m";
            }
            else if (i == xGhosts[3] && j == yGhosts[3])
            {
                cout << "\033[1;45m**\033[0m";
            }
            else
            {
                cout << (arr[i][j] == "#"
                             ? "\033[1;47m  \033[0m"
                         : arr[i][j] == "0"
                             ? "\033[1;40m  \033[0m"
                         : arr[i][j] == "."
                             ? "\033[1;46m..\033[0m"
                             : "\033[1;46m  \033[0m");
            }
        }
        cout << endl;
    }
}

void movePacman(int *xPacman, int *yPacman, char move, string arr[20][20], int Score[20][20])
{
    if (move == 's')
    {
        (*xPacman)++;
        if (*xPacman > 0)
        {
            arr[*xPacman - 1][*yPacman] = " ";
            Score[*xPacman - 1][*yPacman] = 0;
        }
    }
    if (move == 'w')
    {
        (*xPacman)--;
        if (*xPacman > 0)
        {
            arr[*xPacman + 1][*yPacman] = " ";
            Score[*xPacman + 1][*yPacman] = 0;
        }
        else if (*xPacman == 0 && *yPacman == 9)
        {
            arr[*xPacman + 1][*yPacman] = " ";
        }
    }
    if (move == 'a')
    {
        (*yPacman)--;
        if (*yPacman > 0)
        {
            arr[*xPacman][*yPacman + 1] = " ";
            Score[*xPacman][*yPacman + 1] = 0;
        }
    }
    if (move == 'd')
    {
        (*yPacman)++;
        if (*yPacman > 0)
        {
            arr[*xPacman][*yPacman - 1] = " ";
            Score[*xPacman][*yPacman - 1] = 0;
        }
    }
}

void SetCursorPosition(int x, int y)
{
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos{x, y};
    SetConsoleCursorPosition(output, pos);
}
void loadingBar()
{
    system("COLOR 0e");
    system("CLS");
    // asci to print special chracter
    SetConsoleCP(437);
    SetConsoleOutputCP(437);
    int bar1 = 177, bar2 = 219;
    cout << "\n\n\n\t\t\t\tLoading...";
    cout << "\n\n\n\t\t\t\t";

    for (int i = 0; i < 25; i++)
    {
        cout << (char)bar1;
    }
    cout << "\r";
    cout << "\t\t\t\t";
    for (int i = 0; i < 25; i++)
    {
        cout << (char)bar2;
        Sleep(150);
    }
    cout << "\n\t\t\t\t" << (char)1 << "!";
    system("Pause");
}
void stop(char move)
{
    while (move == 'v')
    {
        move = getch();
        cout << "Use w,a,s,d to continue the game . " << endl;
    }
}
void colorfulPrint(string file)
{
    string x;
    ifstream read(file);
    for (; getline(read, x);)
    {
        for (int i = 0; i < x.length(); i++)
        {
            switch (x[i])
            {
            case '0':
                SetConsoleTextAttribute(h, 0x00);
                break;
            case '6':
                SetConsoleTextAttribute(h, 0x66);
                break;
            case 'F':
                SetConsoleTextAttribute(h, 0xFF);
                break;
            case '1':
                SetConsoleTextAttribute(h, 17);
                break;
            }
            cout << "  ";
        }
        cout << endl;
    }
    read.close();
}
void replay()
{
    SetCursorPosition(0, 0);
    string arr[20][20];
    int Score[20][20];
    int x, y;
    int xPacman = 12, yPacman = 10;
    int xGhosts[4] = {1, 1, 18, 18};
    int yGhosts[4] = {1, 18, 1, 18};
    char move;
    int score = 10;
    int food = 0;
    int life = 3;
    long int start = time(0);
    char level;
    cout << "Please select the game level" << endl;
    cout << "Easy-->E" << endl;
    cout << "Normal-->N" << endl;
    cout << "Hard-->H" << endl;
    cin >> level;
    system("cls");

    // Storage of the Map
    mapStorage(arr);
    // Designing the map
    mapDesign(arr);
    arr[6][3] = "0";
    arr[10][15] = "0";
    arr[15][4] = "0";
    for (x = 0; x < 20; x++)
    {
        for (y = 0; y < 20; y++)
        {
            Score[x][y] = 10;
            Score[6][3] = 50;
            Score[10][15] = 50;
            Score[15][4] = 50;
        }
    }
    for (x = 0; x < 20; x++)
    {
        for (y = 0; y < 20; y++)
        {
            if (arr[x][y] == ".")
            {
                food++;
            }
        }
    }
    // Printing the map
    arr[xPacman][yPacman] = "C";
    for (int i = 0; i < 4; i++)
    {
        arr[xGhosts[i]][yGhosts[i]] = "@";
    }
    cout << "\tLife: " << life;
    cout << "\t\t\tScore: " << score;
    cout << endl;
    colorGame(arr, xGhosts, yGhosts, xPacman, yPacman);
    while (true)
    {
        stop(move);
        for (int i = 0; i < 4; i++)
        {
            if (Score[xGhosts[i]][yGhosts[i]] == 10)
            {
                arr[xGhosts[i]][yGhosts[i]] = ".";
            }
            else if (Score[xGhosts[i]][yGhosts[i]] == 0)
            {
                arr[xGhosts[i]][yGhosts[i]] = " ";
            }
            else if (Score[xGhosts[i]][yGhosts[i]] == 50)
            {
                arr[xGhosts[i]][yGhosts[i]] = "0";
            }
        }
        usleep(100000 * 6);
        if (kbhit())
        {
            move = getch();
        }
        SetCursorPosition(0, 0);
        movePacman(&xPacman, &yPacman, move, arr, Score);
        Score[xPacman][yPacman] = 0;

        if (arr[xPacman][yPacman] == "#")
        {
            SetCursorPosition(0, 0);
            if (move == 's')
            {
                xPacman--;
                if (xPacman > 0)
                {
                    arr[xPacman - 1][yPacman] = " ";
                }
            }
            if (move == 'w')
            {
                xPacman++;
                if (xPacman > 0)
                {
                    arr[xPacman + 1][yPacman] = " ";
                }
            }
            if (move == 'a')
            {
                yPacman++;
                if (yPacman > 0)
                {
                    arr[xPacman][yPacman + 1] = " ";
                }
            }
            if (move == 'd')
            {
                yPacman--;
                if (yPacman > 0)
                {
                    arr[xPacman][yPacman - 1] = " ";
                }
            }
        }
        if (level == 'E')
        {
            for (int i = 0; i < 4; i++)
            {
                if (i == 0)
                {
                    if (time(0) - start >= 0)
                    {
                        foolish(&xGhosts[i], &yGhosts[i], arr);
                    }
                }
                else if (i == 1)
                {
                    if (time(0) - start >= 5)
                    {
                        foolish(&xGhosts[i], &yGhosts[i], arr);
                    }
                }
                else if (i == 2)
                {
                    if (time(0) - start >= 10)
                    {
                        foolish(&xGhosts[i], &yGhosts[i], arr);
                    }
                }
                else if (i == 3)
                {
                    if (time(0) - start >= 15)
                    {
                        foolish(&xGhosts[i], &yGhosts[i], arr);
                    }
                }
            }
        }
        else if (level == 'N')
        {
            for (int i = 0; i < 2; i++)
            {

                if (i == 0)
                {
                    if (time(0) - start >= 0)
                    {
                        smart(&xPacman, &yPacman, &xGhosts[i], &yGhosts[i], arr, i, xGhosts, yGhosts);
                    }
                }
                else if (i == 1)
                {
                    if (time(0) - start >= 3)
                    {
                        smart(&xPacman, &yPacman, &xGhosts[i], &yGhosts[i], arr, i, xGhosts, yGhosts);

                    }
                }
            }

            for (int i = 2; i < 4; i++)
            {
                if (i == 2)
                {
                    if (time(0) - start >= 6)
                    {
                        foolish(&xGhosts[i], &yGhosts[i], arr);
                    }
                }
                else if (i == 3)
                {
                    if (time(0) - start >= 9)
                    {
                        foolish(&xGhosts[i], &yGhosts[i], arr);
                    }
                }
            }
        }
        else if (level == 'H')
        {
            for (int i = 0; i < 4; i++)
            {
                if (i == 0)
                {
                    if (time(0) - start >= 0)
                    {
                        smart(&xPacman, &yPacman, &xGhosts[i], &yGhosts[i], arr, i, xGhosts, yGhosts);
                    }
                }
                else if (i == 1)
                {
                    if (time(0) - start >= 2)
                    {
                        smart(&xPacman, &yPacman, &xGhosts[i], &yGhosts[i], arr, i, xGhosts, yGhosts);
                    }
                }
                else if (i == 2)
                {
                    if (time(0) - start >= 4)
                    {
                        smart(&xPacman, &yPacman, &xGhosts[i], &yGhosts[i], arr, i, xGhosts, yGhosts);
                    }
                }
                else if (i == 3)
                {
                    if (time(0) - start >= 6)
                    {
                        smart(&xPacman, &yPacman, &xGhosts[i], &yGhosts[i], arr, i, xGhosts, yGhosts);
                    }
                }
            }
        }
        bool lose;
        lose = 0;
        for (int i = 0; i < 4; i++)
        {
            if (xPacman == xGhosts[i] && yPacman == yGhosts[i])
            {
                lose = 1;
                (life)--;
            }
        }

        for (int i = 0; i < 4; i++)
        {
            if (lose == 1)
            {

                if (Score[xGhosts[i]][yGhosts[i]] == 10)
                {
                    arr[xGhosts[i]][yGhosts[i]] = ".";
                }
                else if (Score[xGhosts[i]][yGhosts[i]] == 0)
                {
                    arr[xGhosts[i]][yGhosts[i]] = " ";
                }
                else if (Score[xGhosts[i]][yGhosts[i]] == 50)
                {
                    arr[xGhosts[i]][yGhosts[i]] = "0";
                }
                xGhosts[0] = 1, xGhosts[1] = 1, xGhosts[2] = 18, xGhosts[3] = 18;
                yGhosts[0] = 1, yGhosts[1] = 18, yGhosts[2] = 1, yGhosts[3] = 18;

                for (int i = 0; i < 4; i++)
                {
                    arr[xGhosts[i]][yGhosts[i]] = "@";
                }
                arr[xPacman][yPacman] = " ";
                xPacman = 12, yPacman = 10;
                arr[xPacman][yPacman] = "C";
                if (life == 0)
                {
                    system("CLS");
                    cout << "You lose the game!!";
                    cout << "\t\t\tScore: " << score;
                    cout << endl;
                    return;
                }
            }
        }
        if (arr[xPacman][yPacman] == ".")
        {
            score += 10;
        }
        else if (arr[xPacman][yPacman] == "0")
        {
            score += 50;
        }

        SetCursorPosition(0, 0);
        if (xPacman == 0)
        {
            xPacman = 19;
        }
        else if (xPacman == 19)
        {
            xPacman = 0;
        }

        arr[xPacman][yPacman] = "C";
        for (int i = 0; i < 4; i++)
        {
            arr[xGhosts[i]][yGhosts[i]] = "@";
        }
        cout << "\tLife: " << life;
        cout << "\t\t\tScore: " << score;
        cout << endl;
        colorGame(arr, xGhosts, yGhosts, xPacman, yPacman);
        if (score == food * 10 + 150)
        {
            cout << "Congratulation!!You won the game.";
            return;
        }
    }
}