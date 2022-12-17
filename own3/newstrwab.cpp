#include <bits/stdc++.h>

using namespace std;

int memo[2005][2005];

int max_capacity, items;
int capacities[2005];
int values[2005];

void funct(int row, int col)
{
	//printf("r:%d c:%d\n",row,capacity);
	if(row>=items-1)
	{
		//printf("found%d\n",capacity);
		return ;
	}
	else
	{
		//skip
		memo[row+1][col] = min( memo[row][col] +1, memo[row+1][col]);
		
		//beli
		if ( row + capacities[row] <= items-1 && col+1<=max_capacity)
		{
			int baris = row+capacities[row];
			memo[baris][col + 1] = min(memo[row][col], memo[baris][col+1]);
		}
		funct(row+1, col);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int hj=1; hj<=t; hj++)
	{
		scanf("%d %d",&items,&max_capacity);
		//memset(memo,-1,sizeof(memo));
		for(int b=0; b<=items-1; b++)
		{
			for(int k=0; k<=max_capacity; k++)
			{
				memo[b][k] = 1000000000;
			}
		}
		
		for(int i=0; i<items; i++)
		{
			scanf("%d",&capacities[i]);
		}
		memo[0][0] = 0;
		
		for(int a=0; a<=max_capacity; a++)
		{
			funct(0,a);
			//printf("a=%d res%d\n",a, result);
		}
		
		int min = 1000000000;
		// printf("isi memo:\n");
		for(int b=0; b<=items-1; b++)
		{
			for(int k=0; k<=max_capacity; k++)
			{
				printf("%d ", memo[b][k]);
				if(min>memo[b][k] && b==items-1)
				{
					// printf("min%d",min);
					min=memo[b][k];
				}
			}
			printf("\n");
		}
		printf("Scenario #%d:\n",hj);
		if(min!=1000000000 && min!=items-1)
			printf("Teresa will skip %d strawberries\n",min);
		else
			printf("Teresa will skip all the strawberries\n");
	}
}