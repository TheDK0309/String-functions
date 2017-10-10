
//string functions
#include <stdio.h>
#include <stdlib.h>

int my_strlen(char *c){ 
	int i;
	for(i=0;c[i]!= '\0';i++);
	return i;
}
void mystrcpy(char *s,char *d){
	int i=0;
    for(i=0;s[i]!='\0';i++){
        d[i]=s[i];
    }
	d[i]='\0';
}
int mystrcmp(char *s, char *d){
	int i = 0;
    while (s[i] == d[i] && s[i])
       i++;
    return s[i] || d[i] ? i : -1;
}
int str2upper(char *s){
	int i,upper=0;
	for(i=0;s[i]!= '\0';i++){
		if(s[i]>='a' && s[i]<='z'){
           s[i]=s[i]-32;
           upper ++;
       }
   }
	return upper;
}
int str2lower_(char *s){
	int i,lower=0;
	for(i=0;s[i]!= '\0';i++){
		if(s[i]>='A' && s[i]<='Z'){
           s[i]=s[i]+32;
           lower ++;
       }
   }
	return lower;
}

int str_strip_numbers(unsigned char *s) {
	int i, j,l=0;
    for(i = 0; s[i] != '\0'; ++i)
    {
        while (s[i]>='0' && s[i]<='9')
        {
            for(j = i; s[j] != '\0'; ++j)
            {
                s[j] = s[j+1];
                
            }
            s[j] = '\0';
        }
    }
   
    for(l=0;s[l]!= '\0';l++);
    return l;
    
}

char * strdupl(char *s){
	char *d;
	d=(char *) malloc(16);
	int i=0;
    for(i=0;s[i]!='\0';i++){
        d[i]=s[i];
    }
	d[i]='\0';
	return d;
}