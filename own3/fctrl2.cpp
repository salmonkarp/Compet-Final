#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0; i<t; i++)
	{
		int num,num_c,counter_2;
		scanf("%d",&num);
		num_c = num;
		LL res = 1;
		int arr[200];
		memset(arr,0,sizeof(arr));
		int counter = 0;
		while(num_c>0)
		{
			arr[counter] = num_c % 10;
			num_c = num_c/10;
			counter++;
		}
		// printf("%d %d\n",num,counter);
		counter_2 = 0;
		int temp;
		for(int i=2; i<num; i++)
		{
			int transfer = 0;
			int j;
			for(j=0; j<counter+counter_2; j++)
			{
				temp = (arr[j] * i) + transfer;
				arr[j] = temp % 10;
				transfer = temp / 10;
				// printf("%d %d %d %d\n",i,j,arr[j],transfer);
			}
			while(transfer>0)
			{
				arr[j] = transfer % 10;
				transfer = transfer / 10;
				j++;
				counter_2++;
			}
		}
		for(int i=counter+counter_2-1; i>=0; i--)
		{
			printf("%d",arr[i]);
		}
		printf("\n");
	}
}