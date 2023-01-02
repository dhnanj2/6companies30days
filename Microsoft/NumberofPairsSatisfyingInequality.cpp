/*
problem: https://leetcode.com/problems/number-of-pairs-satisfying-inequality/description/

SOLUTION:

rearrange the required inequality as :-
    ai-bi <= aj - bj + diff;
*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

class Solution {
public:
    long long numberOfPairs(vector<int>& a, vector<int>& b, int diff) {
        ordered_multiset ms;
        long long ans=0;
        for(int i=0;i<a.size();i++) {
            int x=a[i]-b[i]+diff, pos=ms.size();
            int l=0,r=ms.size()-1;
            // find right pos of x in ordered multiset
            while(l<=r) {
                int m=(l+r)/2;
                if(*ms.find_by_order(m)>x) {
                    pos=m;
                    r=m-1;
                }else l=m+1;
            }
            ans+=pos;
            ms.insert(a[i]-b[i]);
        }
        return ans;
    }
};