/*
problem: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

Solution (Sliding Window): 
1. expand the window untill we get atleast one occurance each of a,b,c.
2. let [L,R] be the current window which satisfy above criteria, then add the product of all the possible starting points & the ending points of the this window
3. continue while next window
*/

class Solution {
public:
    int min(vector<int> &a) {
        return *min_element(a.begin(),a.end());
    }

    int numberOfSubstrings(string s) {
        long long ans=0,l=0;
        vector<int> a(3,0);
        for(int i=0;i<s.size();i++) {
            a[s[i]-'a']++;
            while(l<i && min(a)>0) {
                ans+=(s.size()-i);
                a[s[l++]-'a']--;
            }
        }
        return ans;
    }
};