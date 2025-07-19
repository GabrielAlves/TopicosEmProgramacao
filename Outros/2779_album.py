n = int(input())
m = int(input())
figurinhas = set()

for i in range(m):
    x = int(input())
    figurinhas.add(x)
    
print(n - len(figurinhas))