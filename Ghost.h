#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
bool canMove(int x, int y, string arr[20][20])
{
    return x >= 0 && y >= 0 && x < 20 && y < 20 && arr[x][y] != "#" && arr[x][y] != "@";
}
bool isOccupiedByOtherGhost(int x, int y, int selfIndex, int xGhosts[4], int yGhosts[4])
{
    for (int i = 0; i < 4; i++)
    {
        if (i != selfIndex && xGhosts[i] == x && yGhosts[i] == y)
        {
            return true;
        }
    }
    return false;
}

void smart(int *xPacman, int *yPacman, int *xGhost, int *yGhost, string arr[20][20], int index, int xGhosts[4], int yGhosts[4])
{
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int order[4];
    int idx = 0;

    if (*xGhost < *xPacman)
        order[idx++] = 1;
    else if (*xGhost > *xPacman)
        order[idx++] = 0;

    if (*yGhost < *yPacman)
        order[idx++] = 3;
    else if (*yGhost > *yPacman)
        order[idx++] = 2;

    for (int i = 0; i < 4; i++)
    {
        bool found = false;
        for (int j = 0; j < idx; j++)
        {
            if (order[j] == i)
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            order[idx++] = i;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        int dir = order[i];
        int nx = *xGhost + dx[dir];
        int ny = *yGhost + dy[dir];

        if (canMove(nx, ny, arr) && !isOccupiedByOtherGhost(nx, ny, index, xGhosts, yGhosts))
        {
            *xGhost = nx;
            *yGhost = ny;
            return;
        }
    }
}

void foolish1(int *xGhost1, int *yGhost1, string arr[20][20])
{
    if (arr[*xGhost1][*yGhost1 + 1] != "#")
    {
        (*yGhost1)++;
        return;
    }
    else if (arr[*xGhost1 - 1][*yGhost1] != "#")
    {
       
 (*xGhost1)--;
        return;
    }
    else if (arr[*xGhost1][*yGhost1 - 1] != "#")
    {
        (*yGhost1)--;
        return;
    }
    else
    {
        (*xGhost1)++;
        return;
    }
}
void foolish2(int *xGhost1, int *yGhost1, string arr[20][20])
{
    if (arr[*xGhost1 - 1][*yGhost1] != "#")
    {
        (*xGhost1)--;
        return;
    }
    else if (arr[*xGhost1][*yGhost1 - 1] != "#")
    {
        (*yGhost1)--;
        return;
    }
    else if (arr[*xGhost1 + 1][*yGhost1] != "#")
    {
        (*xGhost1)++;
        return;
    }
    else
    {
        (*yGhost1)++;
        return;
    }
}

void foolish3(int *xGhost1, int *yGhost1, string arr[20][20])
{
    if (arr[*xGhost1][*yGhost1 - 1] != "#")
    {
        (*yGhost1)--;
        return;
    }
    else if (arr[*xGhost1 + 1][*yGhost1] != "#")
    {
        (*xGhost1)++;
        return;
    }
    else if (arr[*xGhost1][*yGhost1 + 1] != "#")
    {
        (*yGhost1)++;
        return;
    }
    else
    {
        (*xGhost1)--;
        return;
    }
}

void foolish4(int *xGhost1, int *yGhost1, string arr[20][20])
{
    if (arr[*xGhost1 + 1][*yGhost1] != "#")
    {
        (*xGhost1)++;
        return;
    }
    else if (arr[*xGhost1][*yGhost1 + 1] != "#")
    {
        (*yGhost1)++;
        return;
    }
    if (arr[*xGhost1 - 1][*yGhost1] != "#")
    {
        (*xGhost1)--;
        return;
    }
    else
    {
        (*yGhost1)--;
        return;
    }
}
void foolish(int *xGhost1, int *yGhost1, string arr[20][20])
{
    srand(time(0));
    int p = rand() % 4;
    if (p == 0)
    {
        foolish1(xGhost1, yGhost1, arr);
    }
    else if (p == 1)
    {
        foolish2(xGhost1, yGhost1, arr);
    }
    else if (p == 2)
    {
        foolish3(xGhost1, yGhost1, arr);
    }
    else if (p == 3)
    {
        foolish4(xGhost1, yGhost1, arr);
    }
    if (*xGhost1 == -1)
    {
        *xGhost1 = 19;
    }
    else if (*xGhost1 == 20)
    {
        *xGhost1 = 0;
    }
}
