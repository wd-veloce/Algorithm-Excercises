#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool checkIfContinue(vector<int> input)
{
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] != 0) return true;
	}
	return false;
}


int main()
{
	int part, road;
	cin >> part >> road;
	vector<vector<int> > score;
	for (int i = 0; i < part; i++)
	{
		vector<int> initial(part, 1000);
		score.push_back(initial);
	}
	for (int i = 0; i < part; i++)
	{
		score[i][i] = 0;
	}
	for (int i = 0; i < road; i++) {
		int temp1, temp2, temp3;
		cin >> temp1 >> temp2 >> temp3;
		score[temp1 - 1][temp2 - 1] = temp3;
		score[temp2 - 1][temp1 - 1] = temp3;
	}
	//´æ´¢Êý¾Ý

	int pos = 0;
	vector<int> comp(part, 1000); comp[pos] = 0;
	vector<int> store;
	while (checkIfContinue(comp))
	{
		for (int i = 0; i < part; i++)
		{
			if (comp[i] > score[pos][i])comp[i] = score[pos][i];
		}
		int min = 1000;
		for (int i = 0; i < part; i++)
		{
			if (min > comp[i] && comp[i] != 0)
			{
				min = comp[i];
				pos = i;
			}
		}
		comp[pos] = 0;
		store.push_back(min);
	}
	sort(store.begin(), store.end());
	cout << store.size() << ' ' << store[store.size() - 1];
	return 0;
}