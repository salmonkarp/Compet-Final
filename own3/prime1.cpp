#include <bits/stdc++.h>
#define LL long long

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int m,n;
		scanf("%d %d",&m,&n);
		for(int i=m; i<=n; i++)
		{
			if(i==1 || (i%2==0 && i!=2)) //firewall 1 & 2
				continue;
			//firewall 3
			bool is_prime = true;
			for(int j=3; j<=sqrt(i); j+=2)
			{
				if(i%j==0)
				{
					is_prime = false;
					break;
				}
			}
			if(is_prime==true)
				printf("%d\n",i);
		}
		printf("\n");
	}
}