s=set()
def func(x,i,j):
    global s
    if j==" ":
        s.add(x[i])
    minlen=len(x[0])
    for leftsub in range(minlen,len(x[i])):
        if leftsub<len(j):
            if j[0:leftsub] in x:
                func(x,i,j[leftsub:]) 
x=input().split()
x.sort(key=len)
minlen=len(x[0])
for i,j in enumerate(x):
    if(len(j)<minlen*2):
        continue
    else:
        func(x,i,j+" ")
print(s)
'''
ef
abc
abcd
abcde
abcdabc

cats
dogs
catsdogs
minlen=4
for i,j in x
    func(x,2,catsdogs )
    j==""no
    minlen=4
    leftsub=4,8
    j[0:4] in x? yes
        func(x,i,dogs )
            j==""no
            minlen=4
            leftsub in 4,8
                j from 0 to 4 =dogs
                 func(x,i," ")
                 
'''

