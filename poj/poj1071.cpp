#include <stdio.h>
#define N 105

int m,n;
int boards[N][N];
int preStates[N][N],newStates[N][N];

void reset(){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			boards[i][j] = preStates[i][j] = newStates[i][j] = 0;
		}
	}
}

void resetNew(){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			preStates[i][j] = newStates[i][j];
			newStates[i][j] = 0;
		}
	}
}

int steps[N*10][2];
char directions[N*10];


void printBoard(int states[][N]){
	printf("\n");
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d ",states[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


int main(){
	int t,st;
	int l,h;
	char d;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&m,&n);
//		reset();
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&st);
				boards[i][j] = st;
				preStates[i][j] = !st;
			}
		}
//		printBoard(preStates);
		int s = 0;
		while(1){
			scanf("%d %d",&l,&h);
			if(!l&&!h)	break;
			scanf(" %c\n",&d);
			steps[s][0] = l;
			steps[s][1] = h;
			directions[s] = d;
			s++;
		}
		
		for(int k=s-1;k>=0;k--){
			l = steps[k][0];
			h = steps[k][1];
			d = directions[k];
			for(int i=0;i<m;i++){
				for(int j=0;j<n;j++){
					if(!preStates[i][j]) continue;
					int ii = i;
					int jj = j;
					if(d=='U'&&i+l<m){
						int flag = 1;
						for(;ii<i+l&&ii<m;ii++){
							if(boards[ii][j]){
								flag = 0;
								break;
							}
						}
						if(flag){
							for(;ii<=i+h&&ii<m;ii++){
								if(boards[ii][j])	break;
								newStates[ii][j] |= 1;
							}
						}
					}else if(d=='D'&&i>=l){
						int flag = 1;
						for(;ii>i-l;ii--){
							if(boards[ii][j]){
								flag = 0;
								break;
							}
						}
						if(flag){
//							printf("D: %d %d %d\n",i,j,flag);
							for(;ii>=i-h&&ii>=0;ii--){
								if(boards[ii][j])	break;
								newStates[ii][j] |= 1;
							}
						}
					}else if(d=='L'&&j+l<n){
						int flag = 1;
						for(;jj<j+l&&jj<n;jj++){
							if(boards[i][jj]){
								flag = 0;
								break;
							}
						}
						if(flag){
							for(;jj<=i+h&&jj<n;jj++){
								if(boards[i][jj])	break;
								newStates[i][jj] |= 1;
							}
						}
					}else if(d=='R'&&j>=l){
						int flag = 1;
						for(;jj>j-l&&jj>=0;jj--){
							if(boards[i][jj]){
								flag = 0;
								break;
							}
						}
						if(flag){
//							printf("R: %d %d %d\n",i,j,flag);
							for(;jj>=j-h&&jj>=0;jj--){
								if(boards[i][jj])	break;
								newStates[i][jj] |= 1;
							}
						}
					}
				}
			}
//			printf("sss:%d\n",k);
//			printBoard(preStates);
//			printBoard(newStates);
			resetNew();
		}
//		printBoard(preStates);
		int res = 0;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(preStates[i][j]){
					res++;
				}
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
