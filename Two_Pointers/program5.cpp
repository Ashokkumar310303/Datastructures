//Fruits into baskets

#include<bits/stdc++.h>
using namespace std;

int findFruitBaskets(vector<int> &arr,int baskets){

    int maxFruits=0;

    int left=0,right=0;

    unordered_map<int,int> mpp;

    while(right<arr.size()){
        
        int fruit=arr[right];

        mpp[fruit]++;

        if(mpp.size()>baskets){
            mpp[arr[left]]--;
            if(mpp[arr[left]]==0){
                mpp.erase(arr[left]);
            }
            left++;
        }




        if(mpp.size()<=baskets){
            maxFruits=max(maxFruits,right-left+1);
        }

        right++;
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