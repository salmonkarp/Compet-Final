#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,temp;
		deque<pair<int,bool> > dq;
		priority_queue<int> pq;
		scanf("%d %d",&n,&m);
		for(int i=0; i<n; i++)
		{
			scanf("%d",&temp);
			if(i==m)
				dq.push_back(make_pair(temp,true));
			else
				dq.push_back(make_pair(temp,false));
			pq.push(temp);
		}
		int timex = 0;
		// printf("HELLO\n");
		while(true)
		{
			// printf("TESTING\n");
			if(pq.top()!=dq.front().first) //other better things in q, move back
			{
				// printf("not printed, switch\n");
				dq.push_back(dq.front()2);
			}
			else //printed
			{
				// printf("printed,\n");
				timex++;
				pq.pop();
				if(dq.front().second==true)
					break;
			}
			dq.pop_front();
		}
		printf("%d\n",timex);
	}
}