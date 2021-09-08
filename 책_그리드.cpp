#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
using namespace std;

void 잔돈거슬러주기();//그리디 알고리즘 예제
void 큰수의법칙();//그리디알고리즘실전문제
void 숫자카드게임();
void 일이될때까지();
//그리디알고리즘실전문제

int main()
{
    일이될때까지();
}

void 잔돈거슬러주기()
{
    int n = 1260;
    int count[4] = { 0,0,0,0 };
    int coin[4] = { 500, 100, 50, 10 };
    for (int i = 0; i < 4; i++)
    {
        count[i] = n / coin[i];
        n -= count[i] * coin[i];
    }
    for (int i = 0; i < 4; i++)
        cout << count[i] << "\n";

}

void 큰수의법칙()
{
    int n = 5;
    int m = 8;
    int k = 3;
    int arry[5] = { 2,4,5,4,6 };

    sort(arry, arry + 5, greater<>());

    for (int i = 0; i < n; i++)
    {
        //cout << arry[i] << "\n";

    }

    int a = 0;
    int b = 0;
    while (a<m)
    {
        for (int i = 0; i < k; i++)
        {
            a++;
            b += arry[0];
            cout << arry[0] << "\n";
            if (a >= m) break;
        }

        if (a >= m) break;
        if (a >= k)
        {
            a++;
            b += arry[1];
            cout << arry[1] << "\n";

        }
    }
    cout << b << "\n";
}

void 숫자카드게임()
{
    int n = 3;
    int m = 3;
    int arry[3][3];
    arry[0][0] = 3;
    arry[0][1] = 1;
    arry[0][2] = 2;
    arry[1][0] = 4;
    arry[1][1] = 1;
    arry[1][2] = 4;
    arry[2][0] = 3;
    arry[2][1] = 3;
    arry[2][2] = 3;

    vector<int> v_arry;
    
    for (int i = 0; i < 3; i++)
    {
        sort(arry[i], arry[i]+2);
        v_arry.push_back(arry[i][0]);
    }

    sort(v_arry.begin(), v_arry.end(),greater<>());

    cout << v_arry[0];

}

void 일이될때까지()//그리디 실전문제
{
    int n = 25;
    int k = 5;
    //1. n-1;
    //2. n/k;
    //n이 1이 될때까지
    int result = 0;
    while (n>1)
    {
        if (n % k == 0)
        {
            n = n / k;

            result++;
            continue;
        }

        result++;
        n - 1;
    }
    cout << result;
}