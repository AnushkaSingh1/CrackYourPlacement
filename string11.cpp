class Solution {
   public:
    int calculate(string s) {
        stack<int> equation;
        istringstream iss(s);

        int value;
        char op = '+';
        while (iss >> value) {
            if (op == '+') {
                equation.push(value);
            } else if (op == '-') {
                equation.push(-value);
            } else {
                int prev = equation.top();
                equation.pop();
                if (op == '*') {
                    prev = prev * value;
                } else {
                    prev = prev / value;
                }
                equation.push(prev);
            }

            iss >> op;
        }

        int sum = 0;
        while (!equation.empty()) {
            sum += equation.top();
            equation.pop();
        }

        return sum;
    }
};










227. Basic Calculator II
Medium

4798

614

Add to List

Share
Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "3+2*2"
Output: 7
Example 2:

Input: s = " 3/2 "
Output: 1
Example 3:

Input: s = " 3+5 / 2 "
Output: 5
 

Constraints:

1 <= s.length <= 3 * 105
s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
s represents a valid expression.
All the integers in the expression are non-negative integers in the range [0, 231 - 1].
The answer is guaranteed to fit in a 32-bit integer.

























