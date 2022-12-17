#include <iostream>
#define LL long long
using namespace std;
int n;
LL arr[300005];
LL temp;
int main(){
	scanf("%d %d",&n,&k);
	for(int i=0; i<=n; i++)
	{
		scanf("%d",arr[i]);
	}
	LL left = 1;
	LL right = 2*inf;
	while(left<right)
	{
		LL mid = (left + right)/2;
		if(left==mid)
			mid++;
		LL temp = 0;
		for(int i=0; i<=n; i++)
		{
			temp += max(0,mid-arr[i]);
		}
		if(temp<=k)
			left = mid;
		else
			right = mid-1;
	}
}