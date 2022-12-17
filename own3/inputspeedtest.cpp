#include <iostream>

using namespace std;

int main() 
{ 
    long n, k;
    scanf("%ld",&n);
    scanf("%ld",&k);
    long counter=0;
    for(long i=0; i<n; i++)
    {
    	long temp = 0;
    	scanf("%ld",&temp);
    	if(temp%k==0){
    		counter++;
    	}
    }
    printf("%ld",counter);
}