//maximum points you can obtain from cards

//you have pick cards should be equal to noOfcards and give me a max points but it was in consecutive order

//input 6 2 3 4 7 2 1 7 1 noofcards=4


#include<bits/stdc++.h>
using namespace std;

int findMaximumPoints(vector<int> &arr,int noOfCards){

        int left=0,right=0;
        int maxPoints=INT_MIN;
        int sum=0;

        while(right<noOfCards){
            sum+=arr[right];
            right++;
        }

        maxPoints=max(maxPoints,sum);

        while(left<arr.size()){
            sum+=arr[(right%arr.size())];
            sum-=arr[left];
            left++;
            right++;

            maxPoints=max(maxPoints,sum);
        }

        return maxPoints;

}

int main(){

    vector<int> arr;
    int elements=0;

    cout<<"Enter the no of elements:"<<endl;
    cin>>elements;

    arr.resize(elements);
    int value=0;
    cout<<"Enter the elements one by one"<<endl;
    for(int i=0;i<arr.size();++i){
        cin>>value;
        arr[i]=value;
    }

    int noOfCards=0;

    cout<<"Enter the no of cards:"<<endl;
    cin>>noOfCards;

    int maximumPoints=findMaximumPoints(arr,noOfCards);

    cout<<"The maximum points we can obtain form the card: "<<maximumPoints<<endl;

    return 0;

}