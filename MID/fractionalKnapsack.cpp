#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int k=0;

void fractionKnapsack(int w[], int b[], int n, int W){
    //definition
    //update k
    float vInd[n],x[n];
    for(int i=0;i<n;i++){
        vInd[i]=b[i]/(float)w[i];
        x[i]=0;     //finding per kilo wait
    }
    int cw =0, rc = W;
    float profit=0;
    while(cw<W){
        // choose the best
        int item=0;
        for(int j=1; j< n; j++){
            if(vInd[item]<vInd[j]){
                item = j;
            }
        }
        // collect the best item
        x[item]=min(w[item], W-cw);
        cw = cw+ x[item];
        profit = profit + x[item]*vInd[item];
        vInd[item]=0;//do not consider next time
    }

    // print
    for(int i=0; i<n; i++){
        cout<<" "<< x[i];
    }
    cout<<endl;
    cout<<"Profit: "<<profit<<endl;
}

int main(){
    int number_items;
    cout<<"Enter number of items:";
    cin>>number_items;
    int weights[number_items],benefits[number_items], Capacity;
    //input
    time_t t;
    srand(time(&t));
    int tw=0;
    for(int i=0; i<number_items; i++){
        weights[i]=1+rand()%10;
        tw =tw+weights[i];
        benefits[i]=1+rand()%100;
    }
    Capacity = tw/2;

    //print the problem
    for(int i=0; i<number_items; i++){
        cout<<"Item"<<i+1<<"\t"<<weights[i]<<"\t"<<benefits[i]<<"\t"<<(float)benefits[i]/weights[i]<<endl;
    }
    cout<<"W="<<Capacity<<endl;

    //call function
    fractionKnapsack(weights,benefits,number_items, Capacity);
    //print k
}
