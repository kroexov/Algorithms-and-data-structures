Fout = open("postfix.out", "w")
with open('postfix.in', 'r') as f:
    postfix = f.read().split()
i=0
while(len(postfix)>1):
    if postfix[i]=="+":
        postfix[i]=int(postfix[i-1])+int(postfix[i-2])
        del postfix[i-1]
        del postfix[i-2]
        i=0
    elif postfix[i]=="*":
        postfix[i]=int(postfix[i-1])*int(postfix[i-2])
        del postfix[i-1]
        del postfix[i-2]
        i=0
    elif postfix[i]=="-":
        postfix[i]=int(postfix[i-2])-int(postfix[i-1])
        del postfix[i-1]
        del postfix[i-2]
        i=0
    i+=1
print(postfix[0],file=Fout)
Fout.close()
