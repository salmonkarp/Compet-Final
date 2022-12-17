#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	int batas;
	printf("Batas array = ");
	scanf("%d", &batas);
	
	int arr[batas+1];
	printf("isi array sebelum sort : \n");
	for( int i=1;i <=batas; i++)
	{
		arr[i] = rand()%10 + 1;
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	for( int i=1;i <=batas; i++)
	{
		int min=i;
		for(int j=i+1;  j<=batas; j++)
			if(arr[j] < arr[min]) 
				min=j; //find min value
		
		//swapping
		int temp = arr[i];
		arr[i] = arr[min];
		arr[min]=temp;
	}
	
	printf("isi array SETELAH sort : \n");
    for( int i=1;i <=batas; i++)
        printf("%d ", arr[i]);
	printf("\n");
   
}
