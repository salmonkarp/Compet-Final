#include <bits/stdc++.h>

using namespace std;
int t,v,k,ai,bi,ci,start,endx;

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&v,&k);
		vector<pair<int,int> > arr[v+1];
		for(int i=0; i<k; i++)
		{
			scanf("%d %d %d",&ai,&bi,&ci);
			arr[ai].push_back(make_pair(bi,ci));
			// printf("%d %d %d\n",ai,bi,ci);
		}

		scanf("%d %d",&start,&endx);
		priority_queue<pair<int,int> > djik;
		bool visited[v+5];
		memset(visited,false,sizeof(visited));

		djik.push(make_pair(0,start));

		while(djik.top().second != endx && !djik.empty())
		{
			int dist = -djik.top().first;
			int cur = djik.top().second;
			// cout << dist << cur << endl;
			djik.pop();
			visited[cur] = true;
			for(int x=0; x<arr[cur].size(); x++)
			{
				int dest = arr[cur][x].first;
				int cost = dist + arr[cur][x].second;
				// cout << dest  << ' '<< cost << endl;
				if(visited[dest] == false)
				{
					djik.push(make_pair(-cost,dest));
				}
			}
		}
		int ans = -djik.top().first;
		if (djik.top().second == endx)
			printf("%d\n",ans);
		else
			printf("NO\n");
	}
}