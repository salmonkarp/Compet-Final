#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n,q;
    cin >> n >> q;
    vector<vector<int>> yo(n);
    for(int i=0; i< n; i++)
    {
        int temp2;
        cin >> temp2;
        vector<int> temp_arr(temp2);
        for(int j=0; j<temp2; j++)
        {
            cin >> temp_arr[j];
        }
        yo[i] = temp_arr;
    }
    for(int i=0;i<q;i++)
    {
        int a,b;
        cin >> a >> b;
        cout << yo[a][b] << endl;
    }
    return 0;
}
