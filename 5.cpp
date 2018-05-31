#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int ngay, thang, nam, ngaymax;
    bool nhuan = false;
    cout<<"Nhap ngay : ";
    cin>>ngay;
    cout<<"Nhap thang : ";
    cin>>thang;
    cout<<"Nhap nam : ";
    cin>>nam;
    if (nam<0 || thang<0 || thang> 12 || ngay<0 || ngay> 31)
    {
        cout<<"Khong hop le";
    }
    else
    {
        switch (thang)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
              ngaymax=31;
              break;
            case 2:
                if ((nam%4==0 && nam%100!=0) || (nam%400==0))
                   { ngaymax=29;
                     nhuan = true;
					} 
                else 
                    ngaymax=28;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                ngaymax=30;
                break;
        }
        cout << ngaymax;
        if (ngay<=ngaymax) {
        	if(nhuan) cout << "Nam nhuan" ;
       		 else
      		  
            cout<<"Ngay hop le !"<<"\n";
        
		}
        else
        {
            cout<<"Ngay khong hop le !"<<"\n";
        }
    }
}
