## Problem Description
Given a set of digits, you need to find a combination of those digits such that the number of factors of the combination is the minimum possible for the given set of digits. In case two combinations have the same number of factors,which also happens to be the minimum, the smaller number is chosen.


## Constraints
1 < n < 1000.  
Each line will have at most 6 digits
## Input
The first line of the input contains the number of test cases 'n'.  
The following 'n' lines contain space seperated digits.
## Output
For each test case, the output must be a single number in a new line.  
## Example
### Input
6  
1 2  
6 0  
4 7 4  
1 3 7 9  
7 5 4 3 6  
1 2 4  


### Output  
21  
6  
447  
1973  
36457  
241  

### Explanation:
In the first testcase, 12 has 6 factors while 21 has only 4.
