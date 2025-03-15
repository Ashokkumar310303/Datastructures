//Longest repeating character replacement
//Capital Letters only

#include<bits/stdc++.h>
using namespace std;

string findLongestRepeating(vector<char> &arr,int repeatingAllowed){

   string answer="";

   int left=0,right=0,maxCount=0;
   int leftIndex=0,rightIndex=0;

   int maxLength=0,length=0;

   vector<int> checking(26,0);

   while(right<arr.size()){

        checking[arr[right]-'A']++;
        maxCount=max(maxCount,checking[arr[right]-'A']);
        

        if((right-left+1)-maxCount>repeatingAllowed){
            checking[arr[left]-'A']--;
            maxCount=0;
            for(auto it:checking){
                maxCount=max(maxCount,it);
            }
            left++;
        }
        
        if(right-left+1>maxLength){
            maxLength=right-left+1;
            leftIndex=left;
            rightIndex=right;
        }
        cout<<left<<" "<<right<<endl;
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

    int replacement=0;

    cout<<"Enter the replacement value allowed:"<<endl;
    cin>>replacement;

    string longestRepeating=findLongestRepeating(arr,replacement);

    cout<<"The longest Repeating string was "<<longestRepeating<<endl;

    return 0;
}