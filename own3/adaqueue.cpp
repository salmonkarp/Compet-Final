#include <stdio.h>
#include <string.h>
#include <queue>
#include <iostream>
using namespace std;
deque<int> reversequ(deque<int> q)
{
	if(q.empty())
		return q;
	else
	{
		int temp = q.front();
		q.pop_front();
		q = reversequ(q);
		q.push_back(temp);
		return q;
	}
}
int main()
{
	deque<int> q;
	int n;
	cin >> n;
	bool is_reversed = false;
	while(n--)
	{ 
		string s;
		cin >> s;
		if(s=="reverse")
			is_reversed=(!is_reversed);
		if((s=="back"||s=="front") && q.empty())
			printf("No job for Ada?\n");
		else if((s=="back" && is_reversed==false) || (s=="front" && is_reversed==true))
		{
			printf("%d\n",q.back());
			q.pop_back();
		}
		else if((s=="back" && is_reversed==true) || (s=="front" && is_reversed==false))
		{
			printf("%d\n",q.front());
			q.pop_front();
		}
		
		if((s=="push_back" && is_reversed==false) || (s=="toFront" && is_reversed==true))
		{
			int temp;
			cin >> temp;
			q.push_back(temp);
		}
		if((s=="push_back" && is_reversed==true) || (s=="toFront" && is_reversed==false))
		{
			int temp;
			cin >> temp;
			q.push_front(temp);
		}
	}
}