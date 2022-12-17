#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
	unsigned LL row,col,t,x,y;
	unsigned LL a;
	unsigned LL vert_shift = 0;
	unsigned LL hori_shift = 0;
	unsigned LL command_counter = 1;
	char s[10];
	map<pair<unsigned LL,unsigned LL>,unsigned LL> changes;
	scanf("%llu %llu",&row,&col);
	scanf("%llu",&t);
	for(unsigned LL hk=1; hk<=t; hk++)
	{
		scanf("%s",&s);
		if(s[0]=='p')
		{
			//x is vertical, y is horizontal
			scanf("%llu %llu",&y,&x);
			x += vert_shift;
			y += hori_shift;
			if(x<1)
				x %= row;
			if(x>row)
				x %= row;
			if(y<1)
				y %= col;
			if(y>col)
				y %= col;
			printf("Command #%llu: ",command_counter);
			if(changes.count(make_pair(x,y))==1)
			{
				printf("%llu\n",changes[make_pair(x,y)]);
			}
			else
			{
				unsigned LL res = (x-1)*col + y;	
				printf("%llu\n",res);
			}
			command_counter++;
		}
		if(s[0]=='u')
		{
			vert_shift +=1;
		}
		if(s[0]=='d')
		{
			vert_shift -=1;
		}
		if(s[0]=='l')
		{
			hori_shift += 1;
		}
		if(s[0]=='r' && s[1]=='i')
		{
			hori_shift -= 1;
		}
		if(s[0]=='m')
		{
			scanf("%llu %llu %llu",&y,&x,&a);
			// if (hori_shift==0) hori_shift=col;
	        // else if (vert_shift==0) vert_shift=row;
	        // else if (hori_shift>col) hori_shift=1;
	        // else if (vert_shift>row) vert_shift=1;
			x += vert_shift;
			y += hori_shift;
			if(x<1)
				x %= row;
			if(x>row)
				x %= row;
			if(y<1)
				y %= col;
			if(y>col)
				y %= col;
			changes[make_pair(x,y)] = a;
		}
		if(s[0]=='r' && s[1]=='e')
		{
			scanf("%llu %llu",&y,&x);
			// if (hori_shift==0) hori_shift=col;
	        // else if (vert_shift==0) vert_shift=row;
	        // else if (hori_shift>col) hori_shift=1;
	        // else if (vert_shift>row) vert_shift=1;
			x += vert_shift;
			y += hori_shift;
			if(x<1)
				x %= row;
			if(x>row)
				x %= row;
			if(y<1)
				y %= col;
			if(y>col)
				y %= col;
			changes[make_pair(x,y)] = 0;
		}

        if (vert_shift==row) vert_shift=0;
        if (hori_shift==col) hori_shift=0;
        if (vert_shift>row) vert_shift=1;
        if (hori_shift>col) hori_shift=1;
	}
}
