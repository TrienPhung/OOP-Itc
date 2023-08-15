#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
struct Date{
	int day,month,year;
};
class QL{
	private:
		string id,l;
		Date date;
		int sl;
		long price;
	public:
		QL(){
			id = l = "";
			sl = 1;
			price = 0;
		}
		friend istream& operator >> (istream &in, QL &ql){
			cout << "\t+Nhap ma o to: ";
			fflush(stdin);
			getline(in,ql.id);
			cout << "\t+Nhap loai o to: ";
			getline(in,ql.l);
			cout << "\t+Nhap ngay: ";
			in >> ql.date.day;
			cout << "\t+Nhap thang: ";
			in >> ql.date.month;
			cout << "\t+Nhap nam: ";
			in >> ql.date.year;
			cout << "\t+Nhap so luong: ";
			in >> ql.sl;
			cout << "\t+Nhap gia cua 1 chiec: ";
			in >> ql.price;
			return in;
		}
		long getTongTien(){
			float vat;
			if(price > 10000){
				vat = 0.1;
			}else if(price > 7000){
				vat = 0.07;
			}else{
				vat = 0.05;
			}
			return sl*price - vat*(sl*price );
		}
		friend ostream& operator << (ostream &out, QL ql){
			out << "\t[+]Ma o to: " << ql.id << endl;
			out << "\t[+]Loai o to: " << ql.l << endl;
			out << "\t[+]Ngay: " << ql.date.day << endl;
			out << "\t[+]Thang: " << ql.date.month << endl;
			out << "\t[+]Nam: " << ql.date.year << endl;
			out << "\t[+]So luong: " << ql.sl << endl;
			out << "\t[+]Gia 1 chiec: " << ql.price << endl;
			out << "\t[+]Tong tien: " << ql.getTongTien() << endl;
		}
		void import_list(QL a[], int n){
			cout << "\n\t\t\t\t\tNHAP DANH SACH QUAN LY\n";
			for(int i = 0; i < n ;i++){
				cout << "-Nhap thong tin cho quan ly thu " << i + 1 << endl;
				cin >> a[i];
			}
		}
		void display_list(QL a[], int n){
			cout << "\n\t\t\t\t\tXUAT DANH SACH  QUAN LY\n";
			for(int i = 0; i < n ;i++){
				cout << "-Thong tin cho quan ly thu " << i + 1 << endl;
				cout << a[i];
			}
		}
		bool operator > (QL other){
			return this-> getTongTien() > other.getTongTien();
		}
		void sort(QL a[],int n){
			cout << "\n\t\t\t\t\tDANH SACH QUAN LY SAU KHI SAP XEP\n";
			for(int i = 0;  i< n - 1; i++){
				for(int j = 1; j < n;j++){
					if(a[i] > a[j]) swap(a[i], a[j]);
				}
			}
			for(int i = 0; i < n ;i++){
				cout << "-Thong tin cho quan ly thu " << i + 1 << endl;
				cout << a[i];
			}
		}
	 	bool check(QL a[], int n){
	 		for(int i = 0; i < n;i++){
	 			if(a[n].l == "s"){
	 				return false;
				 }
			 }
			 return true;
		 }
		void oto(QL a[], int& n){
			bool check = false;
			for(int i = 0; i < n;i++){
				if(a[i].l == "s"){
					cout << a[i];
					check = true;
				}
			}
			if(!check){
				cout << "\n[*]Nhap them quan ly: \n";
				QL ql;
				cin >> ql;
				a[n] = ql;
				n++;
				cout << "\n\t\t\t\t\tXUAT DANH SACH  QUAN LY SAU KHI THEM\n";
				for(int i = 0; i < n ;i++){
				cout << "-Thong tin cho quan ly thu " << i + 1 << endl;
				cout << a[i];
				}
			}
		}
};
int main(){
	cout << "\nNhap so luong quan ly: ";
	int n;cin >> n;
	QL a[n];
	a[n].import_list(a,n);
	a[n].display_list(a,n);
	a[n].sort(a,n);
	a[n].oto(a,n);
	return 0;
}


