#include<stdio.h>
#include<string.h>
#include<ctype.h>
void main()
{
	char s[100];
	printf("Enter a string: ");
	fgets(s,sizeof(s),stdin);
	char u[100], l[100];
	int i,j,uc=0,lc=0;
	char temp;
	for(i=0;s[i]!='\0';i++){
		if(isupper(s[i])){
			u[uc]=s[i];
			uc++;
		}else if(islower(s[i])){
			l[lc]=s[i];
			lc++;
		}	
	}
	for(i=0;i<uc;i++){
		for(j=i+1;j<uc;j++){
			if(u[i]>u[j]){
				temp=u[i]		;
				u[i]=u[j];
				u[j]=temp;
			}	
		}
	}
	for(i=0;i<lc;i++){
		for(j=i+1;j<lc;j++){
			if(l[i]>l[j]){
				temp=l[i]		;
				l[i]=l[j];
				l[j]=temp;
			}	
		}
	}
	uc=0,lc=0;
	for(i=0;s[i]!='\0';i++){
		if(isupper(s[i])){
			s[i]=u[uc];
			uc++;
		}else if(islower(s[i])){
			s[i]=l[lc];
			lc++;
		}	
	}
	printf("%s",s);
}
