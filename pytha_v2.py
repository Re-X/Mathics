'''                       UNIQUE PYTHOGREAN TRIPLETS'''
k = 0
while(1):
    print('\n\t\t\tUNIQUE PYTHOGREAN TRIPLETS\n\n')
    k = 1
    n = int(input())

    for i in range(1, n+1):
        j=i+1
        a = abs(i**2-(j)**2)
        b = 2*i*(j)
        print(a, "\u00b2 + ", b, "\u00b2", " = ", int((a**2 + b**2)**(1/2)), "\u00b2", sep='')
