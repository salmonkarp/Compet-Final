#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL tree[100005];
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
	LL n,id1,id2;
	LL ans = 0;
	scanf("%lld",&n);
	pair<string,LL> arr[n+5];
	pair<string,LL> arr2[n+5];
	LL rev[n+5];
	for(LL i=1; i<=n; i++)
	{
		cin >> arr[i].first;
		update(i,1);
	}
	sort(arr+1,arr+n+1);
	for(LL i=1; i<=n; i++)
	{
		arr[i].second = i;
		arr2[i] = arr[i];
		reverse(arr2[i].first.begin(),arr2[i].first.end());
	}
	sort(arr2+1,arr2+n+1);
	for(LL i=1; i<=n; i++)
	{
		rev[arr2[i].second] = i;
	}
	for(LL i=1; i<=n; i++)
	{
		update(rev[i],-1);
		LL temp = read(rev[i]);
		ans += temp;
	}
	printf("%lld",ans);
}