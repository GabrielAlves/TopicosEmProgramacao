n, distancia_intermediaria = [int(x) for x in input().split()]
postos = [int(x) for x in input().split()]
nao_consegue = False

for i in range(1, n):
    if postos[i] - postos[i - 1] > distancia_intermediaria:
        nao_consegue = True
        break
    
# distancia entre a linha de chegada e o ultimo posto
if 42195 - postos[i] > distancia_intermediaria:
    nao_consegue = True
    
if nao_consegue:
    print("N")
    
else:
    print("S")