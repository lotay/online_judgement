#include <stdio.h>
#include <map>
#include <queue>
#include <stack>
#include <set>

using namespace std;
queue<int> boards;
map<int,char> histories;
map<int,int> locations;
stack<int> st;
const int END = 87654321;
int base[10] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
set<int> unValidDiffs;

void init(){
	for(int i=1;i<8;i++){
		for(int j=0;j<i;j++){
			unValidDiffs.insert(base[i]+base[j]);
		}
	}
}

int moveUp(int board,int ti){
	if(ti>=3){
		int v1 = (board%base[ti+1])/base[ti];
		int v2 = (board%base[ti-3+1])/base[ti-3];
		board += (v1-v2)*base[ti-3]+(v2-v1)*base[ti];
		return board;
	}
	return -1;
}

int moveDown(int board,int ti){
	if(ti<6){
		int v1 = (board%base[ti+1])/base[ti];
		int v2 = (board%base[ti+3+1])/base[ti+3];
		board += (v1-v2)*base[ti+3]+(v2-v1)*base[ti];
		return board;
	}
	return -1;
}

int moveLeft(int board,int ti){
	if(ti%3!=0){
		int v1 = (board%base[ti+1])/base[ti];
		int v2 = (board%base[ti])/base[ti-1];
		board += (v1-v2)*base[ti-1]+(v2-v1)*base[ti];
		return board;
	}
	return -1;
}

int moveRight(int board,int ti){
	if(ti%3!=2){
		int v1 = (board%base[ti+1])/base[ti];
		int v2 = (board%base[ti+2])/base[ti+1];
		board += (v1-v2)*base[ti+1]+(v2-v1)*base[ti];
		return board;
	}
	return -1;
}

bool checkValid(int s){
	int cnt = 0,zeroCnt =0;
	int end = END;
	int i = 0;
	while(i++<9){
		if(s%10!=end%10){
			if(!(s%10)){
				zeroCnt ++;
			}
			cnt ++;
		}
		s/=10;
		end/=10;
	}
	return (cnt==2)&&(zeroCnt==0);
}

void printBoard(int s){
	int i= 0;
	while(i++<9){
		printf("%d",s%10);
		s /= 10;
		if(i%3==0) printf("\n");
	}
	printf("\n");
}

int main(){
	int base = 1;
	char ch;
	int s = 0;
	int orL = 0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			scanf(" %c",&ch);
			if(ch!='x')	s += (ch-'0')*base;
			else orL = i*3+j;
			base *= 10;
		}
	}
	if(s==END){
		printf("\n");
		return 0;
	}
	init();
	int origin = s;
	boards.push(s);
	histories[s] = '\0';
	locations[s] = orL;
	int board[9];
	bool solvable = true;
	int v;
	while(!boards.empty()){
		s = boards.front();
		boards.pop();
//		if(unValidDiffs.find(s-END)!=unValidDiffs.end()||(unValidDiffs.find(END-s)!=unValidDiffs.end())){
//		if(checkValid(s)){
//			solvable = false;
//			break;
//		}
		if(END==s) break;
		int l = locations[s];
		v = moveUp(s,l);
		if(v>0&&!histories[v]){
			histories[v] = 'u';
			locations[v] = l-3;
			boards.push(v);
		}
		v = moveDown(s,l);
		if(v>0&&!histories[v]){
			histories[v] = 'd';
			locations[v] = l+3;
			boards.push(v);
		}
		v = moveLeft(s,l);
		if(v>0&&!histories[v]){
			histories[v] = 'l';
			locations[v] = l-1;
			boards.push(v);
		}
		v = moveRight(s,l);
		if(v>0&&!histories[v]){
			histories[v] = 'r';
			locations[v] = l+1;
			boards.push(v);
		}
	}
	
//	if(!solvable||s!=END) printf("unsolvable\n");
//	else {
		char d = histories[s];
		st.push('\0');
		while(s!=origin){
			st.push(d);
			int i = locations[s];			
			if(d=='l'){
				s = moveRight(s,i);
			}else if(d=='r'){
				s = moveLeft(s,i);
			}else if(d=='u'){
				s = moveDown(s,i);
			}else if(d=='d'){
				s = moveUp(s,i);
			}
			d = histories[s];
		}
		while(!st.empty()){
			printf("%c",st.top());
			st.pop();
		}
		printf("\n");
//	}
	return 0;
}
