## Problem Statement
Vatsal is searching for a new laptop and just like any other programmer, he is confused whether to buy MAC or XPS? Apple and Dell have adopted completely different philosophies in the building of their two laptops. While Apple has gone with a tried and tested aluminium unibody design, Dell has opted for an aluminium lid and carbon fibre coated wrist rest and keyboard tray, with a metal base. The XPS 13 has options for a glorious QHD+ touch display, up to 16GB of RAM and has been refreshed with Intel's latest, 7th-generation Kaby Lake processors. You also get up to 1TB of lightning fast PCIe SSD storage in the XPS 13, though it's easy enough to buy a smaller drive and upgrade it down the line. On the other side, the new Macs haven't moved past Intel's sixth-gen Core processors, they may not actually have much of a speed boost over the Windows competition -- though brand-new AMD graphics may definitely help. Apple claims new MacBook Pros each have twice the graphical power of the ones it released in 2015. But both the laptops have keyboards. And that's what Vatsal is now curious about. Given a list of words he wants to know which of them require at least two rows of United States keyboard layout to type them correctly.


## Input
First line of input contains T, the number of test cases. T lines follow.   
For each testcase, first line contains integer N denoting the number of words in the list.   
Second line of each test case contains N space separated words. The word string will only contain letters of alphabet.  

## Output
For each test case, output the number of words matching the specified condition in the first line.   
Next line should contain the space-separated words which match the specified condition in the same input order.   
If none of the words satisfies the condition, just output 0 and continue.  

## Constraints
1  T  100  
1  N  100000  
1  Length of each word  100  
## Example  
### Input:  
3  
9  
Vatsal loves his Dad or has XPS and MAC   
4  
Aldak had a toy   
9  
God has a lad or is a sad child  

### Output:
6  
Vatsal loves his XPS and MAC   
0  
3  
God is child  
### Explanation
Output words contain alphabets from at least two keyboard rows.   
For the first test case, 6 out of 9 words satisfy the condition.  
