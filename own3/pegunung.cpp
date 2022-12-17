#include <bits/stdc++.h>

using namespace std;

void gunung(int n)
{
	if(n>0)
	{
		gunung(n-1);
		for(int i=0; i<n; i++)
		{
			cout << "*";
		}
		cout << endl;
		gunung(n-1);
	}
}
int main()
{
	int n;
	cin >> n;
	gunung(n);
}