#include <iostream>
#include <graphics.h>
using namespace std;
int mi[3][20] = {0};
int n;
bool move(int,int);
void hanoi(int,int,int,int);
main()
{
    //int n;
    cin>>n;
    initwindow(1000,900);
    line(300,800,300,0);
    line(600,800,600,0);
    line(900,800,900,0);
    for(int i = 1;i<=n;i++)
    {
        mi[0][i-1] = i*5;
        setfillstyle(1,i);
        bar(300-i*5,800-(n-i+1) *10,300+i*5,800-(n-i)*10);
    }
    hanoi(n,0,1,2);
    int first,second;
    cin >>first>>second;
    while(first != -1)
    {

        move(first-1,second-1);
        cin >>first>>second;
    }
	getch();
}
bool move(int from, int to)
{
    int f = 0, t = n-1;
    while(mi[from][f] == 0)
    {
        f++;
    }
    while(mi[to][t] != 0)
    {
        t--;
    }
    if(mi[from][f] != 0)
    {
        setfillstyle(1,0);
        bar(300 * (from +1) - mi[from][f],800 - (n-f) * 10, 300 * (from+1) + mi[from][f], 800- (n-f-1) * 10);
        setfillstyle(1,mi[from][f] / 5);
        bar(300* (to + 1) - mi[from][f], 800 - (n-t) * 10,300*(to+1) + mi[from][f], 800 -(n-t-1)*10);
        mi[to][t] = mi[from][f];
        mi[from][f] = 0;
        cout<<"t"<<t<<"f"<<f;
    }
}
//void hanoi(int from,int to,int help)
void hanoi(int k,int from, int to, int help)
{
    delay(4000);
    if(k == 2)
    {
        move(from,help);
        move(from,to);
        move(help,to);
    }else
    {
        hanoi(k-1,from,help,to);
        move(from,to);
        hanoi(k-1,help,to,from);
    }

}
