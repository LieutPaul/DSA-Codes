#include<iostream>
#include<unordered_map>
using namespace std;
int findTheLongestSubstring(string s) {
    //1->even 0->odd
    unordered_map <int,int> map;
    for(int i=0;i<=31;i++){
        map[i]=INT_MIN;
    }
    map[31]=-1;
    int max_len=0,len=0;
    int a=31;
    for(int i=0;i<s.length();i++){
        if(s[i]=='a'){
            a^=16;
        }else if(s[i]=='e'){
            a^=8;
        }else if(s[i]=='i'){
            a^=4;
        }else if(s[i]=='o'){
            a^=2;
        }else if(s[i]=='u'){
            a^=1;
        }
        if(map[a]==INT_MIN){
            map[a]=i;
        }else{
            len=i-map[a];
            max_len=max(max_len,len);
        }
        
    }
    return max_len;
}