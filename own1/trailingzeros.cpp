#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    long temp = 5;
    long ret = 0;
    while(n/temp>=1){
        ret += n/temp;
        temp *= 5;
    }
    cout << ret;
}