#include <bits/stdc++.h>
using namespace std;
 string Int2Str( int value)
{
   ostringstream os;
   os << value;
   return os.str();
}

 main(){
 	int n;
 	cin >> n;
 	string s = Int2Str(n);
 //	cout << s << endl;
 	 sort(s.begin(),s.end(), greater<int>());
 	 cout  << s;
 	
 }
