#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 5e+5;
int n, k;
int arr[N];
 
void doStuff() 
{
	sort(arr+1, arr+n+1);
	int temp = k;
	int first = arr[1];
	for(int i=2; i<=n; i++) {
		if((arr[i] - first) * (LL)(i - 1) <= k) {
			k -= (arr[i] - first) * (i - 1); 
			first = arr[i];
		} 
	}
 
	int j = 0; 
	while(j + 1 <= n && arr[j + 1] <= first) 
		j++;
 
	int div = k / j;
	int left = k % j;
	for(int i=1; i<=j; i++) 
		arr[i] = first + div + int(i <= left);
 
	k = temp;
}
 
void reverse()
{
	for(int i=1; i<=n; i++)
		arr[i] = -arr[i];  
}
 
int main() {
 
	scanf("%d %d", &n, &k);
	for(int i=1; i<=n;i++)
		scanf("%d", &arr[i]);
	doStuff(); 
	for(int i=1; i<=n; i++)
		arr[i] = -arr[i];  
	doStuff(); 
	for(int i=1; i<=n; i++)
		arr[i] = -arr[i];  
 
	sort(arr + 1, arr + n + 1);
	printf("%d\n", arr[n] - arr[1]);
 
	return 0;
}