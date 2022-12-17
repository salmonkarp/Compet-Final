#include <bits/stdc++.h>
#define LL long long

using namespace std;
LL arr[10000005];

LL mod_ex(LL b, LL e, LL m)
{
	if(e>10000000) //incase of big, just do normally without memo
	{
		LL hasil = mod_ex(b, e / 2, m);
        hasil = ((hasil%m) * (hasil%m)) % m;
        if (e % 2 !=0)
            hasil = ((hasil%m) * (b%m)) % m;
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
        long long hasil = mod_ex(b, e/2, m);
        hasil = ((hasil%m) * (hasil%m)) % m;
        if (e % 2 != 0)
            hasil = ((hasil%m) * (b%m)) % m;
        return arr[e] = (hasil%m) % m;
    }

}

int main()
{
	int t;
	scanf("%d",&t);
	int counter=1;
	while(t--)
	{
		LL b,e,m;
		memset(arr,-1,sizeof(arr));
		scanf("%lld %lld %lld",&b,&e,&m);
		printf("%d. %lld\n",counter,mod_ex(b,e,m));
		counter++;
	}
}