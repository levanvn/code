#include <bits/stdc++.h>
using namespace std;
main(){
	string s;
	getline(cin,s);
	int h = 0, t = 0;
	for(int i = 0 ;i < s.length(); i++ ){
		if(isupper(s[i])) h++;
		else t++;
	}
	cout << "So chu hoa: "<< h << endl;
	cout << "So chu thuong: " << t << endl;
}
