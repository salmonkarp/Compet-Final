#include <bits/stdc++.h>
#define LL long long
using namespace std;
 
int main() {
    int t; 
    scanf("%d",&t);
    while(t--)
    {
        LL n,i;
        scanf("%lld",&n);
        LL arr[n];
        LL min=100001;
        for(LL i=0;i<n;i++)
        {
            scanf("%lld",&arr[i]);
            if(min>arr[i]) 
                min=arr[i];
        }
        printf("%lld\n",min*(n-1));
    }
}