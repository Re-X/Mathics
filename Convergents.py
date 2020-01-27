from time import perf_counter as cn

def sqRoot(n):
    x = n**0.5
    if(x==int(x)):
        return []
    m = 0
    a = int(x)
    b = int(x)
    d = 1
    q = []
    while 1:
        d = (n-(b**2))/d
        a = (x+b)//d
        b = abs(b-(d*a))
        t = (a,b,d)
        if(t in q):
            break
        q.append(t)
    

con = [1]

w = int(input('>>> '))
con = eval(input('Enter reps: '))

t1 = cn()
con = con[::-1]
a = 1
b = con[0]
for i in range(1,len(con)):
    a = a+(b*con[i])
    a,b = b,a

a = str(a+w*b)
print()
print(a,b,sep = '\n'+'-'*len(a)+'\n')
s = 0
for i in a:
    s+=int(i)
print('\n\nValue of convergents is', int(a)/b)
print('time taken:',cn()-t1,'secs')

while 1:
    con = []
