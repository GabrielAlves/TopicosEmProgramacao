dinheiro_inicial, n = [int(x) for x in input().split()]
d, e, f = dinheiro_inicial, dinheiro_inicial, dinheiro_inicial
carteira = {"D" : dinheiro_inicial, "E" : dinheiro_inicial, "F" : dinheiro_inicial} 

for _ in range(n):
    operacao = input().split()
    valor = int(operacao[-1])
    
    if operacao[0] == "C":
        carteira[operacao[1]] -= valor
        
    elif operacao[0] == "V":
        carteira[operacao[1]] += valor
    
    # operacao[0] == "A"
    else:
        carteira[operacao[1]] += valor
        carteira[operacao[2]] -= valor
        
print(f"{carteira['D']} {carteira['E']} {carteira['F']}")