//Longest substring atmost k distinct characters

#include<bits/stdc++.h>
using namespace std;

string findLongestSubarray(vector<char> &arr,int distinctValue){

    unordered_map<int,int> mpp;
    int maxLength=-1,left=0,right=0;
    string answer="";


    for(int i=0;i<arr.size();++i){
        for(int j=i;j<arr.size();++j){

            mpp[arr[j]]++;

            if(mpp.size()<=distinctValue){
                if(maxLength<j-i+1){
                    maxLength=j-i+1;
                    left=i;
                    right=j;
                }
            }
            else{
                break;
            }
        }
    }

    for(int i=left;i<=right;++i){
        answer+=arr[i];
    }

    return answer;
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

    int distinctValue=0;

    cout<<"Enter the no of distinct Value you want:"<<endl;
    cin>>distinctValue;

    string longestSubarray=findLongestSubarray(arr,distinctValue);

    cout<<"The longest subarray was : "<<longestSubarray<<endl;



    return 0;
}