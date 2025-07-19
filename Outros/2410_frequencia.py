n = int(input())
registros = set()

for i in range(n):
    v = int(input())
    registros.add(v)
    
print(len(registros))