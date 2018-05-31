#include <bits/stdc++.h>
#include<string>
using namespace std;

void xuly(string &s){
	for(int i = 0 ;i < s.length(); i++){
		// xu ly khoang trong lien nhau
		int j = i +1;
		if(s[i] == 32) { 
			 while ( s[j] == ' ') 	j++;
			 if(i==0) s.replace(i,j-i,""); 
			 else  s.replace(i+1,j-i-1,"");  }
			 
		//xu ly cham, phay lien nhau
		if(s[i] == 44 || s[i] == 46){
			int k = i+1;
			while(s[k] == 44 || s[k] == 46 ){
				//cout << "s[k]: " << s[k] << endl;
				k++;

			}
			if(s[i+1] == 44 || s[i+1] == 46) s.replace(i+1,k-i,""); 
	//		cout << "i: " << i << "  k: " << k << "  k-i: " << k-i << endl;
		
		}
		 
		if(s[s.length()-1] == 32) s.replace(s.length()-1,1,"");
	 	if(s[i] == ' ' && s[i+1] == ',') s.replace(i,1,"");
		if(s[i] == ' ' && s[i+1] == '.') s.replace(i,1,"");
		if(s[i] == '.' && s[i+1] != ' ') s.insert(i+1," ");
		if(s[i] == ',' && s[i+1] != ' ') s.insert(i+1," ");

//	 cout << s << endl; cout  << s.length() <<endl;
	}	
}

// kiem tra da dung yeu cau chua ?
bool kiemtra(string &s){
	for(int i = 0; i < s.length()-1; i++){
		if( (s[i] == 32 && s[i+1] == '.')  ||  (s[i] == 32 && s[i+1] == ',') 
		|| (s[i] == '.' && s[i+1] == ',') || (s[i] == ',' && s[i+1] == '.') ||(s[i] == ',' && s[i+1] == ',') || (s[i] == '.' && s[i+1] == '.')
		) 
		return false;
	}
	return true;
}
main(){
//	string s;
while(true){
	string s;
	getline(cin,s);

	xuly(s);
	while(kiemtra(s) == false) xuly(s);
	cout << s << endl;
}

}
