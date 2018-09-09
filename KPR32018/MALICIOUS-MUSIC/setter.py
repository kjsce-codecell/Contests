t = int(input())
assert ( 1 <= t <= 100 )
for __ in range(t):
	n, m = map(int, input().split())
	assert ( 1 <= n <= 10**3 )
	assert ( 1 <= m <= n )
	inl = input().split()
	iml = input().split()
	amps = []
	freqs = []
	ampsm = []
	freqsm = []
	c = 0
	for i in range(2*n):
		if i % 2 == 0:
			temp = int(inl[i])
			amps.append(temp)
			assert ( 1 <= temp <= 200 )
		else:
			freqs.append(inl[i])

	for i in range(2*m):
		if i % 2 == 0:
			ampsm.append(int(iml[i]))
		else:
			freqsm.append(iml[i])

	for i in range(len(amps)-m+1):
		for j in range(0, m):
			if(freqs[i+j]!=freqsm[j]):
				break
		else:
			ratio = 0
			for j in range(0, m):
				
				if(amps[i+j]%ampsm[j]):
					break
				if j == 0:
					ratio = amps[i+j]//ampsm[j]
				else:
					if(amps[i+j]//ampsm[j] != ratio):
						break
			else:
				c+=1
	print(c)