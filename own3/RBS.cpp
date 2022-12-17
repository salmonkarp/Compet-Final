#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string s;
		cin >> s;
		if (s.size()%2==0 && s[0]!=')' && s[s.size()-1]!='(')
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}