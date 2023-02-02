// Intuition
// The intuition is to create a custom mapping of characters and then sort the array according to it.

// Approach
// We all know the normal mapping of characters i.e (a == 0, b == 1 and so on) the idea of this question is to create a custom mapping and then sort the array according to it using a comparator.
// First we store the mapping using a hashmap.You can use vector also but I prefer map.
// Then we create our "Sorted array" by using a custom comparator.
// The approach of sorting is to check the common length first and then the smaller one should come first.
// Lastly we check if the array provided was actually sorted or not.

// Complexity
// Time complexity:
// O(NlogN*(max length of string)) - as we are iterating on a string

// Space complexity:
// O(N) - for check
// O(26) - for mapsor

// Code
#include<map>
#include<unordered_map>
#include<string>
#include<vector>

using namespace std;

bool isAlienSorted(vector<string>& words, string order) {
    unordered_map<char,int> map;
    for(int i=0;i<order.size();i++){
        map[order[i]] = i;
    }
    vector<string>check = words;
    sort(check.begin(),check.end(),[&](string& a, string& b){
        int size = min(a.length(),b.length());
        for(int i = 0;i<size;i++){
            if(map[a[i]] != map[b[i]]){
                return map[a[i]] < map[b[i]];
            }
        }
        return a.length() < b.length();
    });
    return check == words;
}
