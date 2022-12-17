#include <bits/stdc++.h>

using namespace std;

int arr[27][27];
bool visited[27][27]={false};
int score = 0;

void dothings(int tr, int tc, int row, int col)
{
	visited[tr][tc]=true;
	score++;
	if(visited[tr+1][tc]==false && arr[tr][tc] == arr[tr+1][tc] && tr+1<row)
		dothings(tr+1,tc,row,col);
	if(visited[tr-1][tc]==false && arr[tr][tc] == arr[tr-1][tc] && tr-1>=0)
		dothings(tr-1,tc,row,col);
	if(visited[tr][tc+1]==false && arr[tr][tc] == arr[tr][tc+1] && tc+1<col)
		dothings(tr,tc+1,row,col);
	if(visited[tr][tc-1]==false && arr[tr][tc] == arr[tr][tc-1] && tc-1>=0)
		dothings(tr,tc-1,row,col);
}

int main()
{
	int row,col;
	scanf("%d %d",&row,&col);
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	int tr, tc;
	scanf("%d %d",&tr,&tc);
	
	dothings(tr,tc,row,col);
	printf("%d",score*(score-1));
}