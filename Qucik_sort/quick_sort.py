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



#算法导论方法

def partition(s,l,r):
    i=l-1
    x=s[r]
    for j in range(l,r):
        if s[j]<=x:
            i=i+1
            s[i],s[j]=s[j],s[i]
    s[i+1],s[r]=s[r],s[i+1]
    return i+1

def quick_sort(s,left,right):
    if(left<right):
        k=partition(s,left,right)
        quick_sort(s,left,k-1)
        quick_sort(s,k+1,right)
    return s


s=[11,13,2,8,4,12,13]
print(s)
s1=quick_sort(s,0,len(s)-1)
print(s1)


#第三种方法
def partition(s,l,r):
    i=l-1
    x=s[r]
    for j in range(l,r):
        if s[j]<=x:
            i=i+1
            s[i],s[j]=s[j],s[i]
    s[i+1],s[r]=s[r],s[i+1]
    return i+1

def quick_sort(s,left,right):
    if(left<right):
        k=partition(s,left,right)
        quick_sort(s,left,k-1)
        quick_sort(s,k+1,right)
    return s


s=[11,13,2,8,4,12,13]
print(s)
s1=quick_sort(s,0,len(s)-1)
print(s1)
