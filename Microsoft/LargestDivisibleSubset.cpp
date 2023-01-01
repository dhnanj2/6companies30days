/*
problem: https://leetcode.com/problems/largest-divisible-subset/description/

SOLUTION ALGORITHM
1. We will first sort our vector so that when we are traversing the array, we will always know that the divisor for current element (at index i )lies on the left side of the array i.e. at position less that i.

2. So, we just need to change this one condition in LIS (Longest Increasing Subsequence) algorithm. We need to find the longest increasing subsequence keeping in mind that the current element is getting divided by the last element of previously longest increasing subsequence (I will give the proof of correctness at the end of the code if some people are eager to know more about it)

3. I will keep the track of previous index for any current index in a LIS as it will help us in generating the sequence itself.
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& a) {
        sort(a.begin(),a.end());
        int n=a.size(),mx=1,st=0,nxt=-1;
        vector<int> dp(n,1),trace(n,-1);
        for(int i=n-1;i>=0;i--) {
            for(int j=i+1;j<n;j++) {
                if(a[j]%a[i]==0 && dp[j]+1>dp[i]) {
                    dp[i]=dp[j]+1;
                    nxt=j;
                }
                if(dp[i]>1) {
                    trace[i]=nxt;                    
                }
                if(dp[i]>mx) {
                    mx=dp[i];
                    st=i;
                }
            }
        }
        vector<int> ans;
        while(st>=0) {
            ans.push_back(a[st]);
            st = trace[st];            
        }
        return ans;
    }
};