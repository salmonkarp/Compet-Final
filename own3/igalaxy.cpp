#include <bits/stdc++.h>
#include <map>

using namespace std;
int t;
int main()
{
	scanf("%d",&t);
	for(int r=1; r<=t; r++)
	{
		int n;
		string temp1;
		string temp2;
		int cur,step;
		int path[10005];
		int visited[10005];
		map<string,int> arr;
		map<int,string> rev_arr;
		queue<pair<int,int> > q;
		scanf("%d",&n);
		vector<int > bus[10005];
		//IO
		int counter = 1;
		for(int i=1; i<=n; i++)
		{
			cin >> temp1;
			cin >> temp2;
			if(arr.count(temp1)!=1)
			{
				arr[temp1] = counter;
				rev_arr[counter] = temp1;
				counter++;
			}
			if(arr.count(temp2)!=1)
			{
				arr[temp2] = counter;
				rev_arr[counter] = temp2;
				counter++;
			}
			bus[arr[temp1]].push_back(arr[temp2]);
			bus[arr[temp2]].push_back(arr[temp1]);
		}
		// for (map<string,int>::iterator saya = arr.begin();  saya != arr.end(); ++saya)
		// cout << saya->first << " => " << saya->second << '\n';

		string start,end;
		cin >> start;
		cin >> end;
		int r_start = arr[start];
		int r_end = arr[end];
		q.push(make_pair(0,r_start));
		// cout << start << arr[start] << endl;
		// cout << end << arr[end] << endl;
		memset(path,-1,sizeof(path));
		memset(visited,false,sizeof(visited));

		int ans = -1;
		bool is_found = false;
		while( !q.empty() )
		{
			cur = q.front().second;
			step = q.front().first;
			// printf("%d:",cur);
			// printf("current(%d) step(%d)\n",cur,step);
			q.pop();

			vector<string> dummy;

			for(int i=0; i<bus[cur].size(); i++)
			{
				int dest = bus[cur][i];
				// printf("%d",dest);

				if(visited[dest]==false)
				{
					string tempx = rev_arr[dest];
					dummy.push_back(tempx);
					// printf("planet connected:%d\n",dest);
				}
			}
			// cout << "CUCUMBER" << endl;
			sort(dummy.begin(),dummy.end());
			for(int i=0; i<dummy.size(); i++)
			{
				int dest = arr[dummy[i]];
				q.push(make_pair(step+1,dest));
				path[dest] = cur;
				visited[dest] = true;
				
			}
			// printf("\n");
			//cek apakah sudah berada di posisi pintu keluar
			if(cur == arr[end])
			{
				ans = step+1;
				is_found = true;
				break;
			}
		}
		if(is_found==false)
		{
			printf("Scenario #%d: -1\n\n",r);
			continue;
		}
		printf("Scenario #%d: %d\n",r, ans);
		// for(int i=1; i<counter; i++)
		// {
		// 	printf("%d ",path[i]);
		// }
		// printf("\n");

		stack<int> final_path;
		int index_temp = path[arr[end]];
		int counter2 = 0;
		while(index_temp!=arr[start])
		{
			final_path.push(index_temp);
			index_temp = path[index_temp];
			counter2++;
		} 
		// printf("Ordered Path:\n");
		cout << start << ' ';
		while(!final_path.empty())
		{
			cout << rev_arr[final_path.top()] << ' ';
			final_path.pop();
		}
		cout << end << endl << endl;
	}
}