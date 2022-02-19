Fout = open("brackets.out", "w")
with open('brackets.in', 'r') as f:
    brackets = f.read().split()
for i in range(len(brackets)):
    good=1
    round=[]
    square=[]
    for j in range(len(brackets[i])):
        if brackets[i][j]=="(":
            round.append(j)
        elif brackets[i][j]=="[":
            square.append(j)
        elif brackets[i][j]==")":
            if not round:
                print('NO',file=Fout)
                good=0
                break
            elif not square:
                round=round[:-1]
            elif round[-1]>square[-1]:
                round=round[:-1]
            else:
                print('NO',file=Fout)
                good=0
                break
        elif brackets[i][j]=="]":
            if not square:
                print('NO',file=Fout)
                good=0
                break
            if not round:
                square=square[:-1]
            elif square[-1]>round[-1]:
                square=square[:-1]
            else:
                print('NO',file=Fout)
                good=0
                break
    if good==1 and not square and not round:
        print("YES",file=Fout)
    elif good==1 and (square or round):
        print("NO",file=Fout)
Fout.close()
