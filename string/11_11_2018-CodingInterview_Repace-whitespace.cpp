class Solution {
public:
	void replaceSpace(char *str,int length) {
    int spaces=0,ptr1=length,ptr2;
        if (length==0)
            return;
        for (int i=0; i<length; i++)
            if (isspace(str[i]))
                spaces++;
        ptr2=length+spaces*2;
        while(ptr1>=0)
        {
            if (!isspace(str[ptr1]))
                str[ptr2--]=str[ptr1--];
            else
            {
              str[ptr2]='0';
              str[--ptr2]='2';
              str[--ptr2]='%'; 
              ptr1--;
              ptr2--;
            }
        }    
	}
};
