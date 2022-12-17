#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int arr[10005];
		int n,u,l,r,val,q,temp;
		cin >> n >> u;
		for(int i=0; i<u; i++)
		{
			scanf("%d %d %d",&l,&r,&val);
			for(int j=l; j<=r; j++)
				arr[j] += val;
		}
		scanf("%d",&q);
		for(int j=0; j<q; j++)
		{
			scanf("%d",&temp);
			printf("%d\n",arr[temp]);
		}

	}
}