#include<iostream>
#include<vector>
using namespace std;

vector<int> dp;
// idx == num, value == count
int solution(int n) 
{ 
    if (n <= 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 4;

    if (dp[n] != 0) return dp[n];

    return  dp[n] = solution(n - 3) + solution(n - 2) + solution(n - 1);
}
int main()
{
    dp.resize(10000, 0);
    int T;
    cin >> T;
    vector<int> inputs;
    inputs.resize(T);
 
    for(int& n : inputs)
        cin >> n;
    
    for (int n : inputs)
        cout << solution(n) << endl;
}