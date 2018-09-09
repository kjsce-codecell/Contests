# Problem Statement
Chaitya is a carpenter. His supervisor instructs him to build a right angled triangle where the longest side should be less than or equal to k. The supervisor specifies that all the sides should be an integer. Now Chaitya needs a long rod to build the triangle. Help him find the maximum length of the rod.

## Input:
First line contains T. T testcases follow.  
Each test case contains an integer k which is the upperbound of the length of the longest side.
## Output:
For each testcase, print the desired result. If no triangles are formed, print 0.

## Constraints:
1 <= T <= 1000  
1 <= k <=1000

## Example:
### Input:
1  
20

### Output:
48  
### Explanation:
The supervisor wants the longest side to be of length < = 20   
The triangles that have the longest side <= 20 are as follows:
3 4 5  
8 6 10  
9 12 15  
5 12 13  
15 8 17  
12 16 20  
The perimeters of the above triangles are:  
12  
24  
36  
30  
40  
48  
Hence the output should be 48  
