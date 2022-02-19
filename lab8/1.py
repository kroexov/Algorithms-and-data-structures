fin = open("input.txt","r")
fout = open("output.txt", "w")
n,m=map(int,fin.readline().split())
ar=[]
for i in range(n):
    ar.append([])
    for j in range(n):
        ar[i].append(0)
for i in range(m):
    k,t=map(int,fin.readline().split())
    ar[k-1][t-1]=1
for i in range(n):
    for j in range(n):
        if j==n-1:
            print(ar[i][j],file=fout)
        else:
            print(ar[i][j],end=" ",file=fout)
