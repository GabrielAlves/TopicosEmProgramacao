mapa = [[False for i in range(501)] for i in range(501)]
caiu_de_novo = False

n = int(input())
for i in range(n):
    x, y = [int(x) for x in input().split()]
    
    if mapa[x][y] == False:
        mapa[x][y] = True 
        
    # ja caiu um raio nesse local antes
    else:
        caiu_de_novo = True

if caiu_de_novo:
    print(1)

else:
    print(0)