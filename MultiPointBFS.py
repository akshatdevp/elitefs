x,y=list(map(int,input().split()))
arr=[]
aux=[[0]*y]*x
for i in range(0,x):
    arr[i].append(list(map(int,input().split())))
print(arr)
