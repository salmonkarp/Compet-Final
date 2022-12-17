#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;
bool arr[130][130]={false};
void testprint(bool arr[130][130], int size);
string ans[17000];
int counter=0;

int check_filled(bool arr[130][130], int size, int row, int col) 
//helper to check
{
	bool is_all_zero = true;
	bool is_all_one = true;
	for(int i=row; i<row+size; i++)
	{
		for(int j=col; j<col+size; j++)
		{
			if(arr[i][j]==0)
				is_all_one = false;
			if(arr[i][j]==1)
				is_all_zero = false;
		}
	}
	if(!(is_all_zero || is_all_one))
		return 2; //if it is not homog
	else if(is_all_one)
		return 1;
	else
		return 0;
}

void dothings(bool arr[130][130], int size, int row, int col, string codex)
{
	int x = check_filled(arr,size,row,col);
	// cout << size << " " << row << " " << col << " " << codex << " " << x << endl;
	if(x==1) // if everything is 1
	{
		//add to answer
		ans[counter] = "1" + codex;
		counter++;
	}
	else if(x==2) // if not homog
	{
		//split further
		dothings(arr,size/2,row,col,codex+"0");
		dothings(arr,size/2,row,col+(size/2),codex+"1");
		dothings(arr,size/2,row+(size/2),col,codex+"2");
		dothings(arr,size/2,row+(size/2),col+(size/2),codex+"3");
	}
	//if all zero should do nothing
}

int fit_size(int r, int c) //helper to make array in size 2^p 
{
	int maxi = max(r,c);
	int res = 1;
	while(res<maxi)
	{
		res*=2;
	}
	return res;
}

int main()
{
	int r,c;
	scanf("%d %d",&r,&c);
	int initial_size = fit_size(r,c);

	//IO
	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	// testprint(arr,initial_size);

	dothings(arr,initial_size,0,0,"");
	printf("%d\n",counter);
	for(int i=0; i<counter; i++)
	{
		cout << ans[i] << endl;
	}
}



//debug stuff
void testprint(bool arr[130][130], int size)
{
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}