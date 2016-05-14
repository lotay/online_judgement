#include <iostream>
#include <set>
#include <vector>
#include <stack>

using namespace std;

class Directory{
	private:
		string name;
		set<string > files;
		vector<Directory *> directories;
	public:
		Directory(string name){
			this->name = name;
		}
		string &getName(){
			return this->name;
		}
		set<string> & getFiles(){
			return this->files;
		}
		vector<Directory *> &getDirectories(){
			return this->directories;
		}
};

string ROOT = "ROOT";

void printDirectory(Directory *d,int dep){
	if(dep>0){
		for(int i=0;i<dep;i++) cout<<"|     ";
	}
	cout<<d->getName()<<endl;
	for(int i=0;i<d->getDirectories().size();i++){
		printDirectory(d->getDirectories()[i],dep+1);
	}
	set<string>::iterator it = d->getFiles().begin();
	for(;it!=d->getFiles().end();it++){
		for(int j=0;j<dep;j++){
			cout<<"|     ";
		}
		cout<<*it<<endl;
	}
}

int main(){
	char str[200];
	bool c1 = true;
	int t = 1;
	while(c1){
		Directory *root = new Directory(ROOT);
		Directory *curD = root;
		stack<Directory*> stacks;
		cin.getline(str,200);
		string line(str);
		if(line.compare("#")==0) break;
		while(true){
			if(line.compare("*")==0){
				break;
			}
			if(line[0]=='f'){
				curD->getFiles().insert(line);
			}else if(line[0]=='d'){
				Directory *newD = new Directory(line);
				curD->getDirectories().push_back(newD);
				stacks.push(curD);
				curD = newD;
			}else if(line[0]==']'){
				curD = stacks.top();
				stacks.pop();
			}
			cin.getline(str,100);
			string t(str);
			line = t;
		}
		cout<<"DATA SET "<<t++<<":"<<endl;
		printDirectory(root,0);
		cout<<endl;
	}
	return 0;
}
