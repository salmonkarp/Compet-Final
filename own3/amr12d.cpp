#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string s;
		cin >> s;
		int length = s.length();
		if(length==1)
			printf("YES\n");
		for(int i=0; i<length/2; i++)
		{
			if(s[i]!=s[length-i-1])
			{
				printf("NO\n");
				break;
			}
			if(i==(length/2)-1)
				printf("YES\n");
		}
	}
}