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
	while(t--)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		int counter = 0;
		for(int i=0; i<n; i++)
		{
			printf("TEST1");
			string s;
			cin >> s;
			for(int j=0; j<m; j++)
			{
				arr[i][j] = int(s[j])-48;
				cout<<arr[i][j];
				if(arr[i][j]==1)
				{
					starts[counter] = make_pair(i,j);
					counter++;
				}
			}
			cout << "TEST2, counter:" << counter<<endl;
		}

		//something weird around here
		printf("TEST3\n");
		printf("TEST4\n");
		queue<pair<int,pair<int,int> > > q;
		for(int i=0; i<counter; i++)
		{
			q.push(make_pair(starts[i].first,make_pair(starts[i].second,0)));
			memset(visited,false,sizeof(visited));
			memset(res_arr,9999999,sizeof(res_arr));
			while(!q.empty())
			{
				y = q.front().first;
				x = q.front().second.first;
				step = q.front().second.second;
				if(y+1<n && res_arr[y+1][x]>step+1 && !visited[y+1][x])
				{
					visited[y+1][x] = true;
					q.push(make_pair(y+1,make_pair(x,step+1)));
				}
				if(y-1>=0 && res_arr[y-1][x]>step+1 && !visited[y-1][x])
				{
					visited[y-1][x] = true;
					q.push(make_pair(y-1,make_pair(x,step+1)));
				}
				if(x+1<m && res_arr[y][x+1]>step+1 && !visited[y][x+1])
				{
					visited[y][x+1] = true;
					q.push(make_pair(y,make_pair(x+1,step+1)));
				}
				if(x-1>=0 && res_arr[y][x-1]>step+1 && !visited[y][x-1])
				{
					visited[y][x-1] = true;
					q.push(make_pair(y,make_pair(x-1,step+1)));
				}
			}
		}
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				printf("%d ",res_arr[i][j]);
			}
			printf("\n");
		}

	}
}