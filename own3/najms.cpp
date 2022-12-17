#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL tree[100005];
LL subtr[100005];
LL MaxVal = 100005;
void update(LL idx ,LL val){
    while (idx <= MaxVal){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

LL read(LL idx){
    LL sum = 0;
    while (idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
int main()
{
	LL t;
	scanf("%lld",&t);
	for(LL hk=1; hk<=t; hk++)
	{
		printf("Case %d:\n",hk);
		memset(tree,0,sizeof(tree));
		memset(subtr,0,sizeof(subtr));
		LL n,q,temp;
		scanf("%lld %lld\n",&n,&q);
		for(LL i=1; i<=n; i++)
		{
			scanf("%lld",&temp);
			update(i,temp);
			update(i+1,-temp);
		}
		for(LL i=0; i<q; i++)
		{
			char x;
			LL aa,ab,valx;
			scanf(" %c %lld",&x,&aa);
			if(x=='w')
			{
				scanf("%lld %lld",&ab,&valx);
				update(aa,valx);
				update(ab+1,-valx);
			}
			if(x=='f')
				printf("%lld\n",read(aa)-subtr[aa]);
			if(x=='m')
			{
				subtr[aa] = read(aa);
			}
		}
		printf("\n");
	}
}