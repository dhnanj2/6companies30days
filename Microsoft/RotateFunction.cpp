/*
problem: https://leetcode.com/problems/rotate-function/

SOLUTION ALGORITHM

*/

class Solution {
    public:
    int maxRotateFunction(vector<int>& a) {
        int s=accumulate(a.begin(),a.begin()+a.size()-1,0);
        int ws=0;
        for(int i=0;i<a.size();i++) {
            ws+=i*a[i];
        }
        int ans=ws;
        for(int i=a.size()-1;i>=1;i--) {
            ws = ws + s - a[i]*(a.size()-1);
            // cout<<ws<<" ";
            ans=max(ans,ws);
            s+=(a[i]-a[i-1]);
        }
        return ans;
    }
};