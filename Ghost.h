#include <iostream>
using namespace std;
void smart(int *xPacman, int *yPacman, int *xGhost1, int *yGhost1, string arr[20][20])
{
    if (*xGhost1 != *xPacman)
    {
        if (*xGhost1 > *xPacman)
        {
            if (arr[*xGhost1 - 1][*yGhost1] != "#" && arr[*xGhost1 - 1][*yGhost1] != "@")
            {
                (*xGhost1)--;
                return;
            }
            else
            {
                bool moveGhost = false;
                while (!moveGhost)
                {
                    int x = rand() % 3;
                    if (x == 0)
                    {
                        if (arr[*xGhost1][*yGhost1 + 1] != "#" && arr[*xGhost1][*yGhost1 + 1] != "@")
                        {
                            (*yGhost1)++;
                            moveGhost = true;
                            return;
                        }
                    }
                    else if (x == 1)
                    {
                        if (arr[*xGhost1][*yGhost1 - 1] != "#" && arr[*xGhost1][*yGhost1 - 1] != "@")
                        {
                            (*yGhost1)--;
                            moveGhost = true;
                            return;
                        }
                    }
                    else if (x == 2)
                    {
                        if (arr[*xGhost1 + 1][*yGhost1] != "#" && arr[*xGhost1 + 1][*yGhost1] != "@")
                        {
                            (*xGhost1)++;
                            moveGhost = true;
                            return;
                        }
                    }
                }
            }
        }
        else if (*xPacman > *xGhost1)
        {
            if (arr[*xGhost1 + 1][*yGhost1] != "#" && arr[*xGhost1 + 1][*yGhost1] != "@")
            {
                (*xGhost1)++;
                return;
            }
            else
            {
                bool moveGhost = false;
                while (!moveGhost)
                {
                    int x = rand() % 3;
                    if (x == 0)
                    {
                        if (arr[*xGhost1][*yGhost1 + 1] != "#" && arr[*xGhost1][*yGhost1 + 1] != "@")
                        {
                            (*yGhost1)++;
                            moveGhost = true;
                            return;
                        }
                    }
                    else if (x == 1)
                    {
                        if (arr[*xGhost1][*yGhost1 - 1] != "#" && arr[*xGhost1][*yGhost1 - 1] != "@")
                        {
                            (*yGhost1)--;
                            moveGhost = true;
                            return;
                        }
                    }
                    else if (x == 2)
                    {
                        if (arr[*xGhost1 - 1][*yGhost1] != "#" && arr[*xGhost1 - 1][*yGhost1] != "@")
                        {
                            (*xGhost1)--;
                            moveGhost = true;
                            return;
                        }
                    }
                }
            }
        }
    }
    if (*xGhost1 == *xPacman)
    {
        if (*yGhost1 != *yPacman)
        {
            if (*yGhost1 > *yPacman)
            {
                if (arr[*xGhost1][*yGhost1 - 1] != "#" && arr[*xGhost1][*yGhost1 - 1] != "@")
                {
                    (*yGhost1)--;
                    return;
                }
                else
                {
                    bool moveGhost = false;
                    while (!moveGhost)
                    {
                        int x = rand() % 3;
                        if (x == 0)
                        {
                            if (arr[*xGhost1 + 1][*yGhost1] != "#" && arr[*xGhost1 + 1][*yGhost1] != "@")
                            {
                                (*xGhost1)++;
                                moveGhost = true;
                                return;
                            }
                        }
                        if (x == 1)
                        {
                            if (arr[*xGhost1 - 1][*yGhost1] != "#" && arr[*xGhost1 - 1][*yGhost1] != "@" )
                            {
                                (*xGhost1)--;
                                moveGhost = true;
                                return;
                            }
                        }
                        if (x == 2)
                        {
                            if (arr[*xGhost1][*yGhost1 + 1] != "#" && arr[*xGhost1][*yGhost1 + 1] != "@" )
                            {
                                (*yGhost1)++;
                                moveGhost = true;
                                return;
                            }
                        }
                    }
                }
            }
            if (*yPacman > *yGhost1)
            {
                if (arr[*xGhost1][*yGhost1 + 1] != "#" && arr[*xGhost1][*yGhost1 + 1] != "@")
                {
                    (*yGhost1)++;
                    return;
                }
                else
                {
                    bool moveGhost = false;
                    while (!moveGhost)
                    {
                        int x = rand() % 3;
                        if (x == 0)
                        {
                            if (arr[*xGhost1 + 1][*yGhost1] != "#" && arr[*xGhost1 + 1][*yGhost1] != "@")
                            {
                                (*xGhost1)++;
                                return;
                            }
                        }
                        if (x == 1)
                        {
                            if (arr[*xGhost1 - 1][*yGhost1] != "#" && arr[*xGhost1 - 1][*yGhost1] != "@")
                            {
                                (*xGhost1)--;
                                return;
                            }
                        }
                        if (x == 2)
                        {
                            if (arr[*xGhost1][*yGhost1-1] != "#" && arr[*xGhost1][*yGhost1-1] != "@")
                            {
                                (*yGhost1)--;
                                return;
                            }
                        }
                    }
                }
            }
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
