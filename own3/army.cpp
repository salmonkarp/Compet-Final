#include <bits/stdc++.h>
#define LL long long
using namespace std;

int main()
{
	LL t;
	scanf("%lld",&t);
	while(t--)
	{
		int ng,nm,temp;
		scanf("%d %d",&ng,&nm);
		priority_queue<int> team1;
		priority_queue<int> team2;
		for(int i=0; i<ng; i++)
		{
			scanf("%d",&temp);
			team1.push(-temp);
		}
		for(int i=0; i<nm; i++)
		{
			scanf("%d",&temp);
			team2.push(-temp);
		}
		while(!team1.empty() && !team2.empty())
		{
			if(team1.top() > team2.top())
			{
				team1.pop();
			}
			else
			{
				team2.pop();
			}
		}
		if(team1.empty())
			printf("MechaGodzilla\n");
		else
			printf("Godzilla\n");
	}
}