class Solution {
public:
    bool isPalindrome(int x) {

        string str = to_string(x); // typecasting int to string
        reverse(str.begin(), str.end()); // reverse a string
        if(to_string(x) == str) // comparing formal parameter to reverse string
            return true;
        return false;
    }
};






class Solution {
public:
      bool isPalindrome(int x) {
        long rev = 0; //Take reverse variable as long
        long temp = x; //Convert input to long to prevent overflow
        while(temp > 0) //Loop until temp is not more than 0
        {
            rev = (rev * 10) + (temp % 10); //Prepare reverse number
            temp = temp / 10; //Reduce temp to remove processed digit
        }
        
        return rev == (long)x; //Compare input x and rev;
    }
};









class Solution {
public:
     bool isPalindrome(int x) {
        int n=x;
        int rem;
        long int reverse=0;
        while(n!=0){    
            rem=n%10;      
            reverse=reverse*10+rem;    
            n/=10;    
        }    
        if(reverse!=x||x<0){
            return false;
        }
        else{
            return true;
        }
    }
};








Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward.

For example, 121 is a palindrome while 123 is not.
 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 

Constraints:

-231 <= x <= 231 - 1
