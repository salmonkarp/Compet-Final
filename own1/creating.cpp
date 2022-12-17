#include <bits/stdc++.h>

using namespace std;

int boss=0;
vector<string> final_res{};

bool shouldSwap(string c, int start, int current){
	for(int i=start; i<current; i++)
	{
		if(c[i]==c[current]){
			return false;
		}
	}
	return true;
}
void permute(string c, int left, int right)
{
	if(left==right)
	{
		final_res.insert(final_res.end(),c);
		boss++;
	}
	else
	{
		for(int i=left; i<right; i++)
		{
			if(shouldSwap(c,left,i)){
				swap(c[i],c[left]);
				permute(c,left+1,right);
				swap(c[i],c[left]);
			}
		}
	}
}
int main()
{
	string x;
	cin >> x;
	int length = int(x.length());
	permute(x,0,length);
	cout << boss << endl;
	sort(final_res.begin(),final_res.end());
	for(int i=0; i<final_res.size(); i++)
	{
		cout << final_res[i] << endl;
	}
}
