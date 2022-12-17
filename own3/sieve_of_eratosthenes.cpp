#include<bits/stdc++.h>
using namespace std;
long long prime[1000000]; // untuk collect prime number nya
bool bo[1000001]; // false = bukan prime


/*Sieve of Eratosthenes*/
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
	
	//#2 collect / mengumpulkan ke dalam array prime
	
	//#3 menjawab pertanyaan soal
	
}
