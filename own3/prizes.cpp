#include <bits/stdc++.h>

using namespace std;

int memo[2005][2005];

int capacity, items;
int capacities[2005];
int values[2005];
// bool path[2005][2005];
bool bought_sth = false;
int K[2005][2005];
int path[2005][2005];
deque<int> ans;
void rec(int x, int y)
{
	if(x==0) return;
	if(path[x][y]==1)
	{
		// printf("%d %d\n",x,y);
		ans.push_back(x);
		rec(x-1,y-capacities[x-1]);
	}
	else
		rec(x-1,y);
}
int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
            {
            	int temp1 = val[i - 1] + K[i - 1][w - wt[i - 1]];
            	int temp2 = K[i - 1][w];
                K[i][w] = max(temp1,temp2);
                if(temp1>temp2)
                {
                	path[i][w] = 1;
                	bought_sth = true;
                }
            }
            else
                K[i][w] = K[i - 1][w];
        }
    }
    // for(int i=0; i<=n; i++)
	// {
	// 	for(int j=0; j<=W; j++)
	// 	{
	// 		printf("%d ",K[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// printf("\n");
	// for(int i=0; i<=n; i++)
	// {
	// 	for(int j=0; j<=W; j++)
	// 	{
	// 		printf("%d ",path[i][j]);
	// 	}
	// 	printf("\n");
	// }
	int temp=K[n][W], counter=0;
	while(K[n][counter]!=temp)
		counter++;
	// printf("start:%d\n",counter);
	rec(n,counter);
    return K[n][W];
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int hk=1; hk<=t; hk++)
	{
		bought_sth = false;
		scanf("%d %d",&capacity,&items);
		memset(K,0,sizeof(K));
		memset(path,0,sizeof(path));
		for(int i=0; i<items; i++)
		{
			scanf("%d %d",&capacities[i],&values[i]);
		}
		int result = knapSack(capacity,capacities,values,items);
		// printf("%d\n",result);
		printf("Case %d:\n",hk);
		if(bought_sth == true)
		{
			while(!ans.empty())
			{
				printf("%d\n",ans.back());
				ans.pop_back();
			}
		}
		else
			printf("0\n");
	}
	
}