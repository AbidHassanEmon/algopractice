#include<iostream>
using namespace std;
int op;

void merge(int arr[], int l, int m, int r)
{
     cout<<" MARGE( ";
    for(int i = l; i <= r ; i++)
          {
            if(i == m){cout<<arr[i] <<"|";}
            else
             cout << arr[i] << " ";
          }
          cout<<")"<<endl;


    int n1 = m - l + 1;
    int n2 = r - m;

    op=op+5;

    int L[n1], R[n2];

    for(int i = 0; i < n1; i++)
        L[i] = arr[l + i];

    op = op + ( 4*n1 );

    for(int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    op = op + ( 5*n2 );

    int i = 0;
    int j = 0;
    int k = l;
    op = op + 3;

    while (i < n1 && j < n2)
    {
        op = op + 3;
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
            op = op + 6;
        }
        else
        {
            arr[k] = R[j];
            j++;
            op = op +4;
        }
        k++;
        op = op + 1;
    }


    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
        op = op +6;
    }


    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
        op = op + 6;
    }
}


void mergeSort(int arr[], int l, int r)
{
     cout<<" mergeSort( ";
    for(int i = l; i <=r ; i++)
          { cout << arr[i] << " ";}
          cout<<")"<<endl;
    if (l < r)
    {
        op = op +1;
        int m = l + (r - l) / 2;

        op = op +4;

        mergeSort(arr, l, m);

        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);

        op = op + 3;
    }
}


void printArray(int A[], int size)
{
    for(int i = 0; i < size; i++)
       { cout << A[i] << " ";}
       cout <<endl;
}


int main()
{
    int arr_size;
    cout<<"Enter number of elements to be sorted:  ";
    cin>>arr_size;
    int arr[arr_size];
    cout<<"Enter "<<arr_size<<" number : "<<endl;
    for(int j=0;j < arr_size; j++)
        {
            cin>>arr[j];
        }

    cout << "GIVEN ARRAY : ";
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    cout << "SORTED ARRAY : ";
    printArray(arr, arr_size);

    cout<<"TOTAL NUMBER OF OPERATION : "<<op;

    return 0;
}

