#include <bits/stdc++.h>

using namespace std;
int y,x,step;
int arr[185][185];
int res_arr[185][185];
bool visited[185][185];
pair<int,int> starts[183*183];

int main()
{
	
	int t;
	scanf("%d",&t);
	for(int k=0;k<t;k++)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		int counter = 0;
		for(int i=0; i<n; i++)
		{
			string steve;
			cin>>steve;
			for(int j=0; j<m; j++)
			{
				arr[i][j] = int(steve[j])-48;
				if(arr[i][j]==1)
				{
					// printf("i:%d,j;%d\n",i,j);
					starts[counter] = make_pair(i,j);
					counter++;
				}
			}
		}
		
		// printf("isi array :\n");
		// for(int i=0; i<n; i++)
		// {
		// 	for(int j=0; j<m; j++)
		// 	{
		// 		printf("%d ", arr[i][j]);
		// 	}
		// 	printf("\n");
		// }
		//something weird around here
		// printf("TEST\n");
		// printf("TEST2\n");
		queue<pair<int,pair<int,int> > > q;
		
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				res_arr[i][j] = 999999;
			}
		}

		for(int i=0; i<counter; i++)
		{
			memset(visited,false,sizeof(visited));
			q.push(make_pair(starts[i].first,make_pair(starts[i].second,0)));
			
			while(!q.empty())
			{
				y = q.front().first;
				x = q.front().second.first;
				step = q.front().second.second;
				// cout << y << x << step << endl;
				// // cout << x-1 << endl;
				// cout << arr[y][x-1] << endl;
				// // cout << visited[y][x-1] << endl;
				q.pop();
				if(y+1<n && res_arr[y+1][x]>step+1 && !visited[y+1][x] && arr[y+1][x]==0)
				{
					visited[y+1][x] = true;
					res_arr[y+1][x] = step+1;
					q.push(make_pair(y+1,make_pair(x,step+1)));
				}
				if(y-1>=0 && res_arr[y-1][x]>step+1 && !visited[y-1][x] && arr[y-1][x]==0)
				{
					visited[y-1][x] = true;
					res_arr[y-1][x] = step+1;
					q.push(make_pair(y-1,make_pair(x,step+1)));
				}
				if(x+1<m && res_arr[y][x+1]>step+1 && !visited[y][x+1] && arr[y][x+1]==0)
				{
					visited[y][x+1] = true;
					res_arr[y][x+1] = step+1;
					q.push(make_pair(y,make_pair(x+1,step+1)));
				}
				if(x-1>=0 && res_arr[y][x-1]>step+1 && !visited[y][x-1] && arr[y][x-1]==0)
				{
					// printf("WAHOO\n");
					visited[y][x-1] = true;
					res_arr[y][x-1] = step+1;
					// printf("%d",res_arr[y][x-1]);
					q.push(make_pair(y,make_pair(x-1,step+1)));
				}
			}
		}
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				if(res_arr[i][j]==999999)
					printf("0 ");
				else
					printf("%d ",res_arr[i][j]);
			}
			printf("\n");
		}

	}
}