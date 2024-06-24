#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define CHARS 20
#define LINES 5

int generalcounter=0;

bool sprawdz(char s1[],char s2[]) {
	int len=0;
	for(int i=0;i<CHARS;i++) {
		if(isalpha(s1[i])!= 0 || isalpha(s2[i])!= 0) {
			len++;
		} else {
			break;
		}
	}
	
	int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0; //10
	int vals[10];
	//Pierwszy ciag
	for(int i=0;i<len;i++) {
		if(s1[i]=='A') { a++; 
		} else if(s1[i]=='B') { b++; 
		} else if(s1[i]=='C') { c++; 
		} else if(s1[i]=='D') { d++;
		} else if(s1[i]=='E') { e++;
		} else if(s1[i]=='F') { f++;
		} else if(s1[i]=='G') { g++;
		} else if(s1[i]=='H') { h++;
		} else if(s1[i]=='I') { i++;
		} else if(s1[i]=='J') { j++; 
		}
	}
	vals[0]=a; vals[1]=b; vals[2]=c; vals[3]=d; vals[4]=e; vals[5]=f; vals[6]=g; vals[7]=h; vals[8]=i; vals[9]=j; 
	int ta=0,tb=0,tc=0,td=0,te=0,tf=0,tg=0,th=0,ti=0,tj=0; 
	//Drugi ciag
	for(int i=0;i<len;i++) {
		if(s2[i]=='A') { ta++; 
		} else if(s2[i]=='B') { tb++; 
		} else if(s2[i]=='C') { tc++; 
		} else if(s2[i]=='D') { td++;
		} else if(s2[i]=='E') { te++;
		} else if(s2[i]=='F') { tf++;
		} else if(s2[i]=='G') { tg++;
		} else if(s2[i]=='H') { th++;
		} else if(s2[i]=='I') { ti++;
		} else if(s2[i]=='J') { tj++; } 
	} 

	//Sprawdz czy ciagi sa anagramami
	if(ta!=vals[0]) { return false; }
	if(tb!=vals[1]) { return false; }
	if(tc!=vals[2]) { return false; }
	if(td!=vals[3]) { return false; }
	if(te!=vals[4]) { return false; }
	if(tf!=vals[5]) { return false; }
	if(tg!=vals[6]) { return false; }
	if(th!=vals[7]) { return false; }
	if(ti!=vals[8]) { return false; }
	if(tj!=vals[9]) { return false; }
	return true;
}

int main(int argc,char *argv[]) {
	FILE *fp = fopen("dane_napisy.txt","rb");
	char line[20],s1[20],s2[20]; 
	if(fp==NULL) {
		printf("Nie mozna otworzyc wskazanego pliku !\n");
		return 0;
	}
	for(int i=0;i<1000;i++) {
		fgets(line,20,fp);
		sscanf(line,"%s %s",s1,s2);
		if(sprawdz(s1,s2)==true) {	
			printf("Wskazane ciagi sa anagramami: %s %s \n",s1,s2);	
		}
	}
	return 0;
}
