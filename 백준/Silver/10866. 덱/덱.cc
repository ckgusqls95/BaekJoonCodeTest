#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	int orders;
	cin >> orders;
	cin.ignore();

	vector<int> deque;
	vector<string> v;

	for (int i = 0; i < orders; ++i)
	{
		string input;		
		getline(cin, input, '\n');
		v.push_back(input);
	}	

	for (string& s : v)
	{
		int split_word = s.find(' ', 0);
		string order = s.substr(0, split_word);

		int num = 0;
		if (split_word != -1)
			num = stoi(s.substr(split_word + 1, s.size() - 1));

		if (order.compare("push_front") == 0)
		{
			deque.insert(deque.begin(), num);
		}
		else if (order.compare("push_back") == 0)
		{
			deque.push_back(num);
		}
		else if (order.compare("pop_front") == 0)
		{
			if (deque.size() > 0)
			{
				int f = deque.front();
				cout << f << endl;
				deque.erase(deque.begin(), deque.begin() + 1);
			}
			else
				cout << -1 << endl;
		}
		else if (order.compare("pop_back") == 0)
		{
			if (deque.size() > 0)
			{
				int b = deque.back();
				cout << b << endl;
				deque.pop_back();
			}
			else
				cout << -1 << endl;
		}
		else if (order.compare("size") == 0)
		{
			cout << deque.size() << endl;
		}
		else if (order.compare("empty") == 0)
		{
			cout << ((deque.size() == 0) ? 1 : 0) << endl;
		}
		else if (order.compare("front") == 0)
		{
			cout << (deque.size() > 0 ? deque.front() : -1) << endl;
		}
		else
			cout << (deque.size() > 0 ? deque.back() : - 1) << endl;
	}

}