#include <stdio.h>
#define N 50

char boards[N][N];
int n=0,v;
int visited[N][N];
int fixed[N][N];
int row,col;
int direction[4];
int directions[4][2] = {{-2,0},{0,2},{2,0},{0,-2}};		//U,R,D,L
int nDirections[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};	
int tt = 1;
void printBoard(){
	printf("Case %d:\n\n",tt++);
	int m = n*4+1;
	for(int j=0;j<m+2;j++){
		printf("*");
	}
	printf("\n");
	for(int i=0;i<m-4;i++){
		printf("*");
		for(int j=0;j<m;j++)	printf("%c",boards[i][j]);
		printf("*\n");
	}
	for(int j=0;j<m+2;j++){
		printf("*");
	}
	printf("\n\n");
}

void init(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if((j%4==0&&i%4==0)||(i%4==2&&j%4==2)){
				boards[i][j] = 'H';
			}else if(j%4==2&&i%4==0){
				boards[i][j] = 'O';
			}else{
				boards[i][j] = ' ';
			}
		}
	}
}

void reset(){
	int m = n*4+1;
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			if(j%4==2&&i%4==0) continue;
			if((j%4==0&&i%4==0)||(i%4==2&&j%4==2)){
				fixed[i][j] = 0;
			}else{
				boards[i][j] = ' ';
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			visited[i][j] = 0;
	}
}

int test1(int i,int j){
	int r = i*4;
	int c = j*4+2;
	int cnt = 0;
	for(int k=0;k<4;k++){
		if(i==0&&k==0||i==n-1&&k==2){
			continue;
		}
//		printf("i=%d,j=%d ,k:%d r:%d c:%d      %d\n",i,j,k,r+directions[k][0],c+directions[k][1],fixed[r+directions[k][0]][c+directions[k][1]]);
		if(!fixed[r+directions[k][0]][c+directions[k][1]]){
			if(cnt>=2)	return 0;
			direction[cnt++] = k;
		}
	}
//	printf("cnt:%d\n",cnt);
	return cnt==2;
}

int test2(int i,int j){
	//TODO:
	int r = i*4;
	int c = j*4+2;
	int cnt = 0;
	
	int rr = r,cc = c;
	if(i>0){
		rr = r-2;
		cc = c;
		if(!fixed[rr][cc]&&visited[i-1][j]){
			direction[cnt++] = 0;
		}
	}
	if(i<n-1){
		rr = r+2;
		cc = c;
		if(!fixed[rr][cc]&&visited[i+1][j]){
			direction[cnt++] = 2;
		}
	}
	if(j==0){
		direction[cnt++] = 3;
	}else{
		rr = r;
		cc = c-2;
		if(!fixed[rr][cc]&&visited[i][j-1]){
			direction[cnt++] = 3;
		}
	}
	if(j==n-1){
		direction[cnt++] = 1;
	}else{
		rr = r;
		cc = c+2;
		if(!fixed[rr][cc]&&visited[i][j+1]){
			direction[cnt++] = 1;
		}
	}
	if(cnt==1){
		int d = direction[0];
		if(d%2){
			if(!i||fixed[r-2][c]){
				direction[cnt++] = 2;
			}else if(i==(n-1)||fixed[r+2][c]){
				direction[cnt++] = 0;
			}
		}else{
			if(fixed[r][c-2]){
				direction[cnt++] = 1;
			}else if(fixed[r][c+2]){
				direction[cnt++] = 3;
			}
		}
	}
	
	return cnt==2;
}

int select(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(!visited[i][j]){
				if(test1(i,j)||test2(i,j)){
					row = i;
					col = j;
					return 1;
				}
			}
		}
	}
	return 0;
}

int main(){		
	init();
	while(scanf("%d",&n)&&n){
		reset();
		for(int i=0;i<n;i++){
			int r = 4*i;
			for(int j=0;j<n;j++){
				scanf("%d",&v);
				if(!v)	continue;
				int c = 4*j+2;
				if(v<0){
					boards[r-1][c] = boards[r+1][c] = '|';
					fixed[r-2][c] = fixed[r+2][c] = 1; 
				}else if(v>0){
					boards[r][c-1] = boards[r][c+1] = '-';
					fixed[r][c-2] = fixed[r][c+2] = 1; 
				}
				visited[i][j] = 1;
			}
		}
		
		while(select()){
			//set...
			int r = row*4;
			int c = col*4+2;
			visited[row][col] = 1;
			for(int j=0;j<2;j++){
				int t = direction[j];
				char ch = '-';
				if(t%2==0){
					ch = '|';
				}
				boards[r+nDirections[t][0]][c+nDirections[t][1]] = ch;
				fixed[r+directions[t][0]][c+directions[t][1]] = 1;
			}
		}
				
		printBoard();
	}
} 
