#include <stdio.h>
#define N 256

int memory[N];
char charMap[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

int getNumber(char chs){
	if(chs>='0'&&chs<='9')	return chs-'0';
	if(chs>='A'&&chs<='F')	return chs-'A'+10;
	return 0;
}

void execute(){
	int a=0,b=0;
	int addr,tmp;
	int i=0;
	while(i<N-16){
		switch(memory[i]){
			case 0:
				addr = memory[i+1]*16+memory[i+2];
				a = memory[addr];
				i+=3;
				break;
			case 1:
				addr = memory[i+1]*16+memory[i+2];
				memory[addr] = a;
				i+=3;
				break;
			case 2:
				tmp = a;
				a = b;
				b = tmp;
				i++;
				break;
			case 3:
				tmp = a+b;
				a = tmp%16;
				b = tmp/16;
				i++;
				break;
			case 4:
				a = (a+1)%16;
				i++;
				break;
			case 5:
				a = (a+15)%16;
				i++;
				break;
			case 6:
				if(!a){
					i = memory[i+1]*16+memory[i+2]; 
				}else{
					i+=3;
				}
				break;
			case 7:
				i = memory[i+1]*16+memory[i+2];
				break;
			case 8: 
				i=N;
				break;
		}
	}
}

int main(){
	char str[N+1];
	while(true){
		gets(str);
		for(int j=0;j<N;j++){
			memory[j] = getNumber(str[j]);
		}
		if(memory[0]==8)	break;
		execute();
		for(int i=0;i<N;i++)	printf("%c",charMap[memory[i]]);
		printf("\n");
	}
	return 0;
}
