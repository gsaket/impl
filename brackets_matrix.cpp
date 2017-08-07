// This code belongs to Matrix(cf)
// http://codeforces.com/problemset/problem/508/E
#include <iostream>
#include <stack>

using namespace std;

const int MAXN = 610;

stack<int> st;
string s;
int p[MAXN], l[MAXN], r[MAXN];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> l[i] >> r[i];
		st.push(i);
		p[i] = s.length();
		s += '(';
		cout<<i<<" "<<"("<<endl;
		while (!st.empty() && p[st.top()] + l[st.top()] <= s.length())
		{
			if (p[st.top()] + r[st.top()] < s.length())
			{
				cout << "IMPOSSIBLE" << endl;
				return 0;
			}
			s += ')';
			cout<<i<<" )"<<endl;
			st.pop();
		}
	}
	if (!st.empty())
		cout << "IMPOSSIBLE" << endl;
	else
		cout << s << endl;

}

