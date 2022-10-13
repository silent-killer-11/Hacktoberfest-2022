#include<iostream>
using namespace std;
template<class T1>
void display(T1 a)
{
	cout<<"\nOne Variable Template "<<a<<"\n";
}
template<class T1,class T2>
void display(T1 a,T2 b)
{
	cout<<"\nTwo Variable Template "<<a<<"&"<<b<<"\n";
}
int main()
{
	display(17);
	display('q');
	display(39.7);
	display(25,'b');
	display(39.7,'a');
	return 0;
}