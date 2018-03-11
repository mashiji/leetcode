//方法一：O(n)时间，并且需要辅助空间O(n)

class Solution {
public:
    void reverseWords(string &s) {//如s为“the sky”
        int n=s.size();
        int i=n-1;
        //辅助字符串存放结果字符串
        string stmp="";//最后为“sky the”
        while(i >= 0)
        {
            while(s[i]==' ' && i>=0)
            {//(1)处理连续有多个空格的情况
                i--;
            }
            if(i<0) break;//s处理完空格,若后续没有单词则应跳出循环
            string wordtmp="";
            for(;i>=0 && s[i]!=' ';i--)
            {//(2)从后往前遍历,每次取得一个单词赋给wordtmp
                wordtmp += s[i];
            }//第一个单词为yks
            //(3)翻转wordtmp,如yks
            reverse(wordtmp.begin(), wordtmp.end());
            if(stmp != "")
            {//(4)在将翻转后的单词加入到stmp之前先加入空格(若非首单词)
                stmp.append(" ");
            }
            stmp.append(wordtmp);//(5)加入到stmp
        }
        s=stmp;
    }
};
//方法二：O(n)时间，不需要辅助空间

//（1）从前往后遍历，依次翻转每个单词 
//（2）翻转整个字符串

class Solution {
public:
    void reverseWords(string &s) {
        int n=s.size();
        int i=0, j=0;
        int start=0;
        while(i<n)
        {
            while(i<n && s[i]==' ') i++;//(1)处理空格
            if(i<n && j>0)
            {//(2)如果处理到非首单词(j>0)，要在其前加入空格
                s[j++]=' ';
            }
            //(3)翻转每个单词
            start=j;
            while(i<n && s[i]!=' ')
            {
                s[j++]=s[i++];
            }
            reverse(s.begin()+start, s.begin()+j);
        }
        s.resize(j);//(4)重置s大小
        reverse(s.begin(), s.end());//(5)翻转整个字符串
    }
};

//方法3：

//利用两个stack，一个表示单词，一个表示句子。当遇到非空格字符时放入单词stack；当遇到空格时将单词
//stack中的字符压入句子stack中（注意：单词此时已经逆序一次），然后仅添加一个空格。最后将句子stack
//依次输出，此时句子逆序。两次逆序的道理同方法1.

class Solution {  
public:  
    void reverseWords(string &s) {  
        stack<int> word;  
        stack<int> sentence;  
        int i = 0;  
          
        while(i <= s.size()){  
            if(i == s.size() || s[i] == ' '){  
                if(!word.empty()){  
                    if(!sentence.empty()){  
                        sentence.push(' ');  
                    }  
                    while(!word.empty()){  
                        sentence.push(word.top());  
                        word.pop();  
                    }  
                }  
            } else{  
                word.push(s[i]);  
            }  
            i++;  
        };  
          
        s.clear();  
        while(!sentence.empty()){  
            s.push_back(sentence.top());  
            sentence.pop();  
        };  
    }  
};  

 
