#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	for(int hk=1; hk<=t; hk++)
	{
		int n;
		scanf("%d",&n);
		int counter = 0;
		while(counter*(counter+1)/2<n)
		{
			counter++;
		}
		printf("Case #%d: ",hk);
		if(counter*(counter+1)/2==n)
		{
			printf("%d ",counter);
			for(int j=0; j<counter; j++)
				printf("+");
			printf("\n");
		}
		else
		{
			queue<pair<int,pair<int,string> > > pq;
			int temp = (counter+1)*counter/2;
			printf("counter:%d upper_limit:%d\n",counter,temp);
			pq.push(make_pair(0,make_pair(0,"")));
			bool is_found = false;
			while(!pq.empty())
			{

				int steps = pq.front().first;
				int location = pq.front().second.first;
				string path = pq.front().second.second;
				printf("(current)  st:%d loc:%d ",steps,location);
				cout << "path: " << path << endl;
				if(steps>counter)
				{
					break;
				}
				if(location==n && steps==counter)
				{
					is_found = true;
					break;
				}
				pq.pop();
				if(location<=temp)
				{
					
					pq.push(make_pair(steps+1,make_pair(location+counter-steps,path+"+")));
					pq.push(make_pair(steps+1,make_pair(location-counter+steps,path+"-")));
				}
				
			}
			if(is_found==true)
			{
				printf("%d ",counter);
				cout << pq.front().second.second << endl;
			}
			else
			{
				cout << "-1\n";
			}
		}
		
	}
}