#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <map>
using namespace std;

#define pp pair<int,int>

bool cmp(const pp& a, const pp& b) {
	if (a.second == b.second) return a.first > b.first;
	return a.second > b.second;
}

int main()
{
	map<int, int>a;
	map<int, int>c;
	int maxCin;
	for (int i = 0; i < maxCin; i++)
	{
		int b;
		cin >> b;
		a.insert(i, b);
		c.insert(i,b);
	}
	sort(c.begin(), c.end(), cmp);
	
	for (int i = 0; i < c.size();i++)
	{
		int count;
		for (int j = i; j < c.size();j++)
		{
			for (int k = c.size();k >= i;k++)
			{
				if (c[i] > c[k]&& c[j] > c[k])
				{
					count++;
				}
			}
		}

		c[i] = count;
	}
	
	sort(c.begin(), c.end());

	for (int i = 0; i < c.size();i++)
	{
		cout << c[i];
	}
}
