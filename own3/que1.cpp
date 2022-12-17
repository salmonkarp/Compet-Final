#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		priority_queue< pair<int,int> > q;
		scanf("%d",&n);
		pair<int,int> height[n+5];
		for(int i=0; i<n; i++)
		{
			int temp3;
			scanf("%d",&temp3);
			height[i].first = -temp3;
		}
		for(int i=0; i<n; i++)
			scanf("%d",&height[i].second);
		for(int i=0; i<n; i++)
			q.push(height[i]);
		
		int temp_end = q.top().second;
		int adder = 0;
		int arr[n];
		for(int i=0; i<n; i++)
		{
			int temp4 = q.top().second;
			arr[q.top().second + adder] = q.top().first;
			// printf("%d ",q.top().second + adder);
			q.pop();
			if(temp4==0)
			{
				adder += temp_end + q.top().second;
			}
		}

		for(int i=0; i<n; i++)
		{
			printf("%d ",-arr[i]);
			q.pop();
		}
	}
}