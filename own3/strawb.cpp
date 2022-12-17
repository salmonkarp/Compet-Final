#include <bits/stdc++.h>

using namespace std;

int memo[2005][2005];

int max_capacity, items;
int capacities[2005];
int values[2005];

int funct(int row, int capacity)
{
	printf("r:%d c:%d\n",row,capacity);
	if(row==items-1)
	{
		printf("found%d\n",capacity);
		return;
	}
	else
	{
		//skip
		memo[row+1][capacity] = min(memo[row][capacity]+1,funct(row+1,capacity));
		//buy
		if(row+capacities[row]<=items-1 && capacity+1<=max_capacity)
			memo[row+capacities[row]][capacity+1] = min(memo[row][capacity],funct(row+capacities[row],capacity+1));
		// printf("%d\n",memo[row][capacity]);
		return funct(row+1,capacity);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&items,&max_capacity);
		memset(memo,999999,sizeof(memo));
		for(int i=0; i<items; i++)
		{
			scanf("%d",&capacities[i]);
		}
		for(int i=0; i<max_capacity; i++)
		{
			int result = funct(0,0);
		}
		printf("res%d\n",result);
	}
}