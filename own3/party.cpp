#include <bits/stdc++.h>

using namespace std;

pair<int,int> memo[2005][2005];

int capacity, items;
int capacities[2005];
int values[2005];

pair<int,int> funct(int row, int capacity)
{
	if(row>=items)
		return make_pair(0,0);
	else if(memo[row][capacity]!=make_pair(-1,-1))
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
		pair<int,int> leave = funct(row+1,capacity);
		pair<int,int> get = funct(row+1,capacity-	capacities[row]);
		get.first = get.first + values[row];
		get.second = get.second + capacities[row];

		if(leave.first>get.first)
			return memo[row][capacity] = leave;
		else if(leave.first<get.first)
			return memo[row][capacity] = get;
		else if(leave.second<get.second)
			return memo[row][capacity] = leave;
		else
			return memo[row][capacity] = get;
	}
}
int main()
{
	scanf("%d %d",&capacity,&items);
	while(capacity!=0 && items!=0)
	{
		memset(memo,-1,sizeof(memo));
		for(int i=0; i<items; i++)
		{
			scanf("%d %d",&capacities[i],&values[i]);
		}
		pair<int,int> result = funct(0,capacity);
		printf("%d %d\n",result.second,result.first);
		scanf("%d %d",&capacity,&items);
	}	
}