//Longest substring without repeating character

#include<bits/stdc++.h>
using namespace std;

string findLongestSubstring(string &s){

    string answer="";

    vector<int> checking(26,0);

    for(int i=0;i<s.length();++i){

        string currentWord="";

        for(int j=i;j<s.length();++j){
            if(checking[s[j]-'a' ]){
                break;
            }
            else{
                currentWord+=s[j];
                checking[s[j]-'a']=1;
            }
        }

        if(currentWord.length()>answer.length()){
            answer=currentWord;
        }
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