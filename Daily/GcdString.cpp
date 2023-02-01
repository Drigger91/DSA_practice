#include<iostream>
#include<string>
#include<vector>
using namespace std;


bool isDivisible(string prefix,string str){
    string check = prefix;
    for(int i = 0;i<str.length();i++){
        if(check.length() > str.length()) return false;
        if(check == str){
            //cout<<prefix<<" ";
            return true;
        }
        check += prefix;
    }
    return false;
}
string gcdOfStrings(string str1, string str2) {
    if(str1.length() < str2.length()) return gcdOfStrings(str2,str1);
    if(str1.length() == str2.length()) return str1 == str2 ? str1 : "";
    string prefix = "";
    string ans;
    for(int i = 0;i<str2.length();i++){
        prefix += str2[i];
        //cout<<prefix<<endl;
        if(isDivisible(prefix,str1) && isDivisible(prefix,str2)) ans = prefix;
    }
    return ans;
}
