- Tags : Easy, Implementation , Strings

# Problem Name

    Malicious Music

# Problem Definition :

X is a musician who writes his music as a sequence of numbers and lowercase letters, where the letters represent the frequencies of the tones, and each letter is preceded by a positive integer **A<sub>i</sub>** which is the amplitude of that tone. For example a song could be 9s 5a 7q 6e 5b 1a. He recently found out that his enemy Y has added a few malicious sequences, which produce an unpleasant noise when played together, in between X's sequence to sabotage his work. Luckily X was able to deduce the base sequence of Y's tones and plans to remove them from his music. All integral multiples of the base sequence must also be removed. For example if 2a 3b is the base sequence to be removed then 4a 12b must also be removed. If **N** is the length of the entire music sequence and **M** is the length of Y's malicious sequence, find the number of such sequences to be removed.

- Note: Overlapping solutions to be considered

# Constraints :

- 0 < **T** <= 100
- 0 < **N** <= 10<sup>3</sup>
- 0 < **M** <= **N**
- 1 <= **A<sub>i</sub>** <= 200

# Input :

- First line contains **T**, the number of testcases.
- The first line of each testcase line contains two integers, **N** and **M**
- The second line contains **N** space seperated tones, which is the entire musical sequence
- The third line contains **M** space seperated tones, which is the base sequence to be removed

# Output :

- For each testcase output a single integer, the number of removals necessary

# Example :

### Input :

2
7 3
3 a 8 b 2 c 6 m 2 d 11 e 6 f
4 b 1 c 3 m
9 2
1 f 2 a 9 c 10 q 6 m 12 d 3 f 6 a 3 m
1 f 2 a

### Output:

1
2

# Explanation

For the first test case, we only have to remove the sequence 8b 2c 6m, which is 2 times 4b 1c 3m.

In the second testcase we must remove 1f 2a and 3f 6a ( 1f 2a multiplied by 3 ). So the number of removals necessary is 2.

- Time Limit : < 1 sec. >
