#include <bits/stdc++.h>

using namespace std;

long long arr[10000005];

long long dodiv(int n)
{
	if(n>10000000)
		return dodiv(n/2) + dodiv(n/3) + dodiv(n/4);
	if(n<=11)
		return n;
	if(arr[n]!=0)
		return arr[n];
	if(dodiv(n/2)+dodiv(n/3)+dodiv(n/4)>n)
		return arr[n] = dodiv(n/2)+dodiv(n/3)+dodiv(n/4);
	else
		return n;
}

int main()
{
	long long n;
	while( scanf("%lld", &n) != EOF)
	{
		printf("%lld\n",dodiv(n));
	}
}