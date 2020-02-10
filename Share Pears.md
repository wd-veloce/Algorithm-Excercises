```cpp
#include<iostream>
#include<vector>
using namespace std;

class pairs {
public:
	int pears;
	int plates;
};


int check(int a, int b) {
	int temp = 1;
	int result = 0;
	if (a == 0) return 1;
	while (temp <= b && a - temp >= 0) {
		result += check(a - temp, temp); temp++;
	}
	return result;
}

int main()
{
	int num; cin >> num;
	vector<pairs> store;
	for (int i = 0; i < num; i++) {
		pairs o;
		cin >> o.pears >> o.plates;
		store.push_back(o);
	}
	for (int i = 0; i < num; i++) {
		cout << check(store[i].pears, store[i].plates) << endl;
	}
	return 0;
}

```