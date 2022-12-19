#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int temp = 5;
		int res = 0;
		while(temp<=n)
		{
			res += n / temp;
			temp *= 5;
		}
		printf("%d\n",res);
	}
}