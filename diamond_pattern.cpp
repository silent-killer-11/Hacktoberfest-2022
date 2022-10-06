#include <iostream>
using namespace std;
int main() {
    int space, rows;
cout <<"Enter number of rows: "; cin >> rows;
for(int i = 1, k = 0; i <= rows; ++i, k = 0) {
for(space = 1; space <= rows-i; ++space) {
cout <<" "; }
while(k != 2*i-1)
{
    cout << "* ";
    ++k;
By: Ali Hassan Soomro BSCS from UBIT, University of Karachi Facebook Id: AliiHassanSoomro Gmail: alisoomro666@gmail.com Instagram Id: alihassansoomro__
}
}
cout << endl;
for(int i = rows; i >= 1; --i)
{
for(int space = 0; space < rows-i; ++space) cout<<" ";
        for(int j = i; j <= 2*i-1; ++j)
            cout << "* ";
for(int j = 0; j < i-1; ++j) cout << "* ";
        cout << endl;
    }
return 0; }
