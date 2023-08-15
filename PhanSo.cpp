#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
class Ps{
	private:
		float tu,mau;
	public :
		friend istream& operator >> (istream& in,Ps&);
		friend ostream& operator << (ostream& out,Ps);
};
istream& operator >> (istream& in,Ps& a){
	cout << "Nhap tu so: ";
	in >> a.tu;
	cout << "Nhap mau so: ";
	in >> a.mau;
	while(a.mau == 0){
		cout << "Vui long nhap lai!";
		cout << "\nNhap mau so: ";
		in >> a.mau;
	}
}
ostream& operator << (ostream& out,Ps a){
	out << "\nPhan so: " << a.tu << "/" << a.mau << endl;
}
int main(){
	Ps a;
	cin >> a;
	cout << a;
	return 0;
}


