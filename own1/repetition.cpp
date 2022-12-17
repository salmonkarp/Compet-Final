#include <bits/stdc++.h>

using namespace std;

int main(){
    string c;
    cin >> c;
    long max=1;
    long actual_max = -1;
    char temp='!';
    for(long i=0; i<c.length(); i++)
    {
        if(i == 0)
        {
            temp = c[i];
        }
        else if(temp==c[i]){
            max +=1;
        }
        else if(temp!=c[i]){
            temp = c[i];
            if(actual_max<max)
            {actual_max=max;}
            max = 1;
        }
        if(i==c.length()-1 && max > actual_max){
            actual_max = max;
        }
    }
    cout << actual_max;
}