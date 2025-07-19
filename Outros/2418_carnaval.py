notas = [float(x) for x in input().split()]
notas.sort()
print(f"{sum(notas[1:4]):.1f}")