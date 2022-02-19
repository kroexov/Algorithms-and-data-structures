def heapsort(alist):
    build_max_heap(alist)
    for i in range(len(alist) - 1, 0, -1):
        alist[0], alist[i] = alist[i], alist[0]
        max_heapify(alist, index=0, size=i)
def parent(i):
    return (i - 1)//2
def left(i):
    return 2*i + 1
def right(i):
    return 2*i + 2
def build_max_heap(alist):
    length = len(alist)
    start = parent(length - 1)
    while start >= 0:
        max_heapify(alist, index=start, size=length)
        start = start - 1
def max_heapify(alist, index, size):
    l = left(index)
    r = right(index)
    if (l < size and alist[l] > alist[index]):
        largest = l
    else:
        largest = index
    if (r < size and alist[r] > alist[largest]):
        largest = r
    if (largest != index):
        alist[largest], alist[index] = alist[index], alist[largest]
        max_heapify(alist, largest, size)
 
Fin = open("race.in")
Fout = open("race.out", "w")
n=int(Fin.readline())
a=[]
for i in range(n):
    a.append([0,0,0])
for i in range(n):
    str=Fin.readline()
    str=str.split()
    m=str[0]
    l=str[1]
    a[i][0]=m
    a[i][1]=i
    a[i][2]=l
heapsort(a)
for i in range(n):
    if i==0:
        print('=== '+a[i][0]+' ===',file=Fout)
        print(a[i][2],file=Fout)
    elif a[i-1][0]!=a[i][0]:
        print('=== '+a[i][0]+' ===',file=Fout)
        print(a[i][2],file=Fout)
    else:
        print(a[i][2],file=Fout)
