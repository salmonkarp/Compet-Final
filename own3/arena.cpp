#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int x;
		cin >> x;
		int arr[150];
		int min = 300;
		for(int i=0; i<x; i++)
		{
			scanf("%d",&arr[i]);
			if(min>arr[i])
				min = arr[i];
		}
		int counter = 0;
		for(int i=0; i<x; i++)
		{
			if(arr[i]==min)
				counter++;
		}
		cout << x-counter << endl;
	}
}