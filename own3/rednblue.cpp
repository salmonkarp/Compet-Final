#include <bits/stdc++.h>
#define LL long long
using namespace std;

int summate(int arr[200],int lent)
{
	int temp = 0;
	int max = 0;
	for(int i=0; i<lent; i++)
	{
		temp += arr[i];
		if(max<temp)
			max = temp;
	}
	return max;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,m;
		cin >> n;
		int arr1[200];
		for(int i=0; i<n; i++)
		{
			scanf("%d",&arr1[i]);
		}
		int arr2[200];
		cin >> m;
		for(int i=0; i<m; i++)
		{
			scanf("%d",&arr2[i]);
		}
		int m_arr1 = summate(arr1,n);
		int m_arr2 = summate(arr2,m);
		cout << m_arr2 + m_arr1 << endl;
	}
}