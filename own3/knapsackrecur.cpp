#include <bits/stdc++.h>

using namespace std;

int memo[2005][2005];

int capacity, items;
int capacities[2005];
int values[2005];

int funct(int row, int capacity)
{
	if(row>items)
		return 0;
	else if(memo[row][capacity]!=-1)
	{
		return memo[row][capacity];
	}
	else if(capacities[row]>capacity)
	{
		memo[row][capacity] = funct(row+1,capacity);
		return memo[row][capacity];
	}
	else
	{
		int get = funct(row+1,capacity);
		int leave = values[row] + funct(row+1,capacity-capacities[row]);
		memo[row][capacity] = max(get,leave);
		return memo[row][capacity];
	}
}
int main()
{
	scanf("%d %d",&capacity,&items);
	memset(memo,-1,sizeof memo);
	for(int i=0; i<items; i++)
	{
		scanf("%d %d",&capacities[i],&values[i]);
	}
	int result = funct(0,capacity);
	printf("%d\n",result);
}