#include <bits/stdc++.h>
#define LL long long

using namespace std;


string binn(int x)
{
	if(x<=1)
	{
		return "1";
	}
	else if(x%2==1)
	{
		return binn(x/2)+"1";
	}
	else
	{
		return binn(x/2)+"0";
	}
}

int main()
{
	int n;
	cin >> n;
	cout << binn(n);
}