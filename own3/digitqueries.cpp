#include <bits/stdc++.h>
using namespace std;

int main(){
	int q;
	cin >> q;
	for(int i=0; i<q; i++)
	{
		long k;
		cin >> k;
		long temp = k;
		long counter = 0;
		if(k<10)
			cout << k;

		while(temp - (9*pow(10,counter)*(counter+1)) > 0){
			temp -= (9*pow(10,counter)*(counter+1));
			counter++;
		}
		counter++;

		bsearch(k,counter);
		long low = pow(10,counter-1);
		long high = pow(10, counter);
		
		while(low<=high)
		{
			midpoint = (low + high) / 2;
			midpoint -= pow(10,counter-1);
		midpoint = midpoint * counter;
		midpoint += pow(10,counter-1);
		}
		
		if(midpoint==k)
		{
			cout << temp/pow(10,counter-1);
		}
		else if(midpoint+1==k)
		{
			cout << temp%pow(10,counter-1);
		}
		else if(midpoint+1<k)
		{

		}
		else
		{

		}
	}
}