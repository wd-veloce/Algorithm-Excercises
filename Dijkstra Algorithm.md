```cpp
#include<iostream>
#include<vector>
using namespace std;

bool ifExist(vector<int> input, int a)
{
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == a) return true;
	}
	return false;
}

int main()
{
	vector<int> finlength, fincost;
	int n, m;
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0) break;
		vector<vector<int> > length, cost;

		for (int i = 0; i < n; i++)
		{
			vector<int> sub(n, 1000);
			length.push_back(sub);
			cost.push_back(sub);
		}
		for (int i = 0; i < n; i++)
		{
			length[i][i] = 0;
			cost[i][i] = 0;
		}
		for (int i = 0; i < m; i++)
		{
			int a, b, d, p;
			cin >> a >> b >> d >> p;
			length[a - 1][b - 1] = d;
			length[b - 1][a - 1] = d;
			cost[a - 1][b - 1] = p;
			cost[b - 1][a - 1] = p;
		}
		int start, end;
		cin >> start >> end;

		int Pos = start - 1;
		vector<int> recordRoad(n, 1000); recordRoad[Pos] = 0;
		vector<int> recordCost(n, 1000); recordCost[Pos] = 0;
		vector<int> exist; exist.push_back(Pos);

		while (exist.size() < n)
		{
			for (int i = 0; i < n; i++)
			{
				if (recordRoad[i] > length[Pos][i] + recordRoad[Pos])
				{
					recordRoad[i] = length[Pos][i] + recordRoad[Pos];
					recordCost[i] = cost[Pos][i] + recordCost[Pos];
				}
				else if (recordRoad[i] == length[Pos][i] + recordRoad[Pos] && recordCost[i] > cost[Pos][i] + recordCost[Pos])
				{
					recordCost[i] = cost[Pos][i] + recordCost[Pos];
				}
			}
			//update the record.

			int minRoad = 1000;
			for (int i = 0; i < n; i++)
			{
				if (minRoad > recordRoad[i] && (!ifExist(exist, i))) minRoad = recordRoad[i];
			}
			vector<int>recordMinRoad;
			for (int i = 0; i < n; i++)
			{
				if (recordRoad[i] == minRoad && (!ifExist(exist, i))) recordMinRoad.push_back(i);
			}
			int minCost = 1000;
			int tPos = 0;
			for (int i = 0; i < recordMinRoad.size(); i++)
			{
				if (minCost > recordCost[recordMinRoad[i]])
				{
					minCost = recordCost[recordMinRoad[i]];
					tPos = recordMinRoad[i];
				}
			}
			//find the minimum cost of the shortest roads.

			Pos = tPos;
			exist.push_back(Pos);
		}

		finlength.push_back(recordRoad[end - 1]);
		fincost.push_back(recordCost[end - 1]);
	}
	for (int i = 0; i < finlength.size(); i++)
	{
		cout << finlength[i] << ' ' << fincost[i] << endl;
	}
	return 0;
}

```