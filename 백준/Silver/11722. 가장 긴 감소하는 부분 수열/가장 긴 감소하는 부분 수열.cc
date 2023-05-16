#include<iostream>
#include<vector>
using namespace std;
vector<int> dp;
vector<int> sequence;

int main()
{
	int size, mx;
	mx = 1;
	cin >> size;
	sequence.resize(size);
	dp.resize(1000);
	for (int& n : sequence)
		cin >> n;

	for (int i = 0; i < size; i++)
	{		
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (sequence[j] > sequence[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
				mx = max(mx, dp[i]);
			}
		}
	}
	cout << mx << endl;	 
}