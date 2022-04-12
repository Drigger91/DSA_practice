#include<bits/stdc++.h>

// StockSpanner() Initializes the object of the class.
// int next(int price) Returns the span of the stock's price given that today's price is price.

// ["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
// [[], [100], [80], [60], [70], [60], [75], [85]]
// Output
// [null, 1, 1, 1, 2, 1, 4, 6]

class StockSpanner {
    stack<int> s1,s2; //tle
    stack<pair<int,int>>s3; //price,day
public:
    int next(int price) {
        if(s3.empty()){
            s3.push({price,1});
            return 1;
        }
        pair<int,int> prev = s3.top();
        if(price==prev.first){
            s3.pop();
            s3.push({price,prev.second+1});
            return prev.second+1;
        }
        else if(price>prev.first){
            int count = 1.;
            while(!s3.empty() and price>=s3.top().first){
                count+=s3.top().second;
                s3.pop();
                
            }
            s3.push({price,count});
            return count;
        }
        else{
            s3.push({price,1});
            return 1;
        }
        
    }
};