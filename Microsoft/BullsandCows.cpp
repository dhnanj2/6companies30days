// problem: https://leetcode.com/problems/bulls-and-cows/description/
/*
SOLUTION ALGORITHM:
1. traverse both the strings and count all the matching indices in the two strings in "bulls" variable.
2. Also count the frequency of each non-matching char in "secret" string in an array say "dig".
3. traverse the "guess" string again and for each non matching position having positive frequency 
   in dig array, decrease its frequency by one and increase count of "cows" by one
*/class Solution {
public:
    string getHint(string s, string t) {
        vector<int> dig(10,0);
        int bulls=0,cows=0;
        for(int i=0;i<s.size();i++) {
            if(s[i]==t[i]) bulls++;
            else dig[s[i]-'0']++;
        }
        for(int i=0;i<t.size();i++) {
            if(s[i]==t[i]) continue;
            if(dig[t[i]-'0']) {                
                dig[t[i]-'0']--;
                cows++;
            }
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};