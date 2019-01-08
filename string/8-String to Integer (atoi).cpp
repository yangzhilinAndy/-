class Solution {
public:
    int myAtoi(string str) {
        if (str.empty())
            return 0;
        int len=str.size(),i=0;
        int neg=1;
        while(i<len)
        {
            if (str[i]!=' ')
                break;
            i++;
        }
        if (i==len)
            return 0;
        if (!isdigit(str[i]) && str[i]!='-' && str[i]!='+')
            return 0;
        if ((str[i]=='-' || str[i]=='+') && (i+1==len || !isdigit(str[i+1]))) //先判断是否超出边界再代入数组索引！！！
            return 0;
        
        if (str[i]=='-' || str[i]=='+')
        {
            if (str[i]=='-')
                neg=-1;
            i++;
        }
        
        long int res=str[i++]-'0';
        while(isdigit(str[i]) && res<=(long int)INT_MAX+1)
//注意这里一定要显式转换INT_MAX，否则这里的比较会自动把res转换为int 类型
            res=res*10+str[i++]-'0';
        res*=neg;
        if (res>INT_MAX)
            return INT_MAX;
         if (res<INT_MIN)
             return INT_MIN;
        
        return res;
    }
};
