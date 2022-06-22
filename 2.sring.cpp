Print all the duplicates in the input string

Difficulty Level : Easy
Last Updated : 31 May, 2022
Write an efficient program to print all the duplicates and their counts in the input string 

Method 1: Using hashing
Algorithm: Let input string be “geeksforgeeks” 
1: Construct character count array from the input string.
count[‘e’] = 4 
count[‘g’] = 2 
count[‘k’] = 2 
……
2: Print all the indexes from the constructed array which have values greater than 1.
