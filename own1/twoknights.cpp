#include <bits/stdc++.h>

using namespace std;

void xcount(long n){
    long base = (n*n) * (n*n-1) / 2;
    long sub = (n-1)*(n-2)*4;
    cout << base - sub << endl;
}
int main()
{
    long n;
    cin >> n;
    for(long i=0; i<n; i++)
    {
        xcount(i+1);
    }
}