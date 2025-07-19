n = int(input())
lista = [int(x) for x in input().split()]
pontos = 1
maior_pontuacao = 1
valor_anterior = lista[0]

for v in range(1, len(lista)):
    if lista[v] == valor_anterior:
        pontos += 1
    
    elif lista[v] != valor_anterior:
        if pontos > maior_pontuacao:
            maior_pontuacao = pontos
        pontos = 1
        valor_anterior = lista[v]
        
    if v == len(lista) - 1:
        if pontos > maior_pontuacao:
            maior_pontuacao = pontos
        
    
print(maior_pontuacao)