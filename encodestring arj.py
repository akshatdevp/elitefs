dp={}
def func(s):
    global dp
    if s not in dp:
        i = (s*2).find(s, 1)
        #print(s)
        #print(i)
        if i<len(s):
            s1=str(int(len(s)/i))+'['+func(s[:i])+']'#encoding given string
            print(s1)
        else:
            s1=s
        m = [func(s[:i]) + func(s[i:]) for i in range(1, len(s))]#solving subproblems
        print(m)
        dp[s]=min([s,s1]+m,key=len)
        print (dp[s])#finding minimum length string among achieved strings
    return dp[s]
print(func(input()))
#ababab
#
