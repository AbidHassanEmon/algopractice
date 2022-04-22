#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

void knapsack( int w[], int b[], int n, int W)
{
    // defining a matrix to store result
    int B[n+1][W+1];
    int i,wt;

    // initialize 0 to first row where i=0
    for(wt=0; wt<=W; wt++)
    {
        B[0][wt]=0;
    }

    // initialize 0 to first column where w=0
    for(i=0; i<=n; i++)
    {
        B[i][0]=0;
    }

    // to consider each item i=1,i=2, i=3, so on
    for(i=1; i<=n; i++)
    {
        // to consider each capacity 1 to M
        for(wt=1; wt<=W; wt++)
        {
            if(w[i]<=wt)
            {
                B[i][wt] = max(B[i-1][wt], b[i] + B[i-1][wt - w[i]]);
            }
            else
                B[i][wt]= B[i-1][wt];
        }
    }
    //////
    cout<<"\nMatrix"<<endl;
    for(int j=0; j<= W; j++)
    {
        for(int i=0; i<=n; i++)
        {
            cout<<B[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"\nMaximum profit: "<<B[n][W]<<endl;

    // finding including items
    int r = B[n][W];
    cout<<"\nItems included are listed below:\n";
    for(int item = n; item >0; item--)
    {
        bool found =false;
        for(int j=0; j<= W; j++)
        {
            if(B[item-1][j] == r)
            {
                found =true;
            }
        }

        if(found == false)
        {
            cout<<"Item : "<< item << ", Profit : "<< b[item] << "\n";
            r = r - b[item];
        }
    }
}
int main()
{
    int no_item;
    cout<<"Enter no of items: ";
    cin>> no_item;
    int capacity;

    int weights[no_item+1],benefits[no_item+1];

    cout<<"User input [N0: 0 or Yes: 1]: ";
    int choice=0;
    cin>>choice;
    if(choice == 0)
    {
        time_t t;
        srand(time(&t));
        int tw=0;
        for(int i=1; i<=no_item; i++)
        {
            weights[i]=1+rand()%10;
            benefits[i]=1+rand()%20;
            tw = tw + weights[i];
        }
        capacity=tw/3;
    }
    else //user input
    {
        for(int i=1; i<=no_item; i++)
        {
            cout<< "Item "<<i<<": ";
            cin>>weights[i]>>benefits[i];
        }
        cout<<"Enter capacity: ";
        cin>>capacity;
    }

    cout<<"\n\nThe problem is below:\n";
    cout<<"Item\tWeight\tBenefit\n";
    for(int i=1; i<=no_item; i++){
        cout<<i<<"\t"<<weights[i]<<"\t"<<benefits[i]<<endl;
    }
    cout<<"Capacity: "<<capacity<<endl;
    knapsack(weights, benefits, no_item, capacity);
}
