#include <bits/stdc++.h>
#define LL long long

using namespace std;
LL arr[10000005];
LL modulo = 1000000007;


LL modex(LL b, LL e)
{
	if(e>10000000)
	{
		LL hasil = modex(b, e / 2, modulo);
        hasil = (hasil * hasil) % modulo;
        if (e % 2 !=0)
            hasil = ((hasil%m) * (b%m)) % modulo;
        return (hasil%m) % m;
	}
	if(arr[e]!=-1)
		return arr[e];
	if (e == 0)
		return 1;
    else if(e == 1)
        return b % m;
    else
    {
        long long hasil = modex(b, e/2, m);
        hasil = ((hasil%m) * (hasil%m)) % m;
        if (e % 2 != 0)
            hasil = ((hasil%m) * (b%m)) % m;
        return arr[e] = (hasil%m) % m;
    }
}
int main()
{
	LL n,l;
	scanf("%lld %lld",&n,&l);
	while(n!=0 && l!=0)
	{
		LL res = 0;
		memset(arr,-1,sizeof(arr));
		for(int i=1; i<=l; i++)
		{
			if(arr[i]!=-1)
			{
				res += arr[i] % modulo;
				res = res % modulo;
				// printf("%lld\n",arr[i]);
			}
			else
			{
				arr[i] = modex(n,i,modulo) % (modulo);
				res += arr[i];	
				res = res % modulo;
				// printf("%lld\n",arr[i]);
			}
		}
		printf("%lld\n",res);
		scanf("%lld %lld",&n,&l);
	}
}