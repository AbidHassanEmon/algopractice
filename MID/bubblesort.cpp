#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n)
{
  int pass,j,flag;
  for (pass = 1; pass< n; pass++)
    {
      flag=0;


  for (j = 0; j < (n-pass); j++)
    {

      if (arr[j] > arr[j+1])
        {
           swap(arr[j], arr[j+1]);

           flag = 1;
        }

      if(flag==0) break;

    }
  }
}


int main()
{
    int arr[] = { 35,2,14,20, 43, 55,97};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    cout<<"\nSORTED ARRAY: "<<endl;

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
        cout << endl;

    return 0;
}
