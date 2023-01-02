/*
problem: https://leetcode.com/problems/perfect-rectangle/description/

SOLUTION:
Let's say that the rectangles form a picture (including the information that whether each grid is covered and how much times the grid is covered. A grid is an 1*1 area where all the vertex of the area have integer coordinates). We want to use a set of values of points to represent this picture.
We may record the value of each points of the picture. When the picture is empty we say that the value of each point is 0. For each rectangle added to this picture, say rectangles[i] = [xi, yi, ai, bi] is added, we do the following operations:
point [xi, yi] has its value +1;
point [xi, bi] has its value -1;
point [ai, yi] has its value -1;
point [ai, bi] has its value +1;
After adding all the rectangles, the result is the set of values of points representing this picture. Let's call it the value representation of this picture. For example, for the examples given in the problem, the value representation should be as follows:
For example 1:
point [1,1] has value 1
point [1,4] has value -1
point [4,1] has value -1
point [4,4] has value 1
all other points have value 0

For example 3:
point [1,1] has value 1
point [1,4] has value -1
point [4,1] has value -1
point [4,4] has value 1
point [2,2] has value 1
point [2,3] has value -1
point [3,2] has value -1
point [3,3] has value 1
all other points have value 0

The value representation has an important property that it's determined by the final picture and is independent of how you added each part of the picture. It's because that the value representation of a whole rectangle is the same as the value representation of all grids of the rectangle combined. Therefore, to see whether the picture is a perfect rectangle becomes very easy: We just see whether there are only 4 points having nonzero value and whether their values are +1 or -1.
Use structure like unordered_map, the complexity is O(n). The following code is easy to understand but costs O(n logn) because I used map rather than unordered_map, since there's no default hash for pair<int, int>:
*/

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_map<long long, int> mark;
        const long long N=1000000;
        for(vector<int>& x:rectangles){
            int x1=x[0];
            int y1=x[1];
            int x2=x[2];
            int y2=x[3];
            mark[x1*N+y1]++;
            mark[x1*N+y2]--;
            mark[x2*N+y1]--;
            mark[x2*N+y2]++;
        }
        int n_mark=0;
        for(auto ptr=mark.begin();ptr!=mark.end();ptr++)
            if(ptr->second!=0){
                if(abs(ptr->second)!=1) return false;
                n_mark++;
            }
        return n_mark==4;
    }
};