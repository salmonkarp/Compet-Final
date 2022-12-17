#include <iostream>
#define LL long long

using namespace std;

int main(){
	int b;
	scanf("%d", &b);
	for(int i=0; i<b; i++)
	{
		int stops;
		scanf("%d", &stops);
		int current_nice = 0, final_nice = 0;
		int current_length = 0, final_length = 0;
		int current_head = 0, final_head = 0;
		int current_tail = 0, final_tail = 0;
		for(int j=1; j<stops; j++)
		{
			int temp;
			scanf("%d",&temp);
			current_nice += temp;
			current_head=j;
			if(current_nice<0)
			{
				current_tail=j;
				current_nice = 0;
			}
			else{
				if(final_nice < current_nice)
				{
					final_tail = current_tail;
					final_head = j;
					final_nice = current_nice;
					final_length = current_head-current_tail;
				}
				else if(final_nice == current_nice && (current_head-current_tail) > final_length)
				{
					final_length = current_head-current_tail;
					final_tail = current_tail;
					final_head = j; 
				}
			}
			// cout << current_tail << ' ' << current_head << ' ' << current_nice << endl;
		}
		if(final_nice<=0)
			printf("Route %d has no nice parts\n",i+1);
		else
			printf("The nicest part of route %d is between stops %d and %d\n",i+1,final_tail+1,final_head+1);
	}
}