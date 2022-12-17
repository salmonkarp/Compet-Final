#include <bits/stdc++.h>

using namespace std;

long sks(vector<long> we, long currentsum, long totalsum, int index)
{
    if(index==0)
    {
        return abs(totalsum - currentsum - currentsum);
    }
    else{
        return min(sks(we, currentsum+we[index], totalsum, index-1), sks(we, currentsum, totalsum, index-1));
    }
}
int main()
{
    int n;
    cin >> n;
    vector<long> we(n);
    long total=0;
    for(int i=0; i<n; i++)
    {
        cin >> we[i];
        total+=we[i];
    }
    cout << sks(we, 0, total, n-1);
}
