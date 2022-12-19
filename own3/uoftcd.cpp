#include <bits/stdc++.h>
#define LL long long
#define INF (LL)1e9
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	for(int hk=1; hk<=t; hk++)
	{
		LL d,h,m,l,cur_time,cur_fear,total_time,final_final,fear_level;
		LL start_time = 0;
		scanf("%lld %lld %lld %lld",&d,&m,&h,&l);
		pair<LL,LL> moments[m+5];
		for(LL i=1; i<=m; i++)
			scanf("%lld %lld",&moments[i].first,&moments[i].second);
		final_final = INF;
		for(LL i=0; i<=m; i++)
		{
			total_time = 0;
			fear_level = 0;
			start_time = -1;
			for(LL j=1; j<=m; j++)
			{
				if(j==i)
				{
					continue;
				}
				cur_time = moments[j].first;
				cur_fear = moments[j].second;
				// printf("%d %d\n",cur_time,cur_fear);
				fear_level += cur_fear;
				if(fear_level<0)
					fear_level=0;
				if(fear_level>=h && fear_level<l && start_time == -1)
				{
					start_time = cur_time;
					// printf("START\n");
				}
				else if((fear_level<h || fear_level>=l) && start_time!=-1)
				{
					total_time += cur_time - start_time;
					// printf("add! cur:%d; start:%d\n",cur_time,start_time);
					start_time = -1;
				}
				if(fear_level>=l)
				{
					start_time = -1;
					break;
				}
			}
			if(start_time!=-1)
			{
				total_time += d - start_time;
			}
			// printf("temp_fin:%d\n",total_time);
			final_final = min(final_final, total_time);
		}
		printf("%lld\n",final_final);;
	}
}