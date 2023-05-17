#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin >> n;

	vector<vector<long long>> dp;
	dp.resize(101, vector<long long>(10, 0));
	for (int i = 1; i <= 9; ++i)
		dp[1][i] = 1;
	
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 0; j <= 9; ++j)
		{
			if (j == 0)
				dp[i][j] = dp[i - 1][j + 1] % 1000000000;
			else if (j == 9)
				dp[i][j] = dp[i - 1][j - 1] % 1000000000;
			else
				dp[i][j] = (dp[i - 1][j + 1] + dp[i - 1][j - 1]) % 1000000000;
		}
	}

	long long res = 0;
	for (int i = 0; i <= 9; ++i)
		res += dp[n][i];
	cout << res % 1000000000 << endl;

}