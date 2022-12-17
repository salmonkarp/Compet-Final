#include <bits/stdc++.h>
#define LL long long

using namespace std;
LL t,v,k,ai,bi,ci;
vector<pair<LL, LL> > arr[200005];
priority_queue<pair<LL,pair<LL,LL> > > djik;
bool visited[200005];

bool is_all_visited(bool arr[200005])
{
	for(LL i=1; i<=v; i++)
	{
		if(arr[i]==false)
			return false;
	}
	return true;
}
int main()
{
	scanf("%lld %lld",&v,&k);
	memset(visited,false,sizeof(visited));

	for(LL i=1; i<=v; i++)
	{
		scanf("%d",&visited[i]);
		if(visited[i]==1)
			djik.push(make_pair(0,make_pair(0,i)));
	}

	for(LL i=0; i<k; i++)
	{
		scanf("%lld %lld %lld",&ai,&bi,&ci);
		arr[ai].push_back(make_pair(bi,ci));
		arr[bi].push_back(make_pair(ai,ci));
		// printf("%d %d %d\n",ai,bi,ci);
	}
	LL final_cost = 0;
	while(!djik.empty() && !is_all_visited(visited))
	{
		LL dist = -djik.top().first;
		LL cur = djik.top().second.second;
		LL ori = djik.top().second.first;
		djik.pop();
		// cout << dist << ori << cur << endl;

		if(visited[cur]==false)
			final_cost += ori;

		visited[cur] = true;

		for(LL x=0; x<arr[cur].size(); x++)
		{
			LL dest = arr[cur][x].first;
			LL cost = dist + arr[cur][x].second;
			// printf("%d %d\n",dest,cost);

			if(visited[dest] == false)
			{
				djik.push(make_pair(-cost,make_pair(arr[cur][x].second,dest)));
			}
		}
	}
	if(is_all_visited(visited))
		printf("%lld\n",final_cost);
	else
		printf("impossible\n");
}