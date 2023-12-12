from math import comb

def catalan_number(n):
    return comb(2 * n, n) // (n + 1) # C_n = 2n chooses n divided by n+1

q = int(input())
for i in range(q):
    x_i = int(input())
    print(catalan_number(x_i))
    
