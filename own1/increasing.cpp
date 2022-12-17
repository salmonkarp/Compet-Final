#include <bits/stdc++.h>

using namespace std;

int main(){
    long n;
    cin >> n;
    long baseline = 0;
    long steps = 0;
    for(long i=0; i<n; i++)
    {
        long temp;
        cin >> temp;
        if(baseline<=temp){baseline=temp;}
        else{
            steps+=baseline-temp;
        }
    }
    cout << steps;
}