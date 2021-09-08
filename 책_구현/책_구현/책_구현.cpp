#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include "책_구현.h"
#include <string>
using namespace std;

int main()
{
    //왕실의나이트();
    //왕실나이트저자풀이();
    게임개발();
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
    string inputData;// = "a1";
    cin >> inputData;
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
            if (inputData == yx[i][j])
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

void 왕실나이트저자풀이()
{
    string inputData;
    int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
    // 현재 나이트의 위치 입력받기
    cin >> inputData;
    int row = inputData[1] - '0';
    int column = inputData[0] - 'a' + 1;

    // 8가지 방향에 대하여 각 위치로 이동이 가능한지 확인
    int result = 0;
    for (int i = 0; i < 8; i++) {
        // 이동하고자 하는 위치 확인
        int nextRow = row + dx[i];
        int nextColumn = column + dy[i];
        // 해당 위치로 이동이 가능하다면 카운트 증가
        if (nextRow >= 1 && nextRow <= 8 && nextColumn >= 1 && nextColumn <= 8) {
            result += 1;
        }
    }

    cout << result << '\n';
}

void 게임개발()
{
    int maxL = 4;
    int maxU = 4;;
    //cin >> maxU;
    //cin >> maxL; 
    int y = 1;
    int x = 1;
   // cin >> y;
    //cin >> x;
    int dir = 0;
    //cin >> dir;
    vector<vector<int> > map(maxU, vector<int>(maxL, 0));
    //0북1동2남3서
    //본방향에서 -90부터
    //가려는 방향이 바다면 회전    
    //1. 회전
    //2. 가보지않은 방향이면 이동 아니라면 회전
    //3. 사방이 막히면 브레이크
    for (int i = 0; i < maxU; i++)
    {
        for (int j = 0; j < maxL; j++)
        {
            cout << "y" << i << " " << "x" << j << "입력값";
            cin >> map[i][j];
        }
    }
    
    for (int i = 0; i < maxU; i++)
    {
        for (int j = 0; j < maxL; j++)
        {
            cout << map[i][j];
            if (j == maxL - 1) cout << "\n";
        }
    }
    map[x][y] = 3;
    int result = 1;
    int rot = 0;
    //map[y][x] = 3;
    while (true)
    {
        cout << "\n";
        for (int i = 0; i < maxU; i++)
        {
            for (int j = 0; j < maxL; j++)
            {
                cout << map[i][j];
                if (j == maxL - 1) cout << "\n";
            }
        }
        int a;
        cin >> a ;
        if (dir == 0)
        {
            dir = 3;
            rot++;
        }
        else
        {
            dir -= 1;
            rot++;
        }
        if (rot > 3) break;
        
        if (dir == 0)
        {
            if (y - 1 < 0) continue;
            if (map[y - 1][x] != 0) continue;
            if (map[y - 1][x] == 0)
            {
                map[y - 1][x] = 3;
                y = y - 1;
                result++;
                rot = 0;
                continue;
            }
        }
        if (dir == 1)
        {
            if (x + 1 > maxL) continue;
            if (map[y][x+1] != 0) continue;
            if (map[y][x+1] == 0)
            {
                map[y][x+1] = 3;
                x = x + 1;
                result++; rot = 0;
                continue;
            }
        }
        if (dir == 2)
        {
            if (y + 1 > maxU) continue;
            if (map[y + 1][x] != 0) continue;
            if (map[y + 1][x] == 0)
            {
                map[y + 1][x] = 3;
                y = y + 1;
                result++; rot = 0;
                continue;
            }
        }
        if (dir == 3)
        {
            if (x - 1 < 0) continue;
            if (map[y][x - 1] != 0) continue;
            if (map[y][x - 1] == 0)
            {
                map[y][x - 1] = 3;
                x = x - 1;
                result++; rot = 0;
                continue;
            }
        }
        break;
    }
    cout << "\n";
    for (int i = 0; i < maxU; i++)
    {
        for (int j = 0; j < maxL; j++)
        {
            cout << map[i][j];
            if (j == maxL - 1) cout << "\n";
        }
    }
    cout << "결과: " << result;
}