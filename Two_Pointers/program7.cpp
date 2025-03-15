//no of substring containing all three characters

#include<bits/stdc++.h>
using namespace std;

int findNoOfSubstrings(vector<char> &arr){

    int aLastPosition=-1,bLastPosition=-1,cLastPosition=-1;

    int index=0;

    int noOfSubstrings=0;

    while(index<arr.size()){

        if(arr[index]=='a'){
            aLastPosition=index;
        }
        else if(arr[index]=='b'){
            bLastPosition=index;
        }
        else{
            cLastPosition=index;
        }

        if(aLastPosition!=-1 && bLastPosition!=-1 && cLastPosition!=-1){

            if(aLastPosition<bLastPosition && aLastPosition<cLastPosition){
                noOfSubstrings+=aLastPosition+1;
            }
            else if(bLastPosition<aLastPosition && bLastPosition<cLastPosition){
                noOfSubstrings+=bLastPosition+1;
            }
            else{
                noOfSubstrings+=cLastPosition+1;
            }
        }

        index++;
    }

    return noOfSubstrings;
    
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