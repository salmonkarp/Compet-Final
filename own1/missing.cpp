#include <bits/stdc++.h>

using namespace std;

int main(){
    long n;
    cin >> n;
    long total = n * (n+1) / 2;
    for(long i=0; i<n-1; i++)
    {
        long temp;
        cin >> temp;
        total -= temp;
    }
    cout << total;
}