#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
	int n,b;
	scanf("%d %d",&n,&b);
	int arr[20005];
	for(int i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+n);
	int temp = 0;
	int counter = 0;
	while(temp<b)
	{
		temp+=arr[n-counter-1];
		counter++;
	}
	printf("%d\n",counter);
}