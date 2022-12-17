#include <bits/stdc++.h>

using namespace std;

long long prime[1000000]; // untuk collect prime number nya
bool bo[1000001]; // false = bukan prime

int main()
{
	memset(bo,true,sizeof(bo));
	//#1 generate
	for(int a=2;a<=1000000;a++)
	{
		for(int b=2;b<=1000000;b++)
		{
			if(a*b>1000000) //firewall
				break;
				
			bo[a*b]=false;
		}
	}
	long long counter=1;

	//#2 collect / mengumpulkan ke dalam array prime
	for(int i=2; i<1000001; i++)
	{
		if(bo[i]==true)
		{
			prime[counter]=i;
			// printf("%lld",prime[counter]);
			counter++;
		}
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		//#3 menjawab pertanyaan soal
		printf("%lld\n",prime[n]);
	}
}