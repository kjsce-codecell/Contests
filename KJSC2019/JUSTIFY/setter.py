n = int(input())
assert(1<=n<=1000),"n"
for _ in range(n):
  nwrd,lim = map(int, input().split())
  assert(1<=nwrd<=1000),"nwrd"
  assert(3<=lim<=10002),"lim"
  words = []
  wlens = []
  for _ in range(nwrd):
    words.append(input())
  currl = 0
  totwrds = []
  currwrds = []
  for i in range(nwrd):
    currl += len(words[i])
    currl += 1
    if currl <= lim:
      currwrds.append(words[i])
    elif (currl-1) == lim:
      currwrds.append(words[i])
      totwrds.append(currwrds[:])
      currwrds = []
      currl = 0
    else:
      totwrds.append(currwrds[:])
      currwrds = []
      currl = len(words[i])
      currl += 1
      currwrds.append(words[i])
  if len(currwrds) > 0:
    totwrds.append(currwrds)
#   print(totwrds)

  whitespaces = []
  for line in totwrds:
    if len(line) > 1:
      whitespace = []
      totallen = 0
      for i in range(len(line)-1):
        totallen += len(line[i])
        whitespace.append([-len(line[i])-len(line[i+1]),i])
      totallen += len(line[-1])
      whitespace.sort()
      needed = lim - totallen
      numwhite = len(whitespace)
      mini = needed//numwhite
      extra = needed%numwhite
      finwhitespace = [0]*numwhite
      for i in whitespace:
        finwhitespace[i[1]] = mini
        if extra > 0:
          extra -= 1
          finwhitespace[i[1]] += 1
    #   print(finwhitespace)
      whitespaces.append(finwhitespace)
    else:
      whitespaces.append([0])

  for i in range(len(totwrds)):
    answer = []
    for j in range(len(totwrds[i])):
      if j > 0:
        answer.append(" "*whitespaces[i][j-1])
        answer.append(totwrds[i][j])
      else:
        answer.append(totwrds[i][j])
    print("".join(answer))
