#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	pair<int,int> list[100005];
	for(int i=0; i<n; i++)
	{
		int temphour;
		scanf("%d %d",&list[i].second,&temphour);
		list[i].first = temphour + list[i].second;
	}
	sort(list,list+n);
	// for(int i=0; i<n; i++)
	// {
	// 	printf("%d %d\n",list[i].first,list[i].second);
	// }
	int res=1;
	int temp_end = list[0].first;
	for(int i=1; i<n; i++)
	{
		if(list[i].second>=temp_end)
		{
			temp_end = list[i].first;
			res+=1;
		}
	}
	printf("%d\n",res);
}