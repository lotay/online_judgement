#include <stdio.h>
#include <string.h>
typedef struct{
	int code[9];
	char chSeq[9];
	int pos;
	int parentNode;
	char path;
} Node;

Node nodes[362881];
int visited[362881];
int sequences[362881];
int TARGET = 1;
int codes[9] = {40320,4980,720,120,24,6,2,1,0};
int encode(char seq[]){
	int n = 1;
	int tmp[9];
	for(int i=0;i<9;i++){
		int cnt = 0;
		for(int j = i+1;j<9;j++){
			if(seq[i]>seq[j]) cnt++;
		}
		n += cnt*codes[i];
		tmp[i] = cnt;
	}
	for(int i=0;i<9;i++) {
		nodes[n].code[i] = tmp[i];
		nodes[n].chSeq[i] = seq[i];	
	}
	return n;
}

void copyCode(int s,int t){
	for(int i=0;i<9;i++){
		nodes[t].code[i] = nodes[s].code[i];
		nodes[t].chSeq[i] = nodes[s].chSeq[i];	
	}
}

int main(){
	int i=0;
	char ch[9];
	int pos = -1;
	while(i<9) {
		scanf(" %c",ch+i);
		if(ch[i]=='x'){
			pos = i;
			ch[i] = '9';
		}
		i++;
	}
	memset(visited,0,362881);
	int code = encode(ch);
	nodes[code].pos = pos;
	nodes[code].parentNode = 0;
	nodes[code].path = '\0';
	i = 0;
	int j = 1;
	sequences[0] = code;
	while(i<j){
		int nn = sequences[i++];
		visited[nn] = 1;
		if(nn==TARGET) break;
		
		pos = nodes[nn].pos;
		int c1 = nodes[nn].code[pos];
		char cc = nodes[nn].chSeq[pos];
	
		//move left;
		if(pos%3){
			int nPos = pos-1;
			int c2 = nodes[nn].code[nPos];
			int nl = nn + (1+c1-c2)*codes[nPos]-(c1-c2)*codes[pos];
			if(!visited[nl]){
				nodes[nl].pos = nPos;
				copyCode(nn,nl);
				nodes[nl].path = 'l';
				nodes[nl].parentNode = nn;
				nodes[nl].code[pos] = c2;
				nodes[nl].code[nPos] = 1+c1;
				nodes[nl].chSeq[pos] = nodes[nn].chSeq[nPos];
				nodes[nl].chSeq[nPos] = nodes[nn].chSeq[pos];
				sequences[j++] = nl;
			}
			if(nl==TARGET) break;
		}
		//move right;
		if(pos%3!=2){
			int nPos = pos+1;
			int c2 = nodes[nn].code[nPos];
			int nr = nn - (c1-c2)*codes[pos]-(c1-c2-1)*codes[nPos];
			if(!visited[nr]){
				nodes[nr].pos = pos+1;
				copyCode(nn,nr);
				nodes[nr].path = 'r';
				nodes[nr].parentNode = nn;
				nodes[nr].code[pos] = c2;
				nodes[nr].code[nPos] = c1-1;
				nodes[nr].chSeq[pos] = nodes[nn].chSeq[nPos];
				nodes[nr].chSeq[nPos] = nodes[nn].chSeq[pos];
				sequences[j++] = nr;
			}
			if(nr==TARGET) break;
		}
		//move up;
		if(pos>2){
			int nPos = pos-3;
			int cn0 = nodes[nn].code[nPos]+3;
			int cn1 = nodes[nn].code[nPos+1];
			int cn2 = nodes[nn].code[nPos+2];
			int cn3 = nodes[nn].code[nPos+3];
			char cc2 = nodes[nn].chSeq[nPos];
			if(cc2<nodes[nn].chSeq[nPos+1])	cn1 ++;
			else 	cn3 --;
			if(cc2<nodes[nn].chSeq[nPos+2])	cn2 ++;
			else 	cn3 --;
			
			int nu = nn + codes[nPos]* (cn0-nodes[nn].code[nPos])
						+ codes[nPos+1]*(cn1-nodes[nn].code[nPos+1])
						+ codes[nPos+2]*(cn2-nodes[nn].code[nPos+2])
						+ codes[nPos+3]*(cn3-nodes[nn].code[nPos+3]);
			if(!visited[nu]){
				nodes[nu].pos = nPos;
				copyCode(nn,nu);
				nodes[nu].path = 'u';
				nodes[nu].parentNode = nn;
				nodes[nu].code[nPos] = cn0;
				nodes[nu].code[nPos+1] = cn1;
				nodes[nu].code[nPos+2] = cn2;
				nodes[nu].code[nPos+3] = cn3;
				nodes[nu].chSeq[nPos] = nodes[nn].chSeq[pos];
				nodes[nu].chSeq[pos] = nodes[nn].chSeq[nPos];
				sequences[j++] = nu;
			}
			if(nu==TARGET) break;
		}
		
		//move down;
		if(pos<6){
			int nPos = pos+3;
			int cn3 = c1-3;
			int cn0 = nodes[nn].code[nPos];
			int cn1 = nodes[nn].code[pos+1];
			int cn2 = nodes[nn].code[pos+2];
			char cc2 = nodes[nn].chSeq[nPos];
			if(cc2<nodes[nn].chSeq[pos+1])	cn1 --;
			else 	cn0 ++;
			if(cc2<nodes[nn].chSeq[pos+2])	cn2 --;
			else 	cn0 ++;
			
			int nd = nn + codes[pos]* (cn0-nodes[nn].code[pos])
						+ codes[pos+1]*(cn1-nodes[nn].code[pos+1])
						+ codes[pos+2]*(cn2-nodes[nn].code[pos+2])
						+ codes[pos+3]*(cn3-nodes[nn].code[pos+3]);
			if(!visited[nd]){
				nodes[nd].pos = nPos;
				copyCode(nn,nd);
				nodes[nd].path = 'd';
				nodes[nd].parentNode = nn;
				nodes[nd].code[nPos] = cn0;
				nodes[nd].code[nPos+1] = cn1;
				nodes[nd].code[nPos+2] = cn2;
				nodes[nd].code[nPos+3] = cn3;
				nodes[nd].chSeq[nPos] = nodes[nn].chSeq[pos];
				nodes[nd].chSeq[pos] = nodes[nn].chSeq[nPos];
				sequences[j++] = nd;
			}
			if(nd==TARGET) break;
		}
	}
	if(i==j) printf("unsolvable\n");
	else{
		int nn = TARGET;
		char paths[10000];
		int k=1;
		while(nn!=code){
			paths[k++] = nodes[nn].path;
			nn = nodes[nn].parentNode;
		}
		while(--k){
			printf("%c",paths[k]);
		}
		printf("\n");
	}
	
	return 0;
}
