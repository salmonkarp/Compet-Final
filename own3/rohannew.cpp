#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	for(int casen=1; casen<=t; casen++)
	{
		int n;
		scanf("%d",&n);
		int arr[n+3][n+3];
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				scanf("%d",&arr[i][j]);
			}
		}


		//floyd
		for(int aux=1; aux<=n; aux++)
		{
			for(int ori=1; ori<=n; ori++)
			{
				for(int des=1; des<=n; des++)
				{
					arr[ori][des] = min(arr[ori][aux] + arr[aux][des], arr[ori][des]);
				}
			}
		}

		int r;
		int res = 0;
		scanf("%d",&r);
		for(int i=0; i<r; i++)
		{
			int s,d;
			scanf("%d %d",&s,&d);
			res += arr[s][d];
		}
		printf("Case #%d: %d\n",casen,res);
	}
}