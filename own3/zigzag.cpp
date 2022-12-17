#include <bits/stdc++.h>

using namespace std;

int arr[13];
bool visited[13] = {false};

void printout(int arr[100], int n)
{
	string x="";
	bool dothing = true;
	for(int i=2; i<=n-1; i++)
	{
		bool cond1 = (arr[i]<arr[i-1]) && (arr[i]<arr[i+1]);
		bool cond2 = (arr[i]>arr[i-1]) && (arr[i]>arr[i+1]);
		if(!(cond1||cond2))
			dothing = false;
	}
	if(dothing == true)
	{
		for(int i=1; i<=n; i++)
		{
			cout << arr[i];
		}
		cout << endl;
	}
}

void permute(int cur, int n){
	if(cur>n)
	{
		printout(arr,n);
	}
	else
	{
		for(int i=1; i<=n; i++)
		{
			if(visited[i]!=true)
			{
				visited[i] = true;
				arr[cur] = i;
				permute(cur+1,n);
				visited[i] = false;
			}

		}

	}
}

int main()
{
	int n;
	cin >> n;
	permute(1,n);
}