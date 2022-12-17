#include <iostream>
#include <algorithm>
#define LL long long

using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);

		int initial[100005];
		int diff[100005];
		int ans[100005];

		//IO
		for(int i=0; i<n; i++)
			scanf("%d",&initial[i]);
		for(int i=0; i<n; i++)
		{
			int temp;
			scanf("%d",&temp);
			diff[i] = temp - initial[i];
		}

		ans[0] = abs(diff[0]);
		for(int i=1; i<n; i++)
		{
			if(diff[i]*diff[i-1]<0){
				ans[i] = abs(diff[i]);
			}
			else
			{
				if(abs(diff[i])>abs(diff[i-1]))
				{
					ans[i] = abs(diff[i]) - abs(diff[i-1]);
					// printf(" split\n");
				}
				else
				{
					ans[i] = 0;
				}
			}
			// cout << i << ' ' << diff[i-1] << ' ' << diff[i] << ' '<< ans[i] << endl;
		}
		int final_res = 0;
		for(int i=0; i<n; i++)
		{
			final_res += ans[i];
			// printf("%d ",ans[i]);
		}
		printf("%d\n",final_res);
	}

}