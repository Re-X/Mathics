
print("\n\n\t\t\t\tPRIMES\n\n")

def primes():
    n = int(input("\n>>> "))
    p = []
    for i in range(2, n+1):
        for j in p:
            if(i%j==0):
                break
        else:
            p.append(i)
            print(str(i)+", \t", end = '')
    return p

while(1):
    primes()
    #print(primes())
    

