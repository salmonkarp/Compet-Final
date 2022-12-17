#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    cin >> n;
    long long result = 1;
    while(n>0){
        result *= 2;
        if(result>=1000000007){
            result = result % 1000000007;
        }
        n--;
    }
    cout << result;
}