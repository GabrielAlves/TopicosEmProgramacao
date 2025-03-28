n = int(input())
movimentos = [int(x) for x in input().split()]
n_mov_feitos = 0
pos = (4, 3)

for movimento in movimentos:
    if movimento == 1:
        pos = (pos[0] + 1, pos[1] + 2)

    elif movimento == 2:
        pos = (pos[0] + 2, pos[1] + 1)

    elif movimento == 3:
        pos = (pos[0] + 2, pos[1] - 1)

    elif movimento == 4:
        pos = (pos[0] + 1, pos[1] - 2)

    elif movimento == 5:
        pos = (pos[0] - 1, pos[1] - 2)

    elif movimento == 6:
        pos = (pos[0] - 2, pos[1] - 1)

    elif movimento == 7:
        pos = (pos[0] - 2, pos[1] + 1)  

    elif movimento == 8:
        pos = (pos[0] - 1, pos[1] + 2)

    n_mov_feitos += 1

    if pos == (1, 3) or pos == (2, 3) or pos == (2, 5) or pos == (5, 4):
        break

print(n_mov_feitos)