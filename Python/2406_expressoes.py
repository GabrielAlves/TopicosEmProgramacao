t = int(input())
inverso = {")" : "(", "]" : "[", "}" : "{"}

for i in range(t):
    expressao = input()
    eh_bem_definida = True
    pilha = []

    for char in expressao:
        if char == "(" or char == "[" or char == "{":
            pilha.insert(0, char)

        elif char == "]" or char == ")" or char == "}":
            if len(pilha) != 0:
                if pilha[0] == inverso[char]:
                    pilha.pop(0)
                    continue

            eh_bem_definida = False
            break

    if len(pilha) != 0:
        eh_bem_definida = False

    if eh_bem_definida:
        print("S")

    else:
        print("N")