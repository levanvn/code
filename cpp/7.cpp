#include <bits/stdc++.h>
using namespace std;
int ucln(int x,int y)
{
	while (x!= y)
	{
		if (x > y) x = x - y;
		else y = y - x;
	}
	return x;
}
int bcnn(int x,int y){
	return (x*y)/ucln(x,y);
}
main(){
	int x,y;
	cout << "Nhap x: "  ;cin >> x;
	cout << "Nhap y: "; cin >> y;
	cout << "UCLN: " << ucln(x,y) << endl;
	cout << "BCNN: " << bcnn(x,y);
}
