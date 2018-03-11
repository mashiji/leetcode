def reverseWords(s):  
    L = s.split() #单词拆分成列表  
    print "字符串以单词分割成列表: %s" % L  
    L.reverse()#反转列表中单词  
    print "反转列表中的单词: %s" % L  
    s1 = ' '.join(L)#列表以空格分割单词，返回字符串  
    print "以空格分隔列表中反转后的单词: %s" % s1  
    return s1  
    #return s1.rstrip()#字符串删除首尾空格和回车  




class Solution(object):  
    def reverseWords(self, s):  
        """ 
        :type s: str 
        :rtype: str 
        """  
        rs=s[::-1] #将整个字符串反转  
        l=rs.split() #将反转后的字符串通过split()函数进行分割，产生的单词发在列表l中  
        ls=[word[::-1] for word in l] #使用列表解析，反转列表l中的每一个单词  
        return ' '.join(ls)  #使用join()函数，将列表ls中的单词，通过空格连接成一个字符串
