
t = int(input())
for i in range(t):
    n = int(input()) #Not useful in Python
    notes = list(map(int, input().split()))
    nums = [0, 0, 0, 0, 0, 0, 0, 0] # Index 0 to 7
    for note in notes:
        nums[note - 1] = nums[note - 1] + 1 #Count occurance of each num from 0 to 8

    print(min(nums)) #Final Beauty

    
