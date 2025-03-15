//Longest substring atmost k distinct characters

#include<bits/stdc++.h>
using namespace std;

string findLongestSubarray(vector<char> &arr,int distinctValue){

   string answer="";

   unordered_map<int,int> mpp;

   int left=0,right=0,maxLength=-1;

   int leftIndex=0,rightIndex=0;

   while(right<arr.size()){

        mpp[arr[right]]++;

        while(mpp.size()>distinctValue){
            mpp[arr[left]]--;
            if(mpp[arr[left]]==0){
                mpp.erase(arr[left]);
            }
            left++;
        }

        

        if(maxLength<right-left+1){
            maxLength=right-left+1;
            leftIndex=left;
            rightIndex=right;
        }

        right++;

   }


   for(int i=leftIndex;i<=rightIndex;++i){
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