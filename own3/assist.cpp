#include <bits/stdc++.h>

using namespace std;

long long prime[3030]; // untuk collect prime number nya
bool bo[5000000]; // false = bukan prime

int main()
{
	memset(bo,true,sizeof(bo));
	//#1 generate
	for(int a=2;a<=35000;a++)
	{
		if(bo[a]==false)
			continue;
		int counter = 0;
		// printf("a:%d\n",a);
		for(int b=a+1;b<=35000;b++)
		{
			if(bo[b]==false)
				continue;
			counter++;
			if(counter==a)
			{
				bo[b]=false;
				counter=0;
				// printf("make false:%d\n",b);
			}
		}
	}


	long long counter2=1;
	//#2 collect / mengumpulkan ke dalam array prime
	for(int i=2; i<35000; i++)
	{
		if(bo[i]==true)
		{
			prime[counter2]=i;
			counter2++;
		}
	}
	int n;
	scanf("%d",&n);
	while(n!=0)
	{		
		//#3 menjawab pertanyaan soal
		printf("%lld\n",prime[n]);
		scanf("%d",&n);
	}
}