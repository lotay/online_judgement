#include <iostream>

using namespace std; 

class BitNode{
	public:
	bool isLeaf;
	BitNode *zeroChild ,*oneChild ;
	BitNode(){
		isLeaf = false;
		zeroChild = NULL;
		oneChild = NULL;
	}
};

bool update(BitNode * root,string &word,int idx){
	if(idx>=word.size()) 	return false;
	char ch = word[idx];
	if(ch=='0'){
		if(root->zeroChild!=NULL){
			if(root->zeroChild->isLeaf||idx==word.size()){
				return false;
			}
			return update(root->zeroChild,word,idx+1);
		}else{
			BitNode *node = new BitNode();
			if(idx==word.size()-1){
				node->isLeaf = true;
			}
			root->zeroChild=node;
			update(node,word,idx+1);
			return true;
		}
	}else{
		if(root->oneChild!=NULL){
			if(root->oneChild->isLeaf||idx==word.size()){
				return false;
			}
			return update(root->oneChild,word,idx+1);
		}else{
			BitNode *node = new BitNode();
			if(idx==word.size()-1){
				node->isLeaf = true;
			}
			root->oneChild=node;
			update(node,word,idx+1);
			return true;
		}
	}
}


int main(){
	string str;
	int t = 1;
	bool valid = true;
	BitNode root;
	root.isLeaf = false;
	while(cin>>str){
		if(str.compare("9")==0){
			if(valid){
				cout<<"Set "<<t++<<" is immediately decodable"<<endl;
			}else{
				cout<<"Set "<<t++<<" is not immediately decodable"<<endl;
			}
			root.oneChild = NULL;
			root.zeroChild = NULL;
			valid = true;
		}else if(valid){
			valid = update(&root,str,0);
		}
	}
	
}

