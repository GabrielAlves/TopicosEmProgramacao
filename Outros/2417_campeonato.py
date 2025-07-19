cv, ce, cs, fv, fe, fs = [int(x) for x in input().split()]

pontos_c = 3 * cv + ce
pontos_f = 3 * fv + fe

if pontos_c > pontos_f:
    print("C")
    
elif pontos_c < pontos_f:
    print("F")
    
else:
    if cs > fs:
        print("C")
        
    elif fs > cs:
        print("F")
        
    else:
        print("=")