#include <bits/stdc++.h>
using namespace std;
void fastscan(int &number) 
{ 
    //variable to indicate sign of input number 
     bool negative = false; 
     register int c; 
     number = 0; 

     // extract current character from buffer 
     c = getchar(); 
     if (c=='-') 
     { 
         // number is negative 
         negative = true; 
         // extract the next character from the buffer 
          c = getchar(); 
      } 

           // Keep on extracting characters if they are integers 
           // i.e ASCII Value lies from '0'(48) to '9' (57) 
           for (; (c>47 && c<58); c=getchar()) 
               number = number *10 + c - 48; 

           // if scanned input has a negative sign, negate the 
           // value of the input number 
           if (negative) 
               number *= -1; 
}
int main()
{
	deque<int> q;
	int n;
	fastscan(n);
	while(n--)
	{ 
		string s;
		cin >> s;
		if((s=="back"||s=="front") && q.empty())
			printf("No job for Ada?\n");
		else if(s=="back")
		{
			printf("%d\n",q.back());
			q.pop_back();
		}
		else if(s=="front")
		{
			printf("%d\n",q.front());
			q.pop_front();
		}
		if(s=="reverse")
		{
			deque<int> tempq;
			while(!q.empty())
			{
				tempq.push_front(q.front());
				q.pop_front();
			}
			q = tempq;
		}
		if(s=="push_back")
		{
			int temp;
			fastscan(temp);
			q.push_back(temp);
		}
		if(s=="toFront")
		{
			int temp;
			fastscan(temp);
			q.push_front(temp);
		}
	}
}
