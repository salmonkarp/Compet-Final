#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		priority_queue<pair<int,int> > q;
		scanf("%d",&n);
		pair<int,int> height[n+5];
		int arr[n];
		for(int i=0; i<n; i++)
		{
			int temp3;
			scanf("%d",&temp3);
			height[i].first = -temp3;
			arr[i] = 0;
		}
		for(int i=0; i<n; i++)
		{
			int temp;
			scanf("%d",&temp);
			height[i].second = temp;
		}
		for(int i=0; i<n; i++)
			q.push(height[i]);
		
		while ( q.empty()==false)
		{
			int tinggi = -q.top().first;
			int jml = q.top().second;
			q.pop();
			
			for(int i=0; i<n; i++)
			{
				if ( arr[i] == 0 && jml==0)
				{
					arr[i] = tinggi;
					break;
				}
				
				if ( arr[i] == 0)
					jml--;
			}
		}

		for(int i=0; i<n; i++)
		{
			printf("%d ",arr[i]);
		}
	}
}