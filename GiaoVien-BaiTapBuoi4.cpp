#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
class GV{
	private:
		string ht,bc,cn;
		int age;
		float bl;
	public:
	 	friend istream& operator >> (istream &in, GV &gv);
		friend ostream& operator << (ostream &out, GV gv);
		float getLuong();
		string getBangCap();
		void import_list(GV gv[], int &n);
		void display_list(GV gv[], int n);
		bool operator == (GV gv);
		void compare_GV(GV gv[]);
		void sort_list(GV gv[] ,int n);
};
istream& operator >> (istream &in,GV& gv){
	cout << "\t+Nhap ho va ten: ";
	fflush(stdin);
	getline(in,gv.ht);
	cout << "\t+Nhap bang cap: ";
	getline(in,gv.bc);
	cout << "\t+Nhap chuyen nganh: ";
	getline(in,gv.cn);
	cout << "\t+Nhap tuoi: ";
	in >> gv.age;
	cout << "\t+Nhap bac luong: ";
	in >> gv.bl;
	return in;
}
ostream& operator << (ostream &out, GV gv){
 	out << "\t[+]Ho va ten: " << gv.ht << endl;
 	out << "\t[+]Bang cap: " << gv.bc << endl;
 	out << "\t[+]Chuyen nganh: " << gv.cn << endl;
 	out << "\t[+]Tuoi: " << gv.age << endl;
 	out << "\t[+]Bac luong: " << gv.bl << endl;
 	out << "\t[+]Luong co ban: " << gv.getLuong() << endl;
 	return out;
 }
float GV::getLuong(){
	return this->bl*610;
}
string GV::getBangCap(){
	return this->bc;
}
void GV::import_list(GV gv[], int &n){
	cout << "\n\t\t\t\t\tNHAP DANH SACH GIAO VIEN\n";
	for(int i = 0;i < n;i++){
		cout << "\n-Nhap thong tin giao vien thu: " << i + 1 << endl;
		cin >> gv[i];
	}
}
void GV::display_list(GV gv[], int n){
	cout << "\n\t\t\t\t\tXUAT DANH SACH GIAO VIEN\n";
	for(int i = 0;i < n;i++){
		cout << "\n[-]Thong tin giao vien thu: " << i + 1 << endl;
		cout << gv[i];
	}
}
string equalsIgnoreCase(string s){
	stringstream ss(s);
	string kq = "";
	string ans = "";
	while(ss >> kq){
		ans += kq;
	}
	string result = "";
	for(int i = 0; i < ans.length();i++){
		 result += tolower(ans[i]);
	}
	return result;
}
bool GV::operator == (GV gv){
	return equalsIgnoreCase(this->getBangCap()) == equalsIgnoreCase(gv.getBangCap());
}
void GV::compare_GV(GV gv[]){
	cout << "\n[*]Nhap 2 giao vien muon so sanh bang cap: "<< endl;
	cout << "\t-Nhap vi tri giao vien thu 1: ";
	int t1; cin >> t1;
	cout << "\t-Nhap vi tri giao vien thu 2: ";
	int t2; cin >> t2;
	if(gv[t1] == gv[t2]) cout << "\t\t--->Giong nhau!";
	else cout << "\t\t--->Khac nhau!";
}
bool cmp(GV a , GV b){
	return a.getBangCap() < b.getBangCap();
}
void GV::sort_list(GV gv[] ,int n){
	sort(gv,gv + n,cmp);
	cout << "\n\t\t\t\t\tDANH SACH GIAO VIEN SAU KHI SAP XEP TANG DAN\n";
	for(int i = 0; i < n;i++){
		cout << "\n[-]Thong tin giao vien thu: " << i + 1 << endl;
		cout << gv[i];
	}
}
int main(){
	cout << "[*]Nhap so luong giao vien: ";
	int n;cin >> n;
	GV gv[n];
	gv[0].import_list(gv,n);
	gv[0].display_list(gv,n);
	gv[0].compare_GV(gv);
	gv[0].sort_list(gv,n); 
	return 0;
}


