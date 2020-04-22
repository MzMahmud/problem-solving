#include <bits/stdc++.h>
#define decode(x) ((x >= 0)? x :(-1*(x+1)))
using namespace std;

template<class T>
T binarySearch(T x,T a[],int size){
    int pos,low,up,mid;
    low = 0,up  = size - 1;
    while(low <= up){
        mid = (low+up)/2;
        if(a[mid] == x) return mid;//if found returns the found index
        else if(x > a[mid]) low = mid + 1;
        else if(x < a[mid]) up  = mid - 1;
    }
	//if not found returns the -1*(correct sitting position + 1)
	//-ve will denote not found and +1 allows to distinguish betwn found at 0 and not found at 0
	///to get correct sitting position -1*(returned value + 1)

	if(x > a[mid]) mid++;//if the key is larger then it would sit next else the position in mid
    return -1*(mid+1);
}

int main(){
	int a[7] = {1,3,5,8,11,13,17};
	cout << binarySearch(1,a,7) << endl;
	cout << binarySearch(-9,a,7) << endl;
	cout << binarySearch(5,a,7) << endl;
	cout << binarySearch(7,a,7) << endl;
	cout << binarySearch(4,a,7) << endl;
    return 0;
}
