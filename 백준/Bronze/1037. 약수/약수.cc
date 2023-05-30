#include<iostream>
#include<vector>
#include<math.h>
#include<string>
#include<array>
#include <algorithm>

using namespace std;
int main()
{
	vector<int> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	cout << v[0] * v[v.size()-1] << endl;
}
