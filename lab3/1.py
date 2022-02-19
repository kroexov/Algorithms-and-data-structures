Fin = open("isheap.in")
Fout = open("isheap.out", "w")
n=int(Fin.readline())
b=map(int,Fin.readline().split())
a=[0]
a=a+list(b)
heap=1
for i in range(1,n):
    if 2*i<=n:
        if a[i]>a[2*i]:
            heap=0
    if 2*i+1<=n:
        if a[i]>a[2*i+1]:
            heap=0
if heap==1: print("YES",file=Fout)
else: print("NO",file=Fout)
Fin.close()
Fout.close()
