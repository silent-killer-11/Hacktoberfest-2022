#include <iostream>
using namespace std;
void saydigit(int n, string arr[])
{
    // base case
    if (n == 0)
    {
        return; /* code */
    }
    // processing
    int digit = n % 10;
    n = n / 10;

    // recursive call

    saydigit(n, arr);
    cout << arr[digit] << " " << endl;
}
int main()
{
    string arr[10] = {"Zero", "one", "Two", "Three", "Four", "Five ", "six", "Seven",
                      "eight", "Nine"};
    int n;
    cin >> n;
    cout << endl;
    saydigit(n, arr);
    cout << endl;

    return 0;
}
