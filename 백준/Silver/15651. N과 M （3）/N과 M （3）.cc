#include<iostream>

using namespace std;

int n, m;
int result[10];
void solution(int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; ++i)
            cout << result[i] << ' ';
        cout << '\n';
        return;
    }
    else
    {
        for (int i = 1; i <= n; ++i)
        {           
            result[cnt] = i;
            solution(cnt + 1);
        }  
    }

}

int main()
{   
    cin >> n >> m;
    solution(0);
}