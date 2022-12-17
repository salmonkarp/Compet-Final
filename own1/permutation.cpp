#include <bits/stdc++.h>

using namespace std;
void dothings(int n)
    {
        n += 1;
        n = n/2;
        for(int i=1; i<=n-1; i++)
        {
            cout << n+i << ' ' << n-i << ' ';
        }
        cout << n << ' ';
    }
int main(){
    int n;
    cin >> n;
    if(n==1){cout<<"1";}
    else if(n<4){cout<<"NO SOLUTION";}
    else if(n==4){cout<<"2 4 1 3";}
    else if(n%2==1){dothings(n);}
    else{
        dothings(n-1);
        cout << n;
    }
}