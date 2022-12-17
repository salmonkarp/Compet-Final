#include <bits/stdc++.h>

using namespace std;
int n,c;

bool isPossible(int dist,int arr[100008])
{
	int cowsplaced = 1;
	int last_cow_index = 0;
	for(int i=1; i<n; i++)
	{
		if(arr[i]-arr[last_cow_index]>=dist)
		{
			cowsplaced++;
			last_cow_index = i;
			if(cowsplaced==c)
				return true;
		}
	}
	// cout << "not possible: " << dist << endl;
	return false;
}

int bin_s(int arr[100008])
{
	int start = 0;
	int end = arr[n-1];
	int max_dist = -1;
	while(end>start)
	{
		int mid = (start + end) / 2;
		// cout << mid << endl;
		if(isPossible(mid,arr))
		{
			// cout << "ufu" << endl;
			max_dist = mid;
			start = mid + 1;
		}
		else
			end = mid;
	}
	return max_dist;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int arr[100008];
		scanf("%d %d",&n,&c);
		for(int i=0; i<n; i++)
		{
			scanf("%d",&arr[i]);
		}
		sort(arr,arr+n);
		int res = bin_s(arr);
		printf("%d\n",res);
	}
}