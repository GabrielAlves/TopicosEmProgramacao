n = int(input())
valores = [int(x) for x in input().split()]
v1 = valores[0]
v2 = sum(valores[1:])

i = 1
while v1 != v2:
    v1 += valores[i]
    v2 -= valores[i]
    i += 1
    
print(i)