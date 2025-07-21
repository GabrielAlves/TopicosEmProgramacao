n, n_fig_carimbadas, n_fig_compradas = [int(x) for x in input().split()]
fig_carimbadas = [int(x) for x in input().split()]
fig_compradas = set([int(x) for x in input().split()])

n_faltam = len(fig_carimbadas)

for fig in fig_compradas:
    if fig in fig_carimbadas:
        n_faltam -= 1

print(n_faltam)
