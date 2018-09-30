t = int(input())
li = ["A", "C", "F", "D", "G", "B", "E"]
for x in range(t):
    s = int(input())
    print(li[s % 7])
