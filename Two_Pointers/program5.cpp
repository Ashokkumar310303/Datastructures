//Fruits into baskets

#include<bits/stdc++.h>
using namespace std;

int findFruitBaskets(vector<int> &arr,int baskets){

    int maxFruits=0;

    for(int i=0;i<arr.size();++i){
        unordered_map<int,int> mpp;
        for(int j=i;j<arr.size();++j){
            
            int fruit=arr[j];

            if(mpp.find(fruit)!=mpp.end()){
                mpp[fruit]+=1;
            }
            else if(mpp.size()<baskets){
                mpp[fruit]=1;
            }
            else{
                break;
            }

            maxFruits=max(maxFruits,j-i+1);


        }

    }

    return maxFruits;
}

int main(){

    int size=0;
    cout<<"Enter the size of the array:"<<endl;
    cin>>size;

    vector<int> arr;
    int value=0;

    cout<<"Please enter the array elements:"<<endl;
    for(int i=0;i<size;++i){
        cin>>value;
        arr.push_back(value);
    }

    cout<<"The array was like:"<<endl;
    for(auto it:arr){
        cout<<it<<" ";
    }

    cout<<endl;

    int baskets=0;

    cout<<"Enter the no of basket you want:"<<endl;
    cin>>baskets;

    int maxFruits=findFruitBaskets(arr,baskets);

    cout<<"Max Fruits we can collect is:"<<maxFruits<<endl;

    return 0;
}