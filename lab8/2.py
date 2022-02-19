fin = open("input.txt","r")
fout = open("output.txt", "w")
matrix="YES"
n=int(fin.readline())
ar=[]
for i in range(n):
    ar.append(list(map(int,fin.readline().split())))
for i in range(n):
    for j in range(n):
        if i==j and ar[i][j]==1:
            matrix="NO"
        if ar[i][j]==1 and ar[j][i]==0:
            matrix="NO"
print(matrix,file=fout)
