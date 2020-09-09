print("---------------- MATRIX DETERMINANT EXPRESSION GENERATOR --------------------")
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
            print(L[i][j] + " "*(9 - len(L[i][j])), end = '')
        print()

def det(L):
    d = 0;
    if(len(L)==1 and len(L[0])==1):
        return L[0][0]
    else:
        for x in range(len(L[0])):
            M = L[1:]
            for y in range(0, len(M)):
                M[y] = M[y][:x] + M[y][x+1:]
            
            if(x%2==0):
                print(" + ", L[0][x], sep = '', end = '*(')
                print(det(M), end = ')')
            else:
                print(" - ", L[0][x], sep = '', end = '*(')
                print(det(M), end = ')')
        return ""

while 1:
    n = int(input("\n>>> "))

    X = Mat(n)
    printMat(X)
    print("\n Determinant Expression:")
    det(X)
    print(";")


