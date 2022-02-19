Fin = open("antiqs.in")
Fout = open("antiqs.out", "w")
n=int(Fin.readline())
left=[1]
right=[2]
if n>2:
    for i in range(3,n+1):
        if i%2==0:
            left.append(i)
            right.append(right.pop(0))
        else:
            right.append(i)
            right[0],right[len(right)-1]=right[len(right)-1],right[0]
for i in range(len(right)):
    left.append(right[i])
for i in range(n):print(left[i],end=" ",file=Fout)
Fin.close()
Fout.close()
