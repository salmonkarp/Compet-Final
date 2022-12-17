#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        long long x,y;
        cin >> y >> x;
        long temp = max(x,y);
        long base = ((temp * temp + (temp-1) * (temp-1))+1)/2;
        long det = -1;
        if(temp%2==1){det=1;}
        long result = base + (x-y)*det;
        cout <<result<<endl;
    }
}