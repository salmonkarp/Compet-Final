#include <bits/stdc++.h>
#define LL long long
using namespace std;
pair<LL,pair<LL,LL> > arr[100005];
LL n,m,temp1,temp2,temp3,ans;
vector<LL> family[10005];
LL parent[10005];
LL dist,ori,dest;
void dostuff(LL mx, LL orix, LL destx)
{
	for(LL i=0; i<family[mx].size(); i++)
	{
		if(parent[family[mx][i]]!=parent[orix])
		{
			parent[family[mx][i]] = parent[orix];
			dostuff(family[mx][i],orix,destx);
		}
	}
}
int main()
{
	scanf("%lld %lld",&n,&m);
	for(LL i=0; i<m; i++)
	{
		scanf("%lld %lld %lld",&temp1,&temp2,&temp3);
		arr[i] = make_pair(temp3,make_pair(temp1,temp2));
	}
	sort(arr,arr+m);
	for(LL i=1; i<=n; i++)
		parent[i] = i;

	ans = 0;
	for(LL i=0; i<m; i++)
	{
		dist = arr[i].first;
		ori = arr[i].second.first;
		dest = arr[i].second.second;
		if(parent[ori]!=parent[dest])
		{
			parent[dest] = parent[ori];
			dostuff(dest,ori,dest);
			family[ori].push_back(dest);
			family[dest].push_back(ori);
			ans += dist;
		}
	}
	printf("%lld\n",ans);
}