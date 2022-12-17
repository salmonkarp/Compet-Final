#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
	LL t;
	scanf("%lld",&t);
	LL counter=1;
	while(t--)
	{
		LL n;
		LL arr[20005];
		LL memo[20005];
		memo[0] = 0;
		scanf("%lld",&n);
		for(LL i=1; i<=n; i++)
		{
			scanf("%lld",&arr[i]);
			memo[i] = arr[i] ^ memo[i-1];
		}
		sort(memo,memo+n+1);
		LL temp_int = memo[0];
		LL temp_counter = 1;
		LL res=0;
		for(LL i=1; i<=n; i++)
		{
			if(memo[i]==temp_int)
				temp_counter++;
			if(memo[i]!=temp_int || i==n)
			{
				res += (temp_counter)*(temp_counter-1) / 2;
				temp_int = memo[i];
				temp_counter = 1;
			}
		}
		printf("Case #%lld: %lld\n",counter,res);
		counter++;	
	}
}