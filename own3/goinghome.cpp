#include <bits/stdc++.h>
#define LL long long
#define INF 1000000007
using namespace std;
LL t,v,k,ai,bi,ci,start,endx,news;

int main()
{
	scanf("%lld",&t);
	for(LL hk=1; hk<=t; hk++)
	{
		printf("Case #%lld:\n",hk);
		scanf("%lld %lld %lld",&v,&k,&news);
		vector<pair<LL,LL> > arr[v+1];
		vector<pair<LL,LL> > arr2[v+1];
		for(LL i=0; i<k; i++)
		{
			scanf("%lld %lld %lld",&ai,&bi,&ci);
			arr[ai].push_back(make_pair(bi,ci));
			arr2[bi].push_back(make_pair(ai,ci));
			// printf("%lld %lld %lld\n",ai,bi,ci);
		}

		//variables
		priority_queue<pair<LL,LL> > djik;
		bool visited[v+5];
		endx = v-1;
		LL direct1[v+5];
		LL direct2[v+5];

		//djikstra direct1
		memset(direct1,INF,sizeof(direct1));
		djik.push(make_pair(0,0));
		while(djik.top().second!=endx && !djik.empty())
		{
			LL dist = -djik.top().first;
			LL cur = djik.top().second;
			// cout << dist << " " << cur << endl;
			djik.pop();
			// visited[cur] = true;
			for(LL x=0; x<arr[cur].size(); x++)
			{
				LL dest = arr[cur][x].first;
				LL cost = dist + arr[cur][x].second;
				// cout << dest  << ' '<< cost << endl;
				if(direct1[dest] > cost)
				{
					direct1[dest] = cost;
					djik.push(make_pair(-cost,dest));
				}
			}
		}
		LL ans = -djik.top().first;
		direct1[0]=0;
		// for(int i=0; i<v; i++)
		// {
		// 	printf("d1: %d %lld\n",i,direct1[i]);
		// }

		//pre-djikstra
		while(!djik.empty())
			djik.pop();
		memset(visited,false,sizeof(visited));
		memset(direct2,INF,sizeof(direct2));
		endx=0;

		//djikstra direct2
		djik.push(make_pair(0,v-1));
		while(djik.top().second != endx && !djik.empty())
		{
			LL dist = -djik.top().first;
			LL cur = djik.top().second;
			// printf("%d:lld  cur:%lld\n",dist,cur);
			djik.pop();
			visited[cur] = true;
			for(LL x=0; x<arr2[cur].size(); x++)
			{
				LL dest = arr2[cur][x].first;
				LL cost = dist + arr2[cur][x].second;
				// printf("de:%lld   cost:%lld\n",dest,cost);
				if(direct2[dest]>cost)
				{
					direct2[dest] = cost;
					djik.push(make_pair(-cost,dest));
				}
			}
		}
		direct2[v-1]=0;
		//debug for direct2
		// for(int i=0; i<v; i++)
		// {
		// 	printf("d2: %d %lld\n",i,direct2[i]);
		// }

		//query processing
		
		for(LL i=0; i<news; i++)
		{
			scanf(" %lld %lld %lld",&ai,&bi,&ci);
			LL temp8 = direct1[ai];
			LL temp9 = direct2[bi];
			// printf("%lld %lld %lld\n",ai,bi,ci);
			// printf("%lld %lld %lld\n",temp8,temp9,ans);
			if(temp8+ci+temp9<ans)
				printf("YES\n");
			else
				printf("NO\n");
		}
		
	}
}