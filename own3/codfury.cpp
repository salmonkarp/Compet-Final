#include <bits/stdc++.h>
#define LL long long

using namespace std;
LL planet_no,max_bots;
LL arr[50005];
pair<LL,LL> funct()
{
	LL finalSum = 1000001;
	LL finalPlanets = 0;
	LL tempSum = 0;
	LL start = 0;
	LL counter = 0;
	for(LL i=0; i<planet_no; i++)
	{
		tempSum += arr[i];
		counter++;
		while(tempSum > max_bots)
		{
			tempSum-=arr[start];
			counter--;
			start++;
		}
		if(finalPlanets < counter)
		{
			finalPlanets = counter;
			finalSum = tempSum;
		}
		else if(finalPlanets == counter && finalSum>tempSum)
			finalSum = tempSum;
	}
	return make_pair(finalSum,finalPlanets);
}

int main()
{
	LL t;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&planet_no,&max_bots);
		for(LL i=0; i<planet_no; i++)
		{
			scanf("%lld",&arr[i]);
		}
		pair<LL,LL> res = funct();
		printf("%lld %lld\n",res.first, res.second);
	}
}