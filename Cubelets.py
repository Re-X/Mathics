print("\n\n\t\t\tCUBE QUADONOMES\n\n")

def main():
    s = []
    x = input(">>> ")
    if(x.count(",")>0):
        s = x.split(",")
    else:
        s = x.split(" ")
    
    if(len(s)>1):
        t = int(s[0])
        n = int(s[1])+1
    else:
        t = 1
        n = int(s[0])
    for i in range(t,n):
        for j in range(1,n):
            for k in range(1,n):
                x = i**3 + j**3 + k**3
                if(int(round(x**(1/3), 14))==round(x**(1/3), 14)):
                    print(str(i)+"\u00b3 +", str(j)+"\u00b3 +", str(k)+"\u00b3 =", str(int(round(x**(1/3), 14)))+"\u00b3")


while(1):
    main()
