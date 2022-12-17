#include <bits/stdc++.h>
using namespace std;
void sorti(int arr[13], int n)
{
	for(int i=1; i<n; i++)
	{
		int j = i;
		while(arr[j]<arr[j-1] && j>0)
		{
			int temp = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] = temp;
			j--;
		}
	}
}
int main()
{
	int a,d;
	int attack[13];
	int defend[13];
	scanf("%d %d",&a,&d);
	while(a!= 0 || d!=0)
	{
		for(int i=0; i<a; i++)
			scanf("%d",&attack[i]);
		for(int i=0; i<d; i++)
			scanf("%d",&defend[i]);
		sort(attack,attack+a);
		sort(defend,defend+d);

		if(attack[0]<defend[1])
			printf("Y\n");
		else
			printf("N\n");
		scanf("%d %d",&a,&d);
	}
}