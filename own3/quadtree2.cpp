#include <bits/stdc++.h>

using namespace std;
string ans[17000];
bool arr[130][130]={false};
int counter=0;

void dothings(bool arr[130][130], string codex, int size, int row, int col)
{
	if(codex.size()>0)
	{
		string mod_codex = codex.substr(1,codex.size()-1);
		if(codex[0]=='0')
			dothings(arr,mod_codex,size/2,row,col);
		else if(codex[0]=='1')
			dothings(arr,mod_codex,size/2,row,col+(size/2));
		else if(codex[0]=='2')
			dothings(arr,mod_codex,size/2,row+(size/2),col);
		else
			dothings(arr,mod_codex,size/2,row+(size/2),col+(size/2));
	}
	else
	{
		//fill in the specified part of the array
		for(int i=row; i<row+size; i++)
		{
			for(int j=col; j<col+size; j++)
			{
				arr[i][j]=1;
			}
		}
	}
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
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		string x;
		cin >> x;
		ans[counter] = x;
		counter++;
	}
	int row, col;
	scanf("%d %d",&row,&col);
	// cout << counter << endl;
	int initial_size = fit_size(row,col);
	for(int i=0; i<counter; i++)
	{
		// cout << ans[i] << endl;
		string tobesent = ans[i].substr(1,ans[i].size()-1);
		// cout << tobesent << endl;
		dothings(arr,tobesent,initial_size,0,0);
	}
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}