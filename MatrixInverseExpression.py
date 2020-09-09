print("------------------ MATRIX INVERSE EXPRESSION GENERATOR ----------------------")
def Mat(n):
    L = []
    for i in range(n):
        L.append([])
        for j in range(n):
            L[-1].append("mat["+str(i*n + j)+"]")
    return L

def printMat(L):
    for i in range(len(L)):
        for j in range(len(L[0])):
            print(str(L[i][j]) + " "*(9 - len(str(L[i][j]))), end = '')
        print()
    print()

def subMat(L, x, y):
    S = []
    
    for i in range(len(L)):
        if(i!=x):
            S.append([])
            for j in range(len(L[0])):
                if(j!=y):
                    S[-1].append(L[i][j])
    
    return S

def det(L, sign = 0):
    d = 0;
    if(len(L)==1 and len(L[0])==1):
        return L[0][0]
    else:
        for x in range(len(L[0])):
            M = L[1:]
            for y in range(0, len(M)):
                M[y] = M[y][:x] + M[y][x+1:]
            
            if(x%2==0):
                if(len(M)>1):
                    print("+" * (1-sign) + "-"*sign, L[0][x], sep = '', end = '*(')
                    print(det(M), end = ')')
                else:
                    print("-"*sign, L[0][x], sep = '', end = '*')
                    print(det(M), end = '')
            else:
                if(len(M)>1):
                    print("-" * (1-sign) + "+"*sign, L[0][x], sep = '', end = '*(')
                    print(det(M), end = ')')
                else:
                    print("-" * (1-sign) + "+"*sign, L[0][x], sep = '', end = '*')
                    print(det(M), end = '')
            
        return ""

def Cofactors(L):
    C = []
    print("Cofactors:")
    for i in range(len(L)):
        for j in range(len(L[0])):
            print(X[i][j], end = ' = ')
            print(det(subMat(L, i, j), (i+j)%2), end = ';\n')

def Inv(L):
    C = []
    print("Inverse matrix:")
    f = 0
    for i in range(len(L)):
        for j in range(len(L[0])):
            if(f%len(L[0])==0):
                print()
            print(X[j][i], end = ' = (')
            print(det(subMat(L, i, j), (i+j)%2), end = ')/det;\n')
            f+=1

while 1:
    n = int(input("\n\nEnter dimension: "))
    X = Mat(n)
    printMat(X)
    Inv(X)

