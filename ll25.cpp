class Solution {
bool isIntDec(string s, bool integer = true) {
if(s.length() && (s[0]=='+'||s[0]=='-')) s = s.substr(1); // begins with sign; skip that
return s.length()>0 && // empty not OK
s.find_first_not_of(integer ? "0123456789" : ".0123456789") == string::npos // contains only numbers and optionally a dot
&& (integer || count(s.begin(), s.end(), '.')<2 && s != "."); // if not integer, contains at most 1 dot and is not only a dot
}
public:
bool isNumber(string s) {
size_t e = s.find_first_of("eE"); // split the string at e or E
string mantissa = s.substr(0, e);
bool mantissa_ok = isIntDec(mantissa) || isIntDec(mantissa, false); // mantissa is either integer or decimal
bool exponent_ok = e == string::npos || isIntDec(s.substr(e+1)); // either no exponent or it has to be an integer
return mantissa_ok && exponent_ok;
}
};













65. Valid Number
Hard

791

1369

Add to List

Share
A valid number can be split up into these components (in order):

A decimal number or an integer.
(Optional) An 'e' or 'E', followed by an integer.
A decimal number can be split up into these components (in order):

(Optional) A sign character (either '+' or '-').
One of the following formats:
One or more digits, followed by a dot '.'.
One or more digits, followed by a dot '.', followed by one or more digits.
A dot '.', followed by one or more digits.
An integer can be split up into these components (in order):

(Optional) A sign character (either '+' or '-').
One or more digits.
For example, all the following are valid numbers: ["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"], while the following are not valid numbers: ["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"].

Given a string s, return true if s is a valid number.

 

Example 1:

Input: s = "0"
Output: true
Example 2:

Input: s = "e"
Output: false
Example 3:

Input: s = "."
Output: false
 

Constraints:

1 <= s.length <= 20
s consists of only English letters (both uppercase and lowercase), digits (0-9), plus '+', minus '-', or dot '.'.
