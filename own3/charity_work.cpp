#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
	LL n,m,k;
	scanf("%lld %lld %lld",&n,&m,&k);
	LL res = lcm(n,lcm(m,k));
	LL res2 = res / n;
	LL res3 = res / m;
	LL res4 = res / k;
	LL resa = res / lcm(n,m);
	LL resb = res / lcm(m,k);
	LL resc = res / lcm(n,k);
	LL resfi = res - res2 - res3 - res4 + resa + resb + resc - 1;
	printf("%lld %lld\n",res,resfi);

}