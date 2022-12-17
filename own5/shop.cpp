#include <bits/stdc++.h>
#define LL long long

using namespace std;
int w,h,ai,bi,ci,new_y,new_x;
char arr[30][30];
priority_queue<pair<LL,pair<LL,LL> > > djik;
bool visited[30][30];

void doStufff(int row, int col, int dist)
{
	if(arr[row][col]=='D')
	{
		djik.push(make_pair(-dist,make_pair(row,col)));
		// printf("%d %d %d\n",dist,row,col);
	}
	else if(arr[row][col]!='X' && row>=1 && row<=h && col>=1 && col <=w && visited[row][col]==false)
	{
		int new_dist = dist + arr[row][col] - 48;
		// printf("%d\n",arr[row][col]-48);
		djik.push(make_pair(-new_dist,make_pair(row,col)));
		// printf("%d %d %d\n",new_dist,row,col);
	}
}

int main()
{
	scanf("%d %d",&w,&h);
	while(w!=0 && h!=0)
	{
		while(!djik.empty())
			djik.pop();
		memset(arr,'X',sizeof(arr));
		memset(visited,false,sizeof(visited));
		// djik.pop();
		for(int i=1; i<=h; i++)
		{
			for(int j=1; j<=w; j++)
			{
				cin >> arr[i][j];
				// printf("%c",arr[i][j]);
				if(arr[i][j]=='S')
				{
					djik.push(make_pair(0,make_pair(i,j)));
					// cout << djik.top().first << djik.top().second.first << djik.top().second.second << endl;
				}
			}
		}
		LL final_cost = 0;
		while(arr[djik.top().second.first][djik.top().second.second] != 'D')
		{
			LL dist = -djik.top().first;
			LL y = djik.top().second.first;
			LL x = djik.top().second.second;
			// cout << "cur:"<<dist << y << x << endl;
			djik.pop();
			

			visited[y][x] = true;

			new_y = y-1, new_x = x;
			doStufff(new_y,new_x,dist);
			new_y = y+1, new_x = x;
			doStufff(new_y,new_x,dist);
			new_y = y, new_x = x+1;
			doStufff(new_y,new_x,dist);
			new_y = y, new_x = x-1;
			doStufff(new_y,new_x,dist);

		}
		printf("%d\n",-djik.top().first);
		scanf("%d %d",&w,&h);
	}
}