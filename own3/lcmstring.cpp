#include <bits/stdc++.h>
#include <numeric>
#define LL long long
using namespace std;

string multiplys(string s, int a)
{
	string x = "";
	while(a--)
	{
		x += s;
	}
	return x;
}
int main()
{
	int t;
	cin >>  t;
	while(t--)
	{
		string s1,s2;
		cin >> s1 >> s2;
		int len1 = s1.length();
		int len2 = s2.length();
		int len_gcd = lcm(len1,len2);
		// cout << len_gcd << endl;
		string long_len1 = multiplys(s1,len_gcd/len1);
		string long_len2 = multiplys(s2,len_gcd/len2);
		if(long_len1==long_len2)
			cout << long_len1 << endl;
		else
			cout << -1 << endl;
	}
}