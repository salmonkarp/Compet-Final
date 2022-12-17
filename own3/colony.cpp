#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
	int y;
	LL p;
	scanf("%d %lld",&y,&p);
	p++;
	LL length = (LL)pow(2,y);

	LL left = 1;
	LL right = length;
	LL counter = 0;
	while(left<right)
	{
		LL mid = (left+right) / 2;
		if(p<=mid)
		{
			right = mid;
			counter++;
		}
		else
		{
			left = mid+1;
		}
	}
	if(counter%2==1)
		printf("blue");
	else
		printf("red");
}