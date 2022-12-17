#include <bits/stdc++.h>
#define LL long long
using namespace std;

int main()
{
	int t,temp,ini1;
	cin >> t;
	while(t--)
	{
		int n,d;
		int arr[300];
		bool can_fix = false;
		bool doable = true;
		scanf("%d %d",&n,&d);
		// printf("%d %d\n",n,d);
		for(int i=0; i<n; i++)
		{
			scanf("%d",&arr[i]);
		}
		sort(arr,arr+n);
		for(int i=0; i<n; i++)
		{
			temp = arr[i];
			if(i==0)
				ini1 = temp;
			if(i==1 && ini1+temp<=d)
				can_fix = true;
			if(temp>d && can_fix==false)
			{
				doable = false;
				// cout << "BRAK!" << endl;
			}
		}
		if(doable==false)
			printf("NO\n");
		else
			printf("YES\n");
	}
}