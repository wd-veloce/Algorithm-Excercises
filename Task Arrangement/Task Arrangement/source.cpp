#include<iostream>
#include<vector>
using namespace std;

bool ifContinue(vector<int> input) {
	int i = input[0];
	for (int j = 0; j < input.size(); j++)
	{
		if (input[j] != i)return true;
	}
	return false;
}

int count(vector<int> input, int begin, int end) {
	int result = 0;
	for (int i = begin; i <= end; i++)
	{
		result += input[i];
	}
	return result;
}
//from begin to end including begin & end.

int main()
{
	int N, S;
	vector<int> Ti, Fi;
	cin >> N >> S;
	for (int i = 0; i < N; i++)
	{
		int a, b; cin >> a >> b;
		Ti.push_back(a); Fi.push_back(b);
	}

	vector<int> cutPosition;
	vector<int> subTi(Ti), subFi(Fi);
	int startPoint = 0;

	while (subTi.size() > 1)
	{
		vector<int> tempStore1;
		for (int i = startPoint; i < subTi.size() - 1; i++)
		{
			tempStore1.push_back((-count(subTi, i + 1, subTi.size() - 1))*count(subFi, startPoint, i) + count(subFi, i + 1, subFi.size() - 1)*S);
		}
		int min = 200, pos = -1;
		for (int i = 0; i < tempStore1.size(); i++)
		{
			//cout << tempStore1[i];
			if (min > tempStore1[i] && tempStore1[i]<0)
			{
				min = tempStore1[i];
				pos = i+startPoint;
			}
		}
		if(pos!=-1){
			cutPosition.push_back(pos);
		}
		if (pos <= subTi.size() - 2) { 
			startPoint = pos + 1; 
		}
		else if (pos >= subTi.size() - 1 || pos==-1) {
			break; 
		}
	}
//	cout << endl;
//	for (int i = 0; i < cutPosition.size(); i++){cout << cutPosition[i];}
//	cout << endl;
	int i = 0, countNum = 0, count = 0;
	vector<int> changedTime;
	for (int j = 0; j < subTi.size(); j++)
	{
		countNum += subTi[j];
		count++;
		if (i > cutPosition.size()-1)
		{
			if (j == subTi.size() - 1)
			{
				countNum += S;
				for (int k = 0; k < count; k++)
				{
					changedTime.push_back(countNum);
				}
				count = 0;
				break;
			}
			else continue;
		}
		if (j == cutPosition[i])
		{
			countNum += S;
			for (int k = 0; k < count; k++)
			{
				changedTime.push_back(countNum);
			}
			count = 0;
			i++;
		}
	}
	//for (int i = 0; i < changedTime.size(); i++)cout << changedTime[i];
	//cout << endl;
	int result = 0;
	for (int i = 0; i < changedTime.size(); i++)
	{
		result = result + (changedTime[i] * subFi[i]);
	}
	cout << result;
 	return 0;
}