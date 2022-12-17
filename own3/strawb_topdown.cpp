#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int memo[1005][1005];
int arr[1005];
int n,k;
//www.spoj.com/problems/STRAWB
/*
Sample Input:

3

7 2

1 1 1 1 1 1 0



7 2

3 2 1 3 2 1 0



7 1

7 6 5 4 3 2 0



Sample Output:

Scenario #1:

Teresa will skip 4 strawberries

Scenario #2:

Teresa will skip 0 strawberries

Scenario #3:

Teresa will skip all the strawberries



Explanation of the second sample test:

Teresa takes the first strawberry at the 1st tile, moves 3 tiles to the right (4th tile), then she grabs the strawberry (3) and moves 3 more tiles, arriving then to the tile 7 where is the pot.
*/
int straw(int id,int ambil){
	if (id==n-1)
		return 0;
	else if (memo[id][ambil]!=-1)
		return memo[id][ambil];
	else if(ambil==0){
		return memo[id][ambil]=straw(id+1,ambil)+1;
	}
	else {
		if (arr[id]+id<n)
			return memo[id][ambil]=min(straw(id+arr[id],ambil-1),straw(id+1,ambil)+1);
		else
			return memo[id][ambil]=straw(id+1,ambil)+1;
	}

}
int main(){
	int t;
	scanf("%d",&t);
	for (int u=0;u<=t-1;u++){
		scanf("%d%d",&n,&k);
		for (int i=0;i<=n-1;i++){
			for (int j=0;j<=k;j++){
				memo[i][j]=-1;
			}
		}


		for (int i=0;i<=n-1;i++){
			scanf("%d",&arr[i]);
		}
		int y=straw(0,k);
		if(y<n-1)
			printf("Scenario #%d:\nTeresa will skip %d strawberries\n",u+1,y);
		else
			printf("Scenario #%d:\nTeresa will skip all the strawberries\n",u+1);

		//print memo
		for (int i=0;i<=n-1;i++){
			for (int j=0;j<=n-1;j++){
				printf("%d ",memo[i][j]);
			}
			printf("\n");
		}
        
	}

	return 0;
}