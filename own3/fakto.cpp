#include <iostream>
#include <algorithm>
#define LL long long

using namespace std;


int fakto(int n)
{
	if(n == 1)
	{
		return 1;
	}
	if(n%2==0)
	{
		return (n/2) * fakto(n-1);
	}
	else
	{
		return n * fakto(n-1);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	printf("%d",fakto(n));
}