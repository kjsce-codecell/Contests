## Problem Statement
Showndarya is participating in a House of Cards competition. She is provided with k cards and an array of n elements. The rules for building the House of Cards are:  

* The length of every level of the house must be an integer from the given array.
* No two levels will have the same length.
* The house must be built using only the k cards provided and not more.  

Your task is to find out the maximum number of cards she can use, to build the tallest house as per the rules.

## Input:
First line contains T. T testcases follow.  
Each test case contains 2 integers, n and k denoting the number of elements in the array and the no of cards provided respectively.  
Second line of each test case contains n integers Ai.  
## Output:
For each testcase, print the desired result.   

## Constraints:
1 <= T <= 10  
1 <= k <=106  
1 <= Ai <=104  
1 <= n <=100  

## Example:  
### Input:  
1  
5 37  
5 4 1 7 3  
### Output:
34  

### Explanation
The no of cards to be used is 37 And each level of the house can only be of length given in the array.  
The tallest house that can be built is of height 4 Lengths of each level of the house from base to top is 5,4,3,1.  
Therefore no of cards used is 5*2+4*3+3*3+1*3=34  
