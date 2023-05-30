#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

int main()
{
	map<string, bool> m;
	int n;
	int cnt = 1;
	cin >> n;
	m.emplace("ChongChong", true);

	for (int i = 0; i < n; ++i)
	{
		string a, b;
		cin >> a >> b;


		auto member_A = m.find(a);
		auto member_B = m.find(b);
		if (member_A == m.end() && member_B == m.end())
		{
			m.insert(pair<string, bool>(a, false));
			m.insert(pair<string, bool>(b, false));
		}
		else if (member_A != m.end() && member_B != m.end() &&
			member_A->second == true && member_B->second == true)
		{
			continue;
		}
		else if ((member_A != m.end() && member_A->second == true))
		{
			if (member_B != m.end())
			{
				member_B->second = true;
			}
			else
				m.insert(pair<string, bool>(b, true));
			++cnt;
		}
		else if(member_B != m.end() && member_B->second == true)
		{
			if (member_A != m.end())
			{
				member_A->second = true;
			}
			else
				m.insert(pair<string, bool>(a, true));
			
			++cnt;
		}
	}
	cout << cnt;
}

