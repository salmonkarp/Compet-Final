#include <bits/stdc++.h>
#define LL long long
using namespace std;

int main()
{
	LL t;
	scanf("%lld",&t);
	while(t--)
	{
		// printf("new\n");
		LL res;
		scanf("%lld",&res);
		while(true)
		{
			char c;
			LL temp;
			scanf(" %c",&c);
			// printf("%c\n",c);
			if(c=='+')
			{
				scanf("%lld",&temp);
				res += temp;
			}
			else if(c=='-')
			{
				scanf("%lld",&temp);
				res -= temp;
			}
			else if(c=='*')
			{
				scanf("%lld",&temp);
				res *= temp;
			}
			else if(c=='/')
			{
				scanf("%lld",&temp);
				res /= temp;
			}
			else if(c=='=')
			{
				printf("%lld\n",res);
				break;
			}
		}
	}
}