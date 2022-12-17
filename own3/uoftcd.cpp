#include <bits/stdc++.h>
#define SCAN(n) scanf("%d",&n);
#define PRINT(n) printf("%d\n",n);
#define FOR(a,b,c) for(int a=b; a<=c; a++)
#define ROF(a,b,c) for(int a=b; a>=c; a--)
#define MOD 1000000007
#define INF (int)1e9
#define mp make_pair
using namespace std;
int main()
{
	int t;
	SCAN(t);
	FOR(hk,1,t)
	{
		// printf("HELLO");
		int d,h,m,l;
		scanf("%d %d %d %d",&d,&m,&h,&l);
		pair<int,int> moments[m+5];
		int current_fear;
		FOR(i,1,m)
		{
			scanf("%d %d",&moments[i].first,&moments[i].second);
		}
		FOR(i,1,m)
		{
			printf("%d %d\n",moments[i].first,moments[i].second);
		}
		printf("HELLO");
	}
}