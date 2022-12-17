#include <bits/stdc++.h>

using namespace std;

int main(){
    string c;
    cin >> c;
    int arr[26]={};
    int len = int(c.length());
    for(int i=0; i<len; i++){
        arr[int(c[i])-65]+=1;
    }
    if(len%2==0)
    {
        for(int i=0; i<26; i++)
        {
            if(arr[i]%2!=0){
                cout<<"NO SOLUTION";
                return 0;
            }
        }
        for(int i=0; i<26; i++)
        {
            if(arr[i]!=0){
                for(int j=0; j<arr[i]/2; j++){
                    cout << char(i+65);
                }
            }
        }
        for(int i=25; i>=0; i--)
        {
            if(arr[i]!=0){
                for(int j=0; j<arr[i]/2; j++){
                    cout << char(i+65);
                }
            }
        }

    }
    else{
        bool found_weird = false;
        int weirdloc;
        for(int i=0; i<26; i++)
        {
            if(arr[i]%2!=0){
                if(found_weird == false){
                    found_weird = true;
                    weirdloc = i;
                }
                else{
                    cout<<"NO SOLUTION";
                    return 0;
                }
            }
        }
        for(int i=0; i<26; i++)
        {
            if(arr[i]!=0 && i!=weirdloc){
                for(int j=0; j<arr[i]/2; j++){
                    cout << char(i+65);
                }
            }
        }
        for(int i=0; i<arr[weirdloc]; i++){
            cout << char(weirdloc+65);
        }
        for(int i=25; i>=0; i--)
        {
            if(arr[i]!=0 && i!=weirdloc){
                for(int j=0; j<arr[i]/2; j++){
                    cout << char(i+65);
                }
            }
        }
    }
}
