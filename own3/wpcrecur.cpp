#include <bits/stdc++.h>

using namespace std;

int memo[105][5];

int arr[105][5],max_row;

int funct(int row, int col)
{
	if(row==max_row)
		return 0;
	else if(memo[row][col]!=-1)
	{
		return memo[row][col];
	}
	else if(col==0)
	{
		memo[row][col] = arr[row][col] + min(funct(row+1,col+1),funct(row+1,col+2));
		return memo[row][col];
	}
	else if(col==2)
	{
		memo[row][col] = arr[row][col] + min(funct(row+1,col-1),funct(row+1,col-2));
		return memo[row][col];
	}
	else
	{
		memo[row][col] = arr[row][col] + min(funct(row+1,col-1),funct(row+1,col+1));
		return memo[row][col];
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int result_arr[105];
		memset(memo,-1,sizeof(memo));
		memset(arr,-1,sizeof(arr));
		scanf("%d",&max_row);
		for(int i=0; i<max_row; i++)
		{
			for(int j=0; j<3; j++)
			{
				scanf("%d",&arr[i][j]);
			}
		}
		for(int j=0;j<3;j++)
		{
	        result_arr[j]=funct(0,j);
	        // printf("%d ",result_arr[j]);
	    }
	    // printf("\n");
	    int final_res = result_arr[0];
	    for(int j=1;j<3;j++)
		{
			if(result_arr[j]<final_res)
				final_res = result_arr[j];
		}
		printf("%d\n",final_res);
	}
	
}