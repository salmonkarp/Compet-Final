#include <bits/stdc++.h>
using namespace std;
int n;
bool wouldPrefer(int w_pref[505][505], int cur_w, int cur_m, int cur_engage)
{
	int m_loc, eng_loc;
	for(int i=1; i<=n; i++)
	{
		if(w_pref[cur_w][i]==cur_m)
			m_loc = i;
		if(w_pref[cur_w][i]==cur_engage)
			eng_loc = i;
	}
	if(m_loc<eng_loc)
		return true;
	else
		return false;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int w_pref[505][505];
		int m_pref[505][505];
		for(int i=1; i<=n; i++)
		{
			int x;
			scanf("%d",&x);
			for(int j=1; j<=n; j++)
			{
				scanf("%d",&w_pref[x][j]);
			}
		}
		for(int i=1; i<=n; i++)
		{
			int x;
			scanf("%d",&x);
			for(int j=1; j<=n; j++)
			{
				scanf("%d",&m_pref[x][j]);
			}
		}
		// for(int i=1; i<=n; i++)
		// {
		// 	for(int j=1; j<=n; j++)
		// 	{
		// 		printf("%d ",w_pref[i][j]);
		// 	}
		// 	printf("\n");
		// }
		// for(int i=1; i<=n; i++)
		// {
		// 	for(int j=1; j<=n; j++)
		// 	{
		// 		printf("%d ",m_pref[i][j]);
		// 	}
		// 	printf("\n");
		// }
		bool is_m_matched[505];
		int w_partner[505];
		memset(is_m_matched,false,sizeof(is_m_matched));
		memset(w_partner,-1,sizeof(w_partner));
		int matches = n;
		while(matches>0)
		{
			int cur_m;
			for(cur_m=1; cur_m<=n; cur_m++)
			{
				if(is_m_matched[cur_m]==false)
					break;
			}
			// cout << cur_m << endl;
			for(int i=1; i<=n; i++)
			{
				int cur_w = m_pref[cur_m][i];
				// cout << cur_w;
				if(w_partner[cur_w] == -1)
				{
					// cout << "HAPPY";
					w_partner[cur_w] = cur_m;
					is_m_matched[cur_m] = true;
					matches--;
					break;
				}
				else
				{
					int cur_engage = w_partner[cur_w];
					//long check here
					if(wouldPrefer(w_pref,cur_w,cur_m,cur_engage)==true)
					{
						w_partner[cur_w] = cur_m;
						is_m_matched[cur_engage] = false;
						is_m_matched[cur_m] = true;
						break;
					}
				}
			}
		}
		for(int i=1; i<=n; i++)
		{
			printf("%d %d\n",w_partner[i],i);
		}
	}
}