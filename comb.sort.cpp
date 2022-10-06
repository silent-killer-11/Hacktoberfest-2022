//Program for Comb Sort in C++
#include<bits/stdc++.h>
#include<time.h>
using namespace std;

int getNextGap(int gap) {
	gap = (gap*10)/13;
	if (gap < 1)
		return 1;
	return gap;
}

void Comb_Sort(int arr[], int n) {
	int gap = n;
    bool swapped = true;
	while (gap != 1 || swapped == true) {
		gap = getNextGap(gap);
		swapped = false;
		for (int i=0; i<n-gap; i++) {
			if (arr[i] > arr[i+gap]) {
				swap(arr[i], arr[i+gap]);
				swapped = true;
			}
		}
	}
}

void print_array(int arr[], int n) {
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(void) {
	int n;
    srand(time(0));
    //cout<<"Enter the size of n:"<<endl;
    cin>>n;
    int arr[n+1];
    for(int i=0;i<n;i++) {
        arr[i]=rand()%1000;
    }    
	
    cout<<"Before sort -- "<<endl;
    print_array(arr,n);

    Comb_Sort(arr, n);

	cout<<"After sort -- "<<endl;
	print_array(arr,n);
	
    return 0;
}
