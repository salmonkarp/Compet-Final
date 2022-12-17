#include <bits/stdc++.h>
#define INF 1000000007;
using namespace std;

int main()
{
	int row,col;
	scanf("%d %d",&row,&col);
	int arr[row+5][col+5];
	int pf[row+5][col+5];
	memset(pf,0,sizeof(pf));
	int counter=0;
	// printf("%d %d\n",row,col);
	for(int i=1; i<=row; i++)
	{
		for(int j=1; j<=col; j++)
		{
			char temp;
			scanf(" %c",&temp);
			arr[i][j] = temp - 48;
			// printf("%d ",arr[i][j]);
			if(arr[i][j]==1)
			{
				counter++;
				pf[i][j]+=1;
			}
			pf[i][j]+= pf[i][j-1] + pf[i-1][j] - pf[i-1][j-1];
			// printf("%d ",pf[i][j]);
		}
		// printf("\n");
	}
	vector<int> factors;
	for(int i=1; i<=sqrt(counter); i++)
	{
		if(counter%i==0)
		{
			factors.push_back(i);
		}
	}
	vector<int> ans;
	int min_ans = INF;
	for(int i=0; i<factors.size(); i++)
	{
		int panjang = factors[i];
		int lebar = counter / panjang;
		// printf("p:%d l:%d\n",panjang,lebar);
		for(int x=1; x+lebar-1<=row; x++)
		{
			for(int y=1; y+panjang-1<=col; y++)
			{
				int temp_sum = counter - (pf[x+lebar-1][y+panjang-1] -pf[x-1][y+panjang-1] - pf[x+lebar-1][y-1]+ pf[x-1][y-1]);
				if(min_ans>temp_sum)
					min_ans = temp_sum;
				// printf("x:%d y:%d ts:%d\n",x,y,temp_sum);
			}
		}
		panjang = lebar;
		lebar = factors[i];
		// printf("p:%d l:%d\n",panjang,lebar);
		for(int x=1; x+lebar-1<=row; x++)
		{
			for(int y=1; y+panjang-1<=col; y++)
			{
				int temp_sum = counter-(pf[x+lebar-1][y+panjang-1] -pf[x-1][y+panjang-1] - pf[x+lebar-1][y-1]+ pf[x-1][y-1]);
				if(min_ans>temp_sum)
					min_ans = temp_sum;
				// printf("x:%d y:%d ts:%d\n",x,y,temp_sum);
			}
		}
	}
	if(min_ans==1000000007)
		printf("-1\n");
	else
		printf("%d\n",min_ans);
}