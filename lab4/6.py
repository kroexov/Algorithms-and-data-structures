Fin = open("garland.in")
Fout = open("garland.out", "w")
n,a=map(float,Fin.readline().split())
n=int(n)
B=[]
l=0;
B.append(a)
r=B[0]
for i in range(n-1):
    B.append(0)
while(r-l>0.000001):
    B[1]=(l+r)/2
    minus=0
    for i in range(2,n):
        B[i]=2*B[i-1]-B[i-2]+2
        if B[i]<0:
            minus=1
            break
    if minus==0:
        r=B[1]
    else:
        l=B[1]
print("%.2f" % B[n-1],file=Fout)
