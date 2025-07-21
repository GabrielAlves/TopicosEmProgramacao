a, b, c = [int(x) for x in input().split()]
h, l = [int(x) for x in input().split()]

if (a <= h and b <= l) or (a <= l and b <= h):
    print ('S')
    
elif (a <= h and c <= l) or (a <= l and c <= h):
    print('S')

elif (b <= h and c <= l) or (b <= l and c <= h):
    print('S')
    
else:
    print('N')