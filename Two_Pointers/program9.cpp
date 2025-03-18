//Binary subarrays with sum

#include<bits/stdc++.h>
using namespace std;

int findNoOfSubarrays(vector<int> &arr,int goal){

    int count=0;
    

    for(int i=0;i<arr.size();++i){
        int sum=0;
        for(int j=i;j<arr.size();++j){
            sum+=arr[j];
            if(sum==goal){
                count++;
            }
            else if(sum>goal){
                break;
            }
        }

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

    cout<<"The no of subarrays are "<<count<<endl;

    return 0;
}