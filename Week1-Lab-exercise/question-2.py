n=input("Enter a String :")
state=0

for i in n:
    if state==0:
        if i=='a':
            state=1
        elif i=='b':
            state=3
        else:
            state=-1
            break
    
    elif state==1:
        if i=='a':
            state=2
        elif i=='b':
            state=3
        else:
            state=-1
            break
        
    elif state==2:
        if i=='a':
            state=2
        elif i=='b':
            state=3
        else:
            state=-1
            break

    elif state==3:
        if i=='a':
            state=1
        elif i=='b':
            state=4
        else:
            state=-1
            break

if state==2 or state==4:
    print("String is Accepted !!")
elif state==-1:
    print("Invalid Token")
else:
    print("String is Not Accepted !!!")