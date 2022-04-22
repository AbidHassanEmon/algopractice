#include<iostream>
using namespace std;

int search(int arr[], int n, int x)
{
    int k=0;
    int i=0;
    k++;

    while( i<n && arr[i]!= x )
    {
      k=k+4;

      i=i+1;

      k=k+2;
    }
    k=k+2;

    if(arr[i]!= x)
    {
      k=k+2;
    cout<<" NOT FOUND "<<endl;
    }

    else
      {
        k=k+2;
        cout<<" FOUND "<<endl;
      }
    cout<<"NUMBER OF COUNT = " << k <<endl;
}

int main()
{
    int arr[] = {2, 3, 4, 60, 11};
    int x = 20;
    int n = sizeof(arr) / sizeof(arr[0]);
    search(arr, n, x);

}
