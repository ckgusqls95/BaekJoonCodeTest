#include<iostream>
#include<vector>
using namespace std;

int BlueNum = 0;
int WhiteNum = 0;

bool IsSameTone(vector<vector<int>>& v, pair<int, int> s, int size)
{
    bool Isblue = v[s.first][s.second] == 1 ? true : false;
    for(int i = s.first; i < s.first + size; ++i)
        for(int j = s.second; j < s.second + size; ++j)
            if (Isblue == true && v[i][j] == 0 || Isblue == false && v[i][j] == 1)
            {
                return false;
            }
    
    if (Isblue)
        ++BlueNum;
    else
        ++WhiteNum;

    return true;
}
void solution(vector<vector<int>>& v, pair<int,int> s, int size)
{
    if (IsSameTone(v, s, size) == true)
        return;
    else
    {
        int PieceSize = size / 2;
        for (int i = s.first; i <= s.first + PieceSize; i += PieceSize)
        {
            for (int j = s.second; j <= s.second + PieceSize; j += PieceSize)
            {                
                solution(v, pair<int,int>(i,j), PieceSize);
            }
        }
        
    }

}


int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v;
    v.resize(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> v[i][j];

    solution(v, pair<int,int>(0,0), v.size());
    cout << WhiteNum << endl << BlueNum << endl;
}
