#include <bits/stdc++.h>
using namespace std;
//#define int long long;

int counter = 0;
string Hanoi(int no_of_disks, int start, int end, int aux){
	string res="";
	if(no_of_disks == 1)
	{
		//when only need to move one, move disk from start to end
		res = res + to_string(start) + " " + to_string(end) + "\n";
		counter++;
		return res;
	}
	else
	{
		res += Hanoi(no_of_disks-1, start, aux, end); //Move all except the bottom to the middle, with the end as the aux
		res = res + to_string(start) + " " + to_string(end) + "\n";//Move bottom disk from start to end
		counter++;
		res += Hanoi(no_of_disks-1, aux, end, start); //Move the rest from the aux to the end, with the beginning as the aux
		return res;
	}
}

int main(){
	int n;
	cin >> n;
	string result = Hanoi(n,1,3,2);
	cout << counter << endl;
	cout << result;
}
