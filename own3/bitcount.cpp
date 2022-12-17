#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t=0,res=0 ;
	scanf("%d",&t);
	while(t>0)
	{
		res += t & 1;
		// cout << res << endl;
		t = t>>1;
	}
	cout << res << endl;
}