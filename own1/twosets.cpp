#include <bits/stdc++.h>

using namespace std;

int main(){
    long n;
    cin >> n;
    if(n%4==0){
        cout << "YES" << endl << n / 2 << endl;
        for(long i=1; i<=n/4; i++){
            cout << 4*i - 3 << ' ' << 4*i << ' ';
        }
        cout << endl << n/2 << endl;
        for(long i=1; i<=n/4; i++){
            cout << 4*i-2 << ' ' << 4*i-1 << ' ';
        }
    }
    else if((n-3)%4==0){
        cout << "YES" << endl << (n+1)/2 << endl;
        cout << "1 2 ";
        for(long i=2; i<=(n-3)/4+1; i++){
            cout << 4*i - 3 << ' ' << 4*i - 2<< ' ';
        }
        cout << endl << (n-1)/2 << endl;
        cout << "3 ";
        for(long i=2; i<=(n-3)/4+1; i++){
            cout << 4*i-4 << ' ' << 4*i-1 << ' ';
        }
    }
    else{
        cout<<"NO";
    }
}