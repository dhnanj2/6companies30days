/*
problem link: https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
Evaluate the expression. Return an integer that represents the value of the expression.

Note that:
The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.
 
Example 1:
Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

Constraints:
1 <= tokens.length <= 104
tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].
*/

class Solution {
public:
    bool isOp(string &s) {
        return s=="+" || s=="-" || s=="*" || s=="/";
    }
    
    long long eval(long long a, long long b, string &op) {
        if(op=="+") return a+b;
        else if(op=="-") return a-b;
        else if(op=="*") return a*b;
        return a/b;
    }

    int evalRPN(vector<string>& s) {
        stack<long long> stk;
        for(auto i=0;i<s.size();i++) {
            if(isOp(s[i])) {
                long long a=stk.top();
                stk.pop();
                long long b=stk.top();
                stk.pop();
                stk.push(eval(b,a,s[i]));
            }else stk.push(stoll(s[i]));
        }
        return stk.top();
    }
};