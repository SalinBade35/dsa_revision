// TOH
#include<iostream>
#include<conio.h>
using namespace std;

void TOH(int n, char s, char m, char d)
{
	if(n>0)
	{
		TOH(n-1, s, d, m);
		cout<<"\n move disk from "<<s<<" to "<<d;
		TOH(n-1, m, s, d);
	}
}

int main()
{
	int n;
	cout<<"entre number of disks: ";
	cin>>n;
	TOH(n, 'S', 'M', 'D');
	getch();
	
	return 0;
}
