#include <stdio.h>
#define R 10
#define C 15

char board[R][C];
int visited[R][C];
int col;
int heights[C];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void initVisited(){
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++) 
			visited[i][j] = 0;
}

int dfs(char ch,int i,int j){
	if(visited[i][j]) return 0;
	visited[i][j] = 1;
	int cnt = 1;
	for(int k=0;k<4;k++){
		int ni = i+dx[k];
		int nj = j+dy[k];
		if(ni<0||nj<0||ni>=heights[nj]||nj>=col||visited[ni][nj]||board[ni][nj]!=ch) continue;
		cnt+= dfs(ch,ni,nj);
	}
	
	return cnt;
}

void label(char ch,int i,int j){
	board[i][j] = 'X';
	for(int k=0;k<4;k++){
		int ni = i+dx[k];
		int nj = j+dy[k];
		if(ni<0||nj<0||ni>=heights[nj]||nj>=col||board[ni][nj]=='X'||board[ni][nj]!=ch) continue;
		label(ch,ni,nj);
	}
}

void printBoard(){
	for(int i=R-1;i>=0;i--){
		for(int j=0;j<C;j++){
			if(j<col&&i<heights[j])
			printf("%c",board[i][j]);
			else printf("X"); 
		}
		printf("\n");
	}
	printf("\n");
}

void update(int r,int c){
	label(board[r][c],r,c);
	int j2=0;
	for(int j1 = 0;j1<col;j1++){
		int i2=0;
		for(int i1=0;i1<heights[j1];i1++){
			if(board[i1][j1]!='X'){
				board[i2++][j2] = board[i1][j1];
			}
		}
		if(i2){
			heights[j2++] = i2;
		}
	}
	col = j2;
}

int main(){
	int t;
	scanf("%d",&t);
	int p = 0;
	char line[20];
	while(p++<t){
		for(int i = R-1;i>=0;i--){
			scanf("%s",line);
			for(int j=0;j<C;j++){
				board[i][j] = line[j];
			}
		}
		
		int total = 0;
		printf("Game %d:\n\n",p);
		int step = 1;
		int left = 150;
		col = C;
		for(int k=0;k<C;k++) heights[k] = R;
		while(1){
			initVisited();
//			printBoard();
			int max = 0;
			int r = 0,c =0;
			for(int j = 0;j<col;j++)
				for(int i=0;i<heights[j];i++){
					if(visited[i][j]) continue;
					if(board[i][j]=='X')	break;
					int cnt = dfs(board[i][j],i,j);
					if(cnt>max){
						max = cnt;
						r = i;
						c = j;
					}
				}
			if(max<2) break;
			int points = (max-2)*(max-2);
			left -= max;
			total += points;
			printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n",step++,(r+1),c+1,max,board[r][c],points);
			update(r,c);
		}
		printf("Final score: %d, with %d balls remaining.\n",total+(left>0?0:1000),left);
		if(p<t) printf("\n");
	}
}

