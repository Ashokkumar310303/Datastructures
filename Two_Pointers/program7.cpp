//no of substring containing all three characters

#include<bits/stdc++.h>
using namespace std;

int findNoOfSubstrings(vector<char> &arr){

    int countSubstrings=0;
    
    for(int i=0;i<arr.size();++i){
        unordered_map<int,int> mpp;
        for(int j=i;j<arr.size();++j){
            mpp[arr[j]]++;
            if(mpp.size()==3){
                countSubstrings++;
            }
        }
    }

    return countSubstrings;
}

int main(){

    int size=0;
    cout<<"Enter the size of the array:"<<endl;
    cin>>size;

    vector<char> arr;
    char value;

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

    int noOfSubstrings=findNoOfSubstrings(arr);

    cout<<"The no of substrings are : "<<noOfSubstrings<<endl;

    return 0;
}