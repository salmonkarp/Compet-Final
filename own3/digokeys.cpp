#include <bits/stdc++.h>

using namespace std;
int t,n,temp1,temp2,x,y;
string step;
int arr[10005][10005];
int path[100005];
bool visited[100005];

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(arr,false,sizeof(arr));

		//IO
		for(int i=1; i<=n-1; i++)
		{
			scanf("%d",&temp1);
			arr[i][0] = temp1;
			for(int j=1; j<=temp1; j++)
			{
				scanf("%d",&temp2);
				arr[i][j] = temp2; 
				//there is a path from i to temp2
			}
		}

		// for(int i=1; i<=n; i++)
		// {
		// 	for(int j=0; j<=arr[i][0]; j++)
		// 	{
		// 		printf("%d ",arr[i][j]);
		// 	}
		// 	printf("\n");
		// }
		//iterate based on starting points
		memset(visited,false,sizeof(visited));
		memset(path,-1,sizeof(path));
		queue<int> q;
		q.push(1);
		visited[1]= true;
		bool is_found = false;
		while(!q.empty())
		{
			y = q.front();
			// cout << y << x << step << endl;
			q.pop();
			int temp4 = arr[y][0];
			sort(arr[y]+1,arr[y]+arr[y][0]+1);
			for(int j=1; j<=temp4; j++)
			{
				x = arr[y][j];
				if(!visited[x])
				{
					// printf("next go to: %d %d\n",x,j);
					visited[x]=true;
					path[x] = y;
					q.push(x);
				}
			}
			if(y==n)
			{
				is_found = true;
				break;
			}
		}
		// for(int i=1; i<n; i++)
		// {
		// 	printf("%d ",path[i]);
		// }

		if(is_found==false)
		{
			cout << -1 << endl << endl;
			continue;
		}
		stack<int> final_path;
		int index_temp = path[n];
		int counter = 0;
		while(index_temp!=-1)
		{
			final_path.push(index_temp);
			index_temp = path[index_temp];
			counter++;
		} 
		cout << counter << endl;
		while(!final_path.empty())
		{
			cout << final_path.top() << ' ';
			final_path.pop();
		}
		cout << endl << endl;
	}
}