#include <bits/stdc++.h>
using namespace std;
int k=0;
int binarySearch(int arr[], int low, int high, int x)
{
    cout<<" LOW = " <<low<<"\t HIGH = "<<high <<endl;

    if (high >= low)
      {
        k=k+1;
        int mid = (low + high )/ 2;
        k=k+3;
        if (arr[mid] == x)
            {
                k=k+3;
                return mid;
            }

        if (arr[mid] > x)
           {
             k=k+3;
             return binarySearch(arr, low, mid - 1, x);
           }
       else
        {
            k=k+1;
            return binarySearch(arr, mid + 1, high, x);
        }

    }
    k=k+1;
    return -1 ;

}


int main( )
{
    int arr[] = { 2, 3, 4, 10, 40, 45, 46, 49 };
    int x = 22;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);

    if(result == -1)
         {cout << "Element is not present in array"<<endl;}

    else
        { cout << "Element is present at index " << result<<endl;}

    cout<< "NUMBER OF OPERATION = "<<k<<endl;

    return 0;
}

