n = int(input())
sequencia = [int(x) for x in input().split()]
n_escadinhas = 1

if len(sequencia) >= 2:
    diferenca = sequencia[1] - sequencia[0] 

    for i in range(2, len(sequencia)):
        if sequencia[i] - sequencia[i - 1] != diferenca:
            n_escadinhas += 1
            diferenca = sequencia[i] - sequencia[i - 1]

print(n_escadinhas)