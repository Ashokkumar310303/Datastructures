//Longest substring without repeating character

#include<bits/stdc++.h>
using namespace std;

string findLongestSubstring(string &s){

    string answer="";

    vector<int> checking(26,0);

    int left=0,right=0;
    int maxLength=INT_MIN;

    int leftIndex=-1,rightIndex=-1;

    while(right<s.length()){

        checking[s[right]-'a']++;

        while(checking[s[right]-'a']==2){
            checking[s[left]-'a']--;
            left++;
        }

        if(right-left>maxLength){
            maxLength=right-left;
            leftIndex=left;
            rightIndex=right;
        }

        right++;

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