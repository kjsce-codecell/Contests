# B W
# def brute(t):
#     si = [9]*17
#     graph = {
#         "A": ["B", "A"],
#         "B": ["D", "C"],
#         "C": ["E", "D"],
#         "D": ["C", "F"],
#         "E": ["G", "G"],
#         "F": ["A", "E"],
#         "G": ["F", "B"]
#     }
#     li = list(graph.keys())
#     nli = [[1, 0], [3, 2], [4, 3], [2, 5], [6, 6], [0, 4], [5, 1]]
#     for x in range(t):
#         start = 0
#         for i in si:
#             for _ in range(i):
#                 start = nli[start][0]
#             start = nli[start][1]
#         print(li[start])


t = int(input())
li = ["A", "C", "F", "D", "G", "B", "E"]
for x in range(t):
    s = int(input())
    print(li[s % 7])
