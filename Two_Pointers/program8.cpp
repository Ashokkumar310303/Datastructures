//Longest repeating character replacement
//Capital Letters only

#include<bits/stdc++.h>
using namespace std;

string findLongestRepeating(vector<char> &arr,int repeatingAllowed){

    int maxLength=-1;
    int leftIndex=-1,rightIndex=-1;

    for(int i=0;i<arr.size();++i){
        vector<int> checking(26,0);

        for(int j=i;j<arr.size();++j){

            checking[arr[j]-'A']+=1;
            
            int maxCount=max(maxCount,checking[arr[j]-'A']);

            int length=j-i+1;

            if(length-maxCount>repeatingAllowed){
                break;
            }
            else{
                if(j-i+1>maxLength){
                    maxLength=j-i+1;
                    leftIndex=i;
                    rightIndex=j;
                }
            }
        }
    }

    string answer="";

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

    int replacement=0;

    cout<<"Enter the replacement value allowed:"<<endl;
    cin>>replacement;

    string longestRepeating=findLongestRepeating(arr,replacement);

    cout<<"The longest Repeating string was "<<longestRepeating<<endl;

    return 0;
}