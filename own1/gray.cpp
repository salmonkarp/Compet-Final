#include <bits/stdc++.h>

using namespace std;

vector<string> wprint(int n){
    if(n==1){
        vector<string> base{"0","1"};
        return base;
    }
    int total = pow(2,n);
    vector<string> arr(total);
    vector<string> temp = wprint(n-1);
    for(int i=0; i<total/2; i++){
        arr[total/2 - i - 1] = "1" + temp[i];
        arr[total/2 + i] = "0" + temp[i];
    }
    return arr;
}

int main(){
    int x;
    cin >> x;
    vector<string> res = wprint(x);
    for(int i=0; i<res.size(); i++)
    {
        cout << res[i] << endl;
    }
}