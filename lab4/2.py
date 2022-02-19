Fin = open("queue.in")
Fout = open("queue.out", "w")
n=int(Fin.readline())
a=[]
queue=0
with open('queue.in', 'r') as f:
    commands = f.read().splitlines()
for i in range(1,n+1):
    command= commands[i].split()
    if command[0]=='+':
        val=command[1]
        a.append(val)
    if command[0]=='-':
        print(a[queue],file=Fout)
        queue+=1
