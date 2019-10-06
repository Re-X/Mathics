print("PYTHAGOREAN TRIPLETS: \n")


def run():
    ar = []
    y = 1
    x = input("\nEnter the no. of triplets or range of values (initial and final value)\n>>> ")
    for k in range (len(x)):
        if x[k] != ',':
            ar.append(x[k])
    x = "".join(ar)
    l = x.split(" ")
    if(l.count("")>0):
        l.remove("")
    if(not l[0].isdigit() and (l[0] != "inrange" or l[0] != "range")):
        print("Please enter a valid range (initial value must be smaller than final value)")
        return
    elif(not l[0].isdigit() and len(l)<2):
        print("Please enter a valid range (initial value must be smaller than final value)")
        return
    if((l[0] == "inrange" or l[0] == "range")):
        x=l[2]
        y=l[1]
    elif(len(l)>1):
        x=l[1]
        y=l[0]
    if(int(x) < int(y)):
        print("Please enter a valid range (initial value must be smaller than final value)")
    if(not x.isdigit()):
        print("Please enter a valid integer")
        return
    print()
    x=int(x)
    if int(y)>0:
        y=int(y)
    else:
        y=1
    s=0
    for i in range(y, x+1):
        for j in range(1, i+1):
            if(int(((i**2 + j**2)**(1/2)))==((i**2 + j**2)**(1/2))):
                print(i, "\u00b2 + ", j, "\u00b2", " = ", int((i**2 + j**2)**(1/2)), "\u00b2", sep='')

while(1):
    run()
