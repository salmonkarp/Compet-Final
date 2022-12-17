#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL MOD = 1000000007;
LL fastex(LL base, LL pangkat)
{
    if(pangkat == 1)
        return base % MOD;
    else if(pangkat==0)
    	return 1;
    else
    {
        LL hasil = fastex( base, pangkat / 2);
        hasil = (hasil%MOD * hasil%MOD) % MOD;
        if (pangkat % 2 !=0)
            hasil = (hasil%MOD * base%MOD) % MOD;
        return hasil;
    }
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		LL n;
		scanf("%lld",&n);
		LL base;
		if(n<3)
			base = n;
		else if(n%3==0)
			base = fastex(3,n/3) % MOD;
		else if(n%3==1)
			base = (fastex(3,n/3 -1) * 4) % MOD;
		else if(n%3==2)
			base = (fastex(3,n/3) * 2) % MOD;
		printf("%lld\n",base);
	}
}
