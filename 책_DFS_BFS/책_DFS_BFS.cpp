// 책_DFS_BFS.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include "책_DFS_BFS.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <deque>
#include<queue>

using namespace std;

int maxX;
int maxY;
int map[1000][1000];
queue<string> q;

int a = 0;
int b = 0;
int main()
{
    음료수얼려먹기();
}


void 음료수얼려먹기()
{
    cin >> maxX;
    cin >> maxY; 

    for (int i = 0; i < maxY; i++)
    {
        for (int j = 0; j < maxX; j++)
        {
            cout << "y" << i << " " << "x" << j << "입력값";
            cin >> map[i][j];
        }
    }

    int result = 0;

    for (int i = 0; i < maxY; i++)
    {
        for (int j = 0; j < maxX; j++)
        {

            if (너비탐색(i, j))
            {
                result += 1;
            }
        }
    }

    cout << result;
    


}

bool 너비탐색(int x, int y)
{
    if (x <= -1 || x >= maxX || y <= -1 || y >= maxY)
        return false;
    if (map[y][x] == 0)
    {

        map[y][x] = 1;

        너비탐색(y, x+1);
        너비탐색(y, x-1);
        너비탐색(y+1, x);
        너비탐색(y-1, x);
        return true;
    }
    
    return false;
    
}
//1. BFS가 사용되면 count++;
//2. 아니면 컷
//3. 음 좌표계는 2중 배열로하고 인트형을 가진 벡터에다가 만약 1로 바꾸면 카운트 

