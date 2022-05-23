#include<stdio.h>
#include <stdlib.h>
#include<string.h>

char * timeConversion(char* );

int main() {

    char str[10] = "06:40:03AM";
    int x = atoi(str);
    int num = 00;
    char res[5];
	sprintf(res,"%d",num);
	strcat(res,"0\n");
	printf("%s\n",res);
	//printf("%s",timeConversion(str));
    return 0;
}
/*char * timeConversion(char* s) {
    
     int num = atoi(s);
     int i,j = 0;
     
     char *t;
	 t = malloc(sizeof(char)*2);
	 for(i = strlen(s)-2;i <= strlen(s);i++)
	 {
		t[j] = s[i];
		j++;
	 }
	j = 0;
	 
	 if(strcmp(t,"AM") == 0)
	{
	return s;
	}
     else
	 {
	 	char * s1,* s2;
     	s1 = malloc(sizeof(char)*10);
    	s2 = malloc(sizeof(char)*10);
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
}*/
