def validate(i,d):      
    s=""
    for j in str(i)[::-1]:
        s+=str(d[int(j)])
    return s!=str(i)
        
count=0
def call(d,i,x):
    global count
    if i>x:
        return
    if validate(i,d):
        count+=1
        print(i)
    for j in d.keys():
        call(d,i*10+j,x)

x=int(input())
d={0:0,1:1,6:9,8:8,9:6}
print('validate')
print([validate(i,d) for i in [0,1,6,8,9,11,18]])
for i in [1,6,8,9]:
    if i<x:
        call(d,i,x)
print(count)
