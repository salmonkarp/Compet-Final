//2.55
#include <iostream>

using namespace std;
int main() 
{ 
	// added the two lines below 
	// ios_base::sync_with_stdio(false); 
	// cin.tie(NULL); 

	long n, k; 
	cin >> n >> k;
	long counter=0;
	for(long i=0; i<n; i++)
	{
		long temp;
		cin>>temp;
		if(temp%k==0)
		{
			counter++;
		}
	}
	cout<<counter;
}