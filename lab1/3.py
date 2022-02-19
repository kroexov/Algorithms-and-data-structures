Fin = open ( "turtle.in" )
Fout = open ( "turtle.out", "w" )
h, w = map(int, Fin.readline().split())
weight = 0
pole=[]
for i in range(h):
    pole.append(list(map(int, Fin.readline().split())))
for i in range(h-1,-1,-1):
    for j in range(w):
        if i==h-1 and j==0:
            weight=pole[i][j]
        if i==h-1 and j!=0:
            pole[i][j]=pole[i][j-1]+pole[i][j]
        if j==0 and i!=h-1:
            pole[i][j]=pole[i+1][j]+pole[i][j]
        if j!=0 and i!=h-1:
            if pole[i+1][j]>=pole[i][j-1]:
                pole[i][j]=pole[i][j]+pole[i+1][j]
            else:
                pole[i][j]=pole[i][j]+pole[i][j-1]
        if i==0 and j==w-1:
            weight=pole[i][j]
print(weight,file=Fout)
Fout.close()
Fin.close()
