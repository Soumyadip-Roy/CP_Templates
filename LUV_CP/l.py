import math as m

def sqrt(target, precision):
    #newton method
    x = target
    while abs(x**2 - target) >= precision:
        x = x - (x**2 - target)/2/x
    return x
    
n=int(input())
for i in range(n):
    k = float(input())
    print(sqrt(k,10))