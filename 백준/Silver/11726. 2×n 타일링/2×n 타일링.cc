#include<iostream>
#include<vector>
using namespace std;
vector<int> dp;

int solution(int n)
{
	if (n <= 0) return 0;
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (dp[n] != 0) return dp[n];

	return (dp[n] = solution(n - 1) + solution(n - 2)) % 10007;
}
int main()
{
	dp.resize(1000);
	int n;
	cin >> n;
	cout <<solution(n) << endl;

}
