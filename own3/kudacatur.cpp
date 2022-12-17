#include <bits/stdc++.h>
using namespace std;
int main()
{
	int start_x, start_y, end_x, end_y,x,y,step;
	scanf("%d %d",&start_y,&start_x);
	scanf("%d %d",&end_y,&end_x);

	bool visited[101][101];
	memset(visited,false,sizeof(visited));
	queue<pair<int,pair<int,int> > > q;
	map<pair<int,int>, pair<int,int> > path;

	q.push(make_pair(start_y,make_pair(start_x,0)));
	visited[start_y][start_x] = true;
	int ans = -1;

	while(!q.empty())
	{
		x = q.front().first;
		y = q.front().second.first;
		step = q.front().second.second;
		q.pop();

		if(y+2<=8)
		{
			if(x+1<=8 && !visited[y+2][x+1])
			{
				visited[y+2][x+1] = true;
				path[make_pair(y+2,x+1)] = make_pair(y,x);
				q.push(make_pair(y+2,make_pair(x+1,step+1)));
			}
			if(x-1>0 && !visited[y+2][x-1])
			{
				visited[y+2][x-1] = true;
				path[make_pair(y+2,x-1)] = make_pair(y,x);
				q.push(make_pair(y+2,make_pair(x-1,step+1)));
			}
		}
		if(y-2>0)
		{
			if(x+1<=8 && !visited[y-2][x+1])
			{
				visited[y-2][x+1] = true;
				path[make_pair(y-2,x+1)] = make_pair(y,x);
				q.push(make_pair(y-2,make_pair(x+1,step+1)));
			}
			if(x-1>0 && !visited[y-2][x-1])
			{
				visited[y-2][x-1] = true;
				path[make_pair(y-2,x-1)] = make_pair(y,x);
				q.push(make_pair(y-2,make_pair(x-1,step+1)));
			}
		}
		if(y+1<=8)
		{
			if(x+2<=8 && !visited[y+1][x+2])
			{
				visited[y+1][x+2] = true;
				path[make_pair(y+1,x+2)] = make_pair(y,x);
				q.push(make_pair(y+1,make_pair(x+2,step+1)));
			}
			if(x-2>0 && !visited[y+1][x-2])
			{
				visited[y+1][x-2] = true;
				path[make_pair(y+1,x-2)] = make_pair(y,x);
				q.push(make_pair(y+1,make_pair(x-2,step+1)));
			}
		}
		if(y-1>0)
		{
			if(x+2<=8 && !visited[y-1][x+2])
			{
				visited[y-1][x+2] = true;
				path[make_pair(y-1,x+2)] = make_pair(y,x);
				q.push(make_pair(y-1,make_pair(x+2,step+1)));
			}
			if(x-2>0 && !visited[y-1][x-2])
			{
				visited[y-1][x-2] = true;
				path[make_pair(y-1,x-2)] = make_pair(y,x);
				q.push(make_pair(y-1,make_pair(x-2,step+1)));
			}
		}

		if(x==end_x && y==end_y)
		{
			ans = step;
			break;
		}
	}
	printf("%d\n",ans);
	pair<int,int> index_temp = make_pair(end_y,end_x);
	stack<pair<int,int> > st;
	st.push(make_pair(end_y,end_x));
	while(path[index_temp]!=make_pair(start_y,start_x))
	{
		index_temp = path[index_temp];
		st.push(index_temp);
	}
	st.push(make_pair(start_y,start_x));
	while(!st.empty())
	{
		printf("(%d,%d) ",st.top().first,st.top().second);
		st.pop();
	}
	
}