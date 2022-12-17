#include <iostream>
#define LL long long

using namespace std;

LL arr[500005];

int main(){
	LL temp = 100000007;
	arr[1] = 1;
	arr[2] = 1;
	for(int i=3; i<=500003; i++)
	{
		arr[i] = (arr[i-1] % temp + arr[i-2] % temp) % temp;
	}

	int t;
	scanf("%d",&t);
	for(int i=0; i<t; i++)
	{
		int n;
		scanf("%d",&n);
		printf("%lld\n",arr[n]);
	}
}