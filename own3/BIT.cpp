/*
binary indexed tree membutuhkan pengertian Two Compliment Number (bilangan komplemen dua)

https://www.cs.cornell.edu/~tomf/notes/cps104/twoscomp.html

Example 2
Now suppose we want to subtract 12 from 69. Now, 69 - 12 = 69 + (-12). To get the negative of 12 we take its binary representation, invert, and add one.

0000 0000 0000 0000 0000 0000 0000 1100
Invert the digits.

1111 1111 1111 1111 1111 1111 1111 0011
And add one.

1111 1111 1111 1111 1111 1111 1111 0100
The last is the binary representation for -12. As before, we'll add the two numbers together.

  1111 1111 1111 1111 1111 1111 1    1   Carry Row
  0000 0000 0000 0000 0000 0000 0100 0101 (69)
+ 1111 1111 1111 1111 1111 1111 1111 0100 (-12)
------------------------------------------------
  0000 0000 0000 0000 0000 0000 0011 1001 (57)
  
  http://www.convertforfree.com/twos-complement-calculator/

*/
#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL tree[10005];
LL MaxVal;

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
	int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(tree,0,sizeof(tree));
        LL n,u,l,r,val,q,temp;
        scanf("%lld %lld",&n,&u);
        MaxVal = n+5;
        for(LL i=0; i<u; i++)
        {
            scanf("%lld %lld %lld",&l,&r,&val);
            update(l+1,val);
            update(r+2,-val);
        }
        scanf("%lld",&q);
        for(LL j=0; j<q; j++)
        {
            scanf("%lld",&temp);
            printf("%lld\n",read(temp+1));
        }
        
    }
}
