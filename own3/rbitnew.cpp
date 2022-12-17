#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	for(int hk=1; hk<=t; hk++)
	{
		int n;
		scanf("%d",&n);
		LL l = 1, r = n, idx = 0;
		while(l<=r)
		{
			LL mid = (l+r)/2;
			LL val = mid*(mid+1)/2;
			if(val>=n)
			{
				idx = mid;
				r = mid-1;
			}
			else
			{
				l = mid+1;
			}
		}
		
		LL upper = idx*(idx+1)/2;
		while((upper-n)%2!=0)
		{
			idx++;
			upper = idx*(idx+1)/2;
		}
		// printf("%d ",idx);
		string s = "";
		LL neg = (upper-n)/2;
		for(int i=idx; i>=1; i--)
		{
			if(i>neg)
			{
				s = s + "+";
			}
			else
			{
				s = s+"-";
				neg -= idx;
				// cout << neg << endl;
			}
		}
		printf("Case #%d: ",hk);
		if(neg>0)
			printf("-1\n");
		else
		{
			printf("%d ",idx);
			cout << s << endl;
		}
	}
}