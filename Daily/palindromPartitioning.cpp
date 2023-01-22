#include<iostream>
#include<vector>
#include<string>
using namespace std;

//Given a string s, 
//partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s

//example
//Input: s = "aab"
//Output: [["a","a","b"],["aa","b"]]
bool isPalindrome(string & s){
    int left = 0;
    int right = s.length()-1;
    while(left <= right){
        if(s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}
void backtrack(vector<string>& curr,string& s,vector<vector<string>>& ans,int idx = 0){
    //if you get at the end,push the current vector in ans;
    if(idx == s.length()){
        ans.push_back(curr);
        return;
    }
    for(int i = idx;i<s.length();i++){
        string check = s.substr(idx,i - idx + 1); //length of the substring
        if(isPalindrome(check)){
            curr.push_back(check);
            backtrack(curr,s,ans,i+1);
            curr.pop_back();
        }
    }

}
vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string>curr;
        backtrack(curr,s,ans);
        return ans;
    }
int main(){
    string s = "aab";
    vector< vector<string> >  ans = partition(s);
    for(int i = 0;i<ans.size();i++){
        vector<string> v = ans[i];
        for(int j = 0;j< v.size();j++){
            string s = v[i];
            cout<<s<<",";
        }
        cout<<endl;
    }
    return 0;
}