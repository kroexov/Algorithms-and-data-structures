Fin = open("stack.in")
Fout = open("stack.out", "w")
n=int(Fin.readline())
a=[0]
stack=0
with open('stack.in', 'r') as f:
    commands = f.read().splitlines()
for i in range(1,n+1):
    command= commands[i].split()
    if command[0]=='+':
        val=command[1]
        a.append(0)
        a[stack]=val
        stack+=1;
    if command[0]=='-':
        stack-=1;
        print(a[stack],file=Fout)
Fin.close()
Fout.close()
