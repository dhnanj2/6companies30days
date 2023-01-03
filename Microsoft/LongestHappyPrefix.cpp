/*
problem: https://leetcode.com/problems/longest-happy-prefix/description/

SOLUTION:
build longest prefix suffix array same as in KMP algorithm and lps[n-1] is required length of the prefix
*/

class Solution {
public:
    vector<int> getLPS(string &pat) {
            int n=pat.size();
            vector<int> lps(n,0);
            int j=0;
            for(int i=1;i<n;i++) {
                while(j>0 && pat[j]!=pat[i]) j=lps[j-1];
                if(pat[i]==pat[j]) lps[i]=++j;
            }
            return lps;
        }

    string longestPrefix(string s) {
        auto lps = getLPS(s);
        return s.substr(0,lps[s.size()-1]);
    }
};