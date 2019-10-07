import math

pi = math.pi

def Sort(n):
    n = str(n)
    x = []
    s = 0
    l = 0
    for i in n:
        x.append(i)
    x.sort()
    s = int("".join(x))
    x.sort(reverse = True)
    l = int("".join(x))
    return (s, l)

def diff():
    n = int(input(">>> "))
    a = []    
    t = Sort(n)[1]-Sort(n)[0]
    print(Sort(n)[1],'-',Sort(n)[0],'=',t)
    while t != n:
        print(Sort(t)[1],'-',Sort(t)[0],'=',Sort(t)[1]-Sort(t)[0])
        t = Sort(t)[1]-Sort(t)[0]
        if(a.count(t)>0):
            break
        else:
            a.append(t)
    print("Terminated!!!")

while 1:
    diff()
