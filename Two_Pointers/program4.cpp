//max consecutive ones you can flip k zero 

#include<bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &arr,int &zeroFlip){

    int maxLength=INT_MIN;

    int countZeros=0;

    int left=0,right=0;

    while(right<arr.size()){

        if(arr[right]==0){
            countZeros++;
        }

        if(countZeros>zeroFlip){
            if(arr[left]==0){
                countZeros--;
            }
            left++;
        }

        maxLength=max(maxLength,right-left+1);

        right++;
        
    }

    return maxLength;
    
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

    int zerosFlip=0;

    cout<<"Enter the no of zero you can flip"<<endl;
    cin>>zerosFlip;

    int maxConsecutive=findMaxConsecutiveOnes(arr,zerosFlip);

    cout<<"Max consecutive values are "<<maxConsecutive<<endl;


    return 0;
}