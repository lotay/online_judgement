#include <iostream> 

using namespace std;

const string CharMorseCodes[26]={".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
const string extendMorseCodes[4] ={"..--","---.",".-.-","----"};
const char extendChars[5] = "_.,?";
int length[101];
char str[101];
char res[101];

string getMorseCode(char ch){
	if(ch>='A'&&ch<='Z') return CharMorseCodes[ch-'A'];
	for(int i=0;i<4;i++){
		if(extendChars[i]==ch) return extendMorseCodes[i];
	}
	return "";
}

char getMorseChar(const string &morseCode){
	for(int i=0;i<26;i++){
		if(CharMorseCodes[i].compare(morseCode)==0){
			return (char)(i+'A');
		}
	}
	
	for(int i=0;i<4;i++){
		if(extendMorseCodes[i].compare(morseCode)==0){
			return extendChars[i];
		}
	}
	return ' ';
}

int main(){
	int n;
	cin>>n;
	int t=0;
	cin.getline(str,101);
	while(t++<n){
		cin.getline(str,101);
		string morseCode = "";
		int i=0;
		for(i=0;str[i]!='\0';i++){
			string mc = getMorseCode(str[i]);
			morseCode+=mc;
			length[i] = mc.size();
		}
		int p =0,j=0;

		for(j=0;j<i;j++){
			res[j] = getMorseChar(morseCode.substr(p,length[i-1-j]));
			p = p+length[i-1-j];
		}
		res[j] = '\0';
		cout<<t<<": "<<res<<endl;
	}
	return 0;
}
