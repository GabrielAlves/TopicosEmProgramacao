m, n = [int(x) for x in input().split()]
mapa = []

for i in range(m):
    mapa.append(input())

quadrados_na_costa = 0
for i in range(m):
    for j in range(n):
        if mapa[i][j] == "#":
            # verifica se a terra esta na borda do mapa
            if (i == 0 or i == m - 1) or (j == 0 or j == n - 1):
                quadrados_na_costa += 1
                continue

            # verifica se tem agua acima
            if i - 1 >= 0 and mapa[i - 1][j] == ".":
                quadrados_na_costa += 1
                continue
                
            # verifica se tem agua abaixo
            if i + 1 < n and mapa[i + 1][j] == ".":
                quadrados_na_costa += 1
                continue
                
            # verifica se tem agua a esquerda
            if j - 1 >= 0 and mapa[i][j - 1] == ".":
                quadrados_na_costa += 1
                continue
                
            # verifica se tem agua a direita
            if j + 1 < m and mapa[i][j + 1] == ".":
                quadrados_na_costa += 1
                continue

print(quadrados_na_costa)