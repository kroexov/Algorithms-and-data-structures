def found(pathArr, Tn, Tm):
    weight = 1
    for i in range(len(pathArr)*len(pathArr[0])):
        weight += 1
        for y in range(len(pathArr)):
            for x in range(len(pathArr[y])):
                if pathArr[y][x] == (weight - 1):
                    if y > 0 and pathArr[y-1][x] == 0:
                        pathArr[y-1][x] = weight
                    if y < (len(pathArr)-1) and pathArr[y+1][x] == 0:
                        pathArr[y+1][x] = weight
                    if x > 0 and pathArr[y][x-1] == 0:
                        pathArr[y][x-1] = weight
                    if x < (len(pathArr[y])-1) and pathArr[y][x+1] == 0:
                        pathArr[y][x+1] = weight
                    if (abs(y-Tn) + abs(x-Tm)) == 1:
                        pathArr[Tn][Tm] = weight
                        return weight-1
    return -1
 
def printPath(pathArr, Tn, Tm):
    y = Tn
    x = Tm
    weight = pathArr[y][x]
    result = list(range(weight))
    while (weight):
        weight -=1
        if y > 0 and pathArr[y-1][x] == weight:
            y -= 1
            result[weight] = 'D'
        elif y < (len(pathArr)-1) and pathArr[y+1][x] == weight:
            result[weight] = 'U'
            y += 1
        elif x > 0 and pathArr[y][x-1] == weight:
            result[weight] = 'R'
            x -= 1
        elif x < (len(pathArr[y])-1) and pathArr[y][x+1] == weight:
            result[weight] = 'L'
            x += 1
    return result[1:]
 
fin = open("input.txt","r")
fout = open("output.txt", "w")
n,m=map(int,fin.readline().split())
matrix=[]
for i in range(n):
    matrix.append(list(fin.readline()))
    matrix[i].pop(-1)
for i in range(n):
    for j in range(m):
        if matrix[i][j]==".":
            matrix[i][j]=0
        if matrix[i][j]=="#":
            matrix[i][j]=-1
        if matrix[i][j]=="S":
            Sn=i
            Sm=j
            matrix[i][j]=0
        if matrix[i][j]=="T":
            Tn=i
            Tm=j
            matrix[i][j]=0
path = [ [x if x == 0 else -1 for x in y] for y in matrix ]
path[Sn][Sm] = 1;
print(found(path,Tn,Tm),file=fout)
result = printPath(path,Tn,Tm)
for i in range(len(result)):
    print(result[i],end="",file=fout)
