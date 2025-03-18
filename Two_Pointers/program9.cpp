//Binary subarrays with sum

#include<bits/stdc++.h>
using namespace std;

int findNoOfSubarrays(vector<int> &arr,int goal){

    if(goal<0){
        return 0;
    }

    int count=0,sum=0;

    int left=0,right=0;

    while(right<arr.size()){

        sum+=arr[right];

        while(sum>goal){
            sum-=arr[left];
            left++;
        }

        count+=(right-left+1);
        right++;
    }

    return count;

    
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

    int goal=0;

    cout<<"Enter the goal value:"<<endl;
    cin>>goal;

    int count=findNoOfSubarrays(arr,goal);
    int count2=findNoOfSubarrays(arr,goal-1);

    int finalCount=count-count2;

    cout<<"The no of subarrays are "<<finalCount<<endl;

    return 0;
}