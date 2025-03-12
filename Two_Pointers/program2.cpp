//maximum points you can obtain from cards

//you have pick cards should be equal to noOfcards and give me a max points but it was in consecutive order
//but the main condition was you can pick from front and back only

//input 6 2 3 4 7 2 1 7 1 noofcards=4


#include<bits/stdc++.h>
using namespace std;

int findMaximumPoints(vector<int> &arr,int noOfCards){

      int left=0,right=0,sum=0,lastIndex=arr.size()-1;
      int maxPoints=INT_MIN;

      while(right<noOfCards){
        sum+=arr[right];
        right++;
      }

      right--;

      maxPoints=max(maxPoints,sum);

      while(right>=0){

        sum-=arr[right];
        right--;
        sum+=arr[lastIndex];
        lastIndex--;

        maxPoints=max(maxPoints,sum);
      }


      return maxPoints;



    

}

int main(){

    vector<int> arr;
    int elements=0;

    cout<<"Enter the size of the array:"<<endl;
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