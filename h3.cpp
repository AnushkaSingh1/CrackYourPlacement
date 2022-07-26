class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> array(n, 0); 
        array[0] = 1;   //First Ugly Number

        //Pointer to the next allowed multiples of 2, 3, 5
        int indexA = 0, indexB = 0, indexC = 0; //Pointer to next allowed multiplier to generate next minimum element containing only factors of A B C, where A = 2, B = 3, C = 5
        //All the pointers points to index 0 of array i.e. value 1.
        
        int nextA, nextB, nextC;
        int mini;
        for(int i=1; i<n; i++){
            nextA = array[indexA]*2;    //Value of next multiple of A (2) --> 1x2
            nextB = array[indexB]*3;    //Value of next multiple of B (3) --> 1x3
            nextC = array[indexC]*5;    //Value of next multiple of C (5) --> 1x5
            mini = min(nextA, min(nextB, nextC));   //Find the minimum to be the next.

            if(nextA==mini) indexA++;   //Go to next multiple.  nextA = 1
            if(nextB==mini) indexB++;   //Go to next multiple.  nextB = 0
            if(nextC==mini) indexC++;   //Go to next multiple.  nextC = 0

            array[i] = mini;
        }

        return array[n-1];
    }
};














An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.

 

Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
 

Constraints:

1 <= n <= 1690
