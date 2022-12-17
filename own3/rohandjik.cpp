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

		//djikstra
		
		int res = 0;
		
		int r;
		scanf("%d",&r);
		for(int i=0; i<r; i++)
		{
			priority_queue<pair<int,int> > pq;
			bool visited[n+3];
			memset(visited,false,sizeof(visited));
			
			int s,d;
			scanf("%d %d",&s,&d);
			pq.push(make_pair(0,s));

			while(pq.top().second != d)
			{
				int dist = -pq.top().first;
				int orig = pq.top().second;
				pq.pop();

				visited[orig] = true;

				for(int j=1; j<=n; j++)
				{
					int dest = j;
					int new_dist = dist + arr[orig][dest];
					if(visited[dest]==false)
					{
						pq.push(make_pair(-new_dist,dest));

					}
				}
			}
			res += -pq.top().first;
			// printf("%d ",res);
		}
		printf("Case #%d: %d\n",casen,res);
	}
}