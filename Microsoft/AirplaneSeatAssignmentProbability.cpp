/*
problem: https://leetcode.com/problems/airplane-seat-assignment-probability/description/

solution: https://leetcode.com/problems/airplane-seat-assignment-probability/solutions/1874330/in-depth-explanation-with-diagrams-and-mathematical-proof/

*/

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        return n==1?1:0.5;
    }
};