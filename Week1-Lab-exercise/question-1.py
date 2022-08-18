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
            state=0
        elif i=='b':
            state=2
        else:
            state=-1
            break
            
    elif state==2:
        if i=='a':
            state=3
        elif i=='b':
            state=1
        else:
            state=-1
            break
            
    elif state==3:
        if i=='a':
            state=2
        elif i=='b':
            state=0
        else:
            state=-1
            break
            
if state==0:
    print("String Accepted !!")
elif state==-1:
    print("Invalid Token")
else:
    print("String is Not Accepted !!!")