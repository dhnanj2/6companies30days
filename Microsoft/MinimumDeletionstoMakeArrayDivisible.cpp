/*
problem: https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/description/

INTUITION: 
find the smallest ai which divides the gcd of numsDivide
*/

class Solution {
public:
    int minOperations(vector<int>& a, vector<int>& numsDivide) {
        int gcd=0;
        for(auto i:numsDivide) gcd = __gcd(gcd,i);
        sort(a.begin(),a.end());
        int i=0;
        while(i<a.size() && gcd%a[i]) i++;
        return i<a.size()?i:-1;        
    }
};