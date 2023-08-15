#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
class GV{
	private:
		string ht,bc,cn;
		int age;
		float bl;
	public:
		friend istream& operator >> (istream& in, GV&);
		friend ostream& operator << (ostream &out, GV);
		float getLuong();
		string getCn();
		void import_list(GV gv[], int &n);
		void display_list(GV gv[], int n);
		void display_list_2000(GV gv[],int n);
		void display_list_sort(GV gv[],int n);
};
istream& operator >> (istream& in, GV& gv ){
	cout << "Nhap ho va ten: ";
	fflush(stdin);
	getline(in,gv.ht);
	cout << "Nhap tuoi: ";
	in >> gv.age;
	fflush(stdin);
	cout << "Nhap bang cap: ";
	getline(in,gv.bc);
	cout << "Nhap chuyen nganh: ";
	getline(in,gv.cn);
	cout << "Nhap bac luong: ";
	in >> gv.bl;
	return in;
}
float GV:: getLuong(){
	return bl*610;
}
string GV::getCn(){
	return this->cn;
}
ostream& operator << (ostream &out, GV gv){
	out << "\t[+]Ho va ten: " << gv.ht << endl;
	out << "\t[+]Tuoi: " << gv.age << endl;
	out << "\t[+]Bang cap: " << gv.bc << endl;
	out << "\t[+]Chuyen nganh: " << gv.cn << endl;
	out << "\t[+]Bac luong: "<< gv.bl << endl;
	out << "\t[+]Luong co ban: "<< gv.getLuong() << endl;
}
void GV::import_list(GV gv[], int &n){
	for(int i = 0; i < n;i++){
		cout << "[-]Nhap thong tin cho giao vien: " << i + 1 << endl;
		cin >> gv[i];
	}
}

void GV::display_list(GV gv[], int n){
	cout << "\n\t\t\t\t\tDANH SACH GIAO VIEN\n";
	for(int i = 0; i < n;i++){
		cout << "[-]Thong tin giao vien: " << i + 1 << endl;
		cout << gv[i];
	}
}
void GV::display_list_2000(GV gv[],int n){

	cout << "\n\t\t\t\t\tDANH SACH GIAO VIEN CO TIEN LUONG NHO HON 2000\n";
	bool check = false;
	for(int i = 0; i < n;i++){
		if(gv[i].getLuong() < 2000){
			check = true;
			cout << "[-]Thong tin giao vien: " << i + 1 << endl;
			cout << gv[i];
		}
	}
	if(!check){
		cout << "[!]Khong co giao vien nao!" << endl;
	}
}
bool cmp(GV a, GV b){
	return a.getCn() < b.getCn();
}
void GV::display_list_sort(GV gv[],int n){
	sort(gv, gv + n,cmp);
	cout << "\n\t\t\t\t\tDANH SACH GIAO VIEN SAU KHI SAP XEP\n";
	for(int i = 0; i < n;i++){
		cout << "[-]Thong tin giao vien: " << i + 1 << endl;
		cout << gv[i];
	}
}
int main(){
	cout << "[*]Nhap so luong giao vien: ";
	int n;cin >> n;
	GV gv[n];
	gv[n].import_list(gv,n);
	gv[n].display_list(gv,n);
	gv[n].display_list_2000(gv,n);
	gv[n].display_list_sort(gv,n);
	return 0;
}


