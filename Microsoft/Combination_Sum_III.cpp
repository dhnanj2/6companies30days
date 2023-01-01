/*
problem link: https://leetcode.com/problems/combination-sum-iii/

SOLUTION ALGORITHM:
1. Define a recursive funtion 
*/

class Solution {
public:
    void fun(int k, int n, vector<int> &t, vector<vector<int>> &ans, int x=1) {
        if(x==10 || k==0) {
            if(n==0 && k==0) ans.push_back(t);            
            return;
        }
        if(n>=x) {
            t.push_back(x);
            fun(k-1,n-x,t,ans,x+1);
            t.pop_back();
        }
        fun(k,n,t,ans,x+1);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> t;
        vector<vector<int>> ans;
        fun(k,n,t,ans);
        return ans;
    }
};