#include <bits/stdc++.h>

using namespace std;

int memo[105][105];

int arr[105][105],max_row,max_col;

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
		memo[row][col] = arr[row][col] + min(funct(row+1,col+1), funct(row+1,col));
		return memo[row][col];
	}
	else if(col==max_col-1)
	{
		memo[row][col] = arr[row][col] + min(funct(row+1,col-1), funct(row+1,col));
		return memo[row][col];
	}
	else
	{
		memo[row][col] = arr[row][col] + min(min(funct(row+1,col-1),funct(row+1,col+1)), funct(row+1,col));
		return memo[row][col];
	}
}
int main()
{
	int result_arr[105];
	memset(memo,-1,sizeof(memo));
	scanf("%d %d",&max_row, &max_col);
	for(int i=0; i<max_row; i++)
	{
		for(int j=0; j<max_col; j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	for(int j=0;j<max_col;j++)
	{
        result_arr[j]=funct(0,j);
        // printf("%d ",result_arr[j]);
    }
    // printf("\n");
    int final_res = result_arr[0];
    for(int j=1;j<max_col;j++)
	{
		if(result_arr[j]<final_res)
			final_res = result_arr[j];
	}
	printf("%d\n",final_res);

}