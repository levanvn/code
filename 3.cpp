#include <bits/stdc++.h>
using namespace std;
main(){
	int m,them=0,count =0, k = 0;
	int usd = 10000;;
	cin >> m;
	int x = 30000;
	if(m > 30000) while(x+1000 < m ) them ++;
	
	if(m > 1000){
		int i = 1000;
		while(i+200 < m){
			count ++ ;
			i += 200;
		}
		 k =m -i;
	}
	
//	cout << them <<" " << count << " " << usd << " " << k <<  endl;
	 int kq =  count * 1500 + usd +them *8000 + (k * 15)/2 ;
	cout << kq << " VND" <<endl;
	
}
