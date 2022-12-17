#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	for(int hk=1; hk<=t; hk++)
	{
		bool is_gay = false;
		int bug_no, intr_no,bug1,bug2;
		scanf("%d %d",&bug_no,&intr_no);
		vector<int> arr[bug_no+5];
		for(int i=1; i<=intr_no; i++)
		{
			scanf("%d %d",&bug1,&bug2);
			arr[bug1].push_back(bug2);
			arr[bug2].push_back(bug1);
		}
		queue<int> q;
		int genders[bug_no+5];
		memset(genders,0,sizeof(genders));
		
		for(int i=1; i<=bug_no; i++)
		{
			if(genders[i]==0)
			{
				q.push(i);
				genders[i]=1;
				while(!q.empty() && is_gay==false)
				{
					int x = q.front();
					q.pop();
					for(int j=0; j<arr[x].size();j++)
					{
						int cur = arr[x][j];
						if(genders[cur]==0)
						{
							genders[cur] = -genders[x];
							q.push(cur);
						}
						else if(genders[cur]==genders[x])
						{
							is_gay = true;
							break;
						}
					}
				}
			}
		}
		printf("Scenario #%d:\n",hk);
		if(is_gay==false)
			printf("No suspicious bugs found!\n");
		else
			printf("Suspicious bugs found!\n");
		
	}
}