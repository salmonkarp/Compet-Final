#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	for(int hk=1; hk<=t; hk++)
	{
		int a, b;
		scanf("%d %d",&a,&b);
		double small_r = double(a), big_r = double(b);
		double res = 0;
		res += small_r + big_r;
		double temp1 = double(pow(big_r+small_r,2)) - double(small_r*small_r);
		double temp2 = double(small_r*small_r) / 3.0;
		double temp3 = sqrt(temp1-temp2);
		res += temp3;
		printf("Case #%d: %f\n",hk,res);
	}
}