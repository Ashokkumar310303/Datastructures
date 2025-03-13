//Longest substring without repeating character

#include<bits/stdc++.h>
using namespace std;

string findLongestSubstring(string &s){

    string answer="";

    int left=0,right=0;
    int maxLength=INT_MIN;

    unordered_map<char,int> mpp;

    int leftIndex=-1,rightIndex=-1;

    while(right<s.length()){

        if(mpp.find(s[right])!=mpp.end() && mpp[s[right]]>=left){
  
            left=mpp[s[right]]+1;
        }

        if(right-left>maxLength){
            maxLength=right-left;
            leftIndex=left;
            rightIndex=right;
        }

        mpp[s[right]]=right;

        right++;

        cout<<left<<" "<<right<<endl;

    }

    for(int i=leftIndex;i<=rightIndex;++i){
        answer+=s[i];
    }

    return answer;
}

int main(){

    string s;

    cout<<"Longest substring without repeating character"<<endl;

    cout<<"Enter the string you want:"<<endl;
    cin>>s;

    string longestSubstring=findLongestSubstring(s);

    cout<<"The longest substring was "<<longestSubstring<<endl;


    return 0;
}