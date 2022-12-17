#include <bits/stdc++.h>

using namespace std;

int arr[13];

void printout(int arr[13], int n)
{
	for(int i=1; i<=n; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}

void permute(int cur, int n, int k){
	if(cur>k)
	{
		printout(arr,k);
	}
	else
	{
		for(int i=arr[cur-1]+1; i<=n; i++)
		{
			arr[cur] = i;
			permute(cur+1,n,k);
		}

	}
}

int main()
{
	int n,k;
	cin >> n >> k;
	permute(1,n,k);
}