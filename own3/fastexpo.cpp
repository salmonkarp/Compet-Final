#include <iostream>
#include <cstring>
#define LL long long

using namespace std;
LL arr[10000005];

int fastex(LL base, LL pangkat)
{
	if(pangkat>10000000)
	{
		LL hasil = fastex(base, pangkat / 2);
        hasil = hasil * hasil;
        if (pangkat % 2 !=0)
            hasil = hasil * base;
        return arr[pangkat] = hasil % 10;
	}
	if(arr[pangkat]!=-1)
		return arr[pangkat];
    else if(pangkat == 1)
        return arr[1] = base;
    else
    {
        LL hasil = fastex( base, pangkat / 2);
        hasil = hasil * hasil;
        if (pangkat % 2 !=0)
            hasil = hasil * base;
        return arr[pangkat] = hasil % 10;
    }
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long a,b;
		memset(arr,-1,sizeof(arr));
		scanf("%lld %lld",&a,&b);
		printf("%d\n",fastex(a,b));
	}

}