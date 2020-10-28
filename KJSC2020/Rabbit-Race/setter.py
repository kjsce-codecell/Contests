for _ in range(int(input())):
	(n, s1, s2, hp1, hp2) = tuple(map(int, input().strip().split()))
	ls = tuple(map(int, input().strip().split()))
	wait1 = False; wait2 = False

	n-=1; i = 0; j = 0
	
	if n == 0:
	    win = 'A'; dist = 0
	    print(win, dist)
	    continue
	
	if ls[i] == 0:
		hp1 -= 5
		if hp1 <= 0:
			win = 'B'; dist = 0
			print(win, dist)
			continue
		hp2 -= 5
		if hp2 <= 0:
			win = 'A'; dist = 0
			print(win, dist)
			continue

	while(True):
		if wait1 == False:
			i += s1
			if i >= n:
				dist = n - j
				win = 'A'
				break
			if ls[i] == 0:
				hp1 -= 5
				wait1 = True
			if hp1 <= 0:
				dist = abs(i-j)
				win = 'B'
				break
		else:
			wait1 = False
		
		if wait2 == False:
			j += s2
			if j >= n:
				dist = n - i
				win  = 'B'
				break
			if ls[j] == 0:
				hp2 -= 5
				wait2 = True
			if hp2 <= 0:
				dist = abs(i-j)
				win = 'A'
				break
		else:
			wait2 = False
		
	print(win, dist)