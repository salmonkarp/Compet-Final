#include <iostream>
#include <stdio.h>
#include <map>
#include <utility>
#define ull unsigned long long
#define mp make_pair
using namespace std;

ull n,m,posx,posy,temps,hasil;
char temp[10];
int tc,c;
ull a,b;
map<pair<int,int>,ull> modif;

int main()
{
    //freopen("in7.in","r",stdin); 
    //freopen("out7v2.out","w",stdout); 
    scanf("%llu %llu",&n,&m);
    scanf("%d",&tc);
    c=0;
    posx=1;
    posy=1;
    while(tc--)
    {
        scanf("%s",temp);
        if(temp[0]=='u')
        {
            //printf("test\n");
            posy++;
            if(posy>n)
            posy=1;
        }
        else if(temp[0]=='d')
        {
            posy--;
            if(posy<1)
            posy=n;
        }
        else if(temp[0]=='l')
        {
            posx++;
            if(posx>m)
            posx=1;
        }
        else if(temp[0]=='r'&&temp[1]=='i')
        {
            posx--;
            if(posx<1)
            posx=m;
        }
        else if(temp[0]=='m')
        {
            scanf("%llu %llu %llu",&a,&b,&temps);
            a+=posx-1;
            b+=posy-1;
            while(a>m)a-=m;
            while(b>n)b-=n;
            modif[mp(a,b)]=temps+1;
        }
        else if(temp[0]=='r'&&temp[1]=='e')
        {
            scanf("%llu %llu",&a,&b);
            a+=posx-1;
            b+=posy-1;
            while(a>m)a-=m;
            while(b>n)b-=n;
            modif[mp(a,b)]=1;
        }
        else
        {
            scanf("%llu %llu",&a,&b);
            a+=posx-1;
            b+=posy-1;
            while(a>m)a-=m;
            while(b>n)b-=n;
            if(modif[mp(a,b)]==0)
            {
                hasil=(b-1)*m+a;
            }
            else
            hasil=modif[mp(a,b)]-1;
            //printf("%llu %llu %llu %llu\n",posx,posy,a,b);
            printf("Command #%d: %llu\n",++c,hasil);
        }
    }
    return 0;
}