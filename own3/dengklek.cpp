#include <bits/stdc++.h>
#define LL long long

using namespace std;


bool dengklek(string x)
{
	if(x.size()<=1)
		return true;
	else if(x[0]==x[x.size()-1])
		return dengklek(x.substr(1,x.size()-2));
	else
		return false;
}

int main(){
	string x;
	cin >> x;
	if(dengklek(x)==true)
		printf("YA");
	else
		printf("BUKAN");
}