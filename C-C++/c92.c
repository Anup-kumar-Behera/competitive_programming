#include<stdio.h>
#include <stdlib.h>
#include<string.h>

char * timeConversion(char* );

int main() {

    char str[10] = "12:40:22AM";
    int x = atoi(str);
	
	 
	printf("%s",timeConversion(str));
    return 0;
}
char * timeConversion(char* s) {
   int num = atoi(s);
     int i,j = 0;
     
     char *t;
     t = malloc(sizeof(char)*2);
     char * s1,* s2;
         s1 = malloc(sizeof(char)*10);
        s2 = malloc(sizeof(char)*10);
     for(i = strlen(s)-2;i <= strlen(s);i++)
     {
        t[j] = s[i];
        j++;
     }
    j = 0;
      
     if(strcmp(t,"AM") == 0 )
    {
        if(num < 12)
            return s;
        else
        {    
        num = 0;
        char *res;
        res = malloc(sizeof(char)*5);
        sprintf(res,"%d",num);
        strcat(res,"0");
        for(i = 2;i < strlen(s)-2;i++)
        {
            s2[j] = s[i];
            j++;
        }
        strcat(res,s2);
        return res;
    }
    }
     else
     {
         
         num = num+12;
         sprintf(s1,"%d",num);

         for(i = 2;i < strlen(s)-2;i++)
        {
            s2[j] = s[i];
            j++;
        }
        strcat(s1,s2);
        return s1;
    }
}
