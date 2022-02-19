fin = open("input.txt","r")
fout = open("output.txt", "w")
parallel="NO"
n,m=map(int,fin.readline().split())
ar=[]
for i in range(n):
    ar.append([])
    for j in range(n):
        ar[i].append(0)
for i in range(m):
    first,second=map(int,fin.readline().split())
    ar[first-1][second-1]+=1
for i in range(n):
    for j in range(n):
        if ar[i][j]>0 and ar[j][i]>0 or ar[i][j]>1 or ar[j][i]>1:
            parallel="YES"
print(parallel,file=fout)
