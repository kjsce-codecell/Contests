n = int(input())

assert(1<=n<=10)
for _ in range(n):
    n = int(input())

    assert(1<=n<=100000)
    nums = list(map(int, input().split()))
    
    for i in nums:
        assert(-10**9 <= i <= 10**9)
    subSum = [nums[0]]
    subInd = [[0,0]]

    #kadenes
    for i in range(1,n):
        if subSum[-1] + nums[i] >= nums[i]:
            subSum.append(subSum[-1] + nums[i])
            subInd.append([subInd[-1][0],i])
        else:
            subSum.append(nums[i])
            subInd.append([i,i])
    
    maxSum = max(subSum)
    maxInd = []
    
    for i in range(len(subInd)):
        if subSum[i] == maxSum:
            maxInd.append(subInd[i])
    
    minVal = 0
    for i in maxInd:
        if i[0] != i[1]:
            temp = min(nums[i[0]:i[1]+1])
            if temp < minVal:
                minVal = temp

    print(maxSum - minVal)
