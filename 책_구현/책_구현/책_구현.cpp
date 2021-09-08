#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include "책_구현.h"
#include <string>
using namespace std;

int main()
{
    왕실의나이트();
}

void 시각()//구현 에제
{
    int n = 5;
    int time = 0;
    int min=0;
    int sec=0;
    int result = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < 60; j++)
        {
            for (int k = 0; k < 60; k++)
            {
                string a = to_string(i) + to_string(j) + to_string(k);
                for (int r = 0; r < a.length(); r++)
                {
                    if (a[r] == '3')
                    {
                        result++;
                        break;
                    }

                }
            }
        }
    }
    cout << result;
}

void 왕실의나이트()
{
    string cin = "a1";
    string yx[8][8];
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            string x;
            string y;
            if (i == 0)  y = 'a';
            else if (i == 1)  y = 'b';
            else if (i == 2)  y = 'c';
            else if (i == 3)  y = 'd';
            else  if (i == 4)  y = 'e';
            else  if (i == 5)  y = 'f';
            else  if (i == 6)  y = 'g';
            else  if (i == 7)  y = 'h';

            x = to_string(j + 1);

            yx[i][j] = y + x;
        }
    }

    int Y = 0;
    int X = 0;

    bool exitloop = false;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (cin == yx[i][j])
            {
                Y = i; X = j;
                exitloop = true;
                break;
            }
        }
        if (exitloop) break;
    }
    int result = 0;
    if (X - 2 >= 0 && Y - 1 >= 0) result++;
    if (X + 2 < 8 && Y - 1 >= 0) result++;
    if (X - 2 >= 0 && Y + 1 < 8) result++;
    if (X + 2 < 8 && Y + 1 < 8) result++;
    if (X - 1 >= 0 && Y - 2 >= 0) result++;
    if (X + 1 < 8 && Y - 2 >= 0) result++;
    if (X - 1 >= 0 && Y + 2 < 8) result++;
    if (X + 1 < 8 && Y + 2 < 8) result++;

    cout << result;


}