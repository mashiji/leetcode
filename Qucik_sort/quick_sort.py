def partition(s,left,to):
    i=left
    j=to
    value=s[left]
    while(i<j):     
        while(i<j) and (s[j]>=value):
            j=j-1
        s[i]=s[j]
        while(i<j)and (s[i]<=value):
            i=i+1
        s[j]=s[i]
    s[j]=value
    return j

def quick_sort(s,left,to):
    if(left<to):
        k=partition(s,left,to)
        quick_sort(s,left,k-1)
        quick_sort(s,k+1,to)
    return s


s=[11,13,2,8,4,12,13]
print(s)
s1=quick_sort(s,0,len(s)-1)
print(s1)
