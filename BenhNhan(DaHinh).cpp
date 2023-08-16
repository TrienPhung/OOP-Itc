#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
class BenhNhan{
	private:
		string ma,hvt,ns,benh;
		int soTT;
	public:
		virtual void import(){
			fflush(stdin);
			cout << "[-]Nhap ma ho so: ";
			getline(cin,this->ma);
			cout << "[-]Nhap ho va ten: ";
			getline(cin,this->hvt);
			cout << "[-]Nhap ngay sinh(dd/mm/yyyy): ";
			getline(cin,this->ns);
			cout << "[-]Nhap chuan doan benh: ";
			getline(cin,this->benh);
		}
		void setSoTT(int count){
			this->soTT = count;
		}
		int getSoTT(){
			return this->soTT;
		}
		string getNs(){
			return this->ns;
		}
		virtual void display(){
			cout << "\t\t[+]Ma ho so: " << this-> ma << endl;
			cout << "\t\t[+]Ho va ten: " << this->hvt << endl;
			cout << "\t\t[+]Ngay sinh: " << this->ns << endl; 
			cout << "\t\t[+]Chuan doan benh: " << this->benh << endl;
		}
		virtual bool check(string x) = 0;
};
vector<int> chuyenDoi(string s){
		stringstream ss(s);
		string ans = "";
		vector<string> result;
		while(getline(ss,ans,'/')){
			result.push_back(ans);
		}
		vector<int> a(result.size());
		for(int i = 0 ; i < result.size();i++){
			a[i] = stoi(result[i]);
 	}
 	return a;
}
class BenhNhanNoiTru : public BenhNhan{
	private:
		string nnv,nrv,khoa;
		int soGiuong;
	public:
		void import(){
			BenhNhan::import();
			cout << "[-]Nhap ngay nhap vien(dd/mm/yyyy): ";
			getline(cin,this->nnv);
			cout << "[-]Nhap ngay ra vien(dd/mm/yyyy): ";
			getline(cin,this->nrv);
			cout << "[-]Nhap ten khoa: ";
			getline(cin,this->khoa);
			cout << "[-]Nhap so giuong: ";
			cin >> this->soGiuong;
		}
		void display(){
			cout << "\t[-]Thong tin benh nhan noi tru thu " << getSoTT() << endl;
			BenhNhan::display();
			cout << "\t\t[+]Ngay nhap vien: " << this->nnv << endl;
			cout << "\t\t[+]Ngay ra vien: " << this->nrv << endl;
			cout << "\t\t[+]Ten khoa: " << this->khoa << endl;
			cout << "\t\t[+]So giuong: " << this->soGiuong << endl;
		}
		bool check(string x){
			vector<int> token = chuyenDoi(getNs());
			vector<int> X = chuyenDoi(x);
			if(token[2] > X[2]) return true;
			else if (token[1] > X[1]) return true;
			else if (token[0] > X[0]) return true;
			return false;
		} 
};
class BenhNhanNgoaiTru : public BenhNhan{
	private:
		string ngayChuyen,noiChuyen;

	public:
		void import(){
			BenhNhan::import();
			cout << "[-]Nhap ngay chuyen(dd/mm/yyyy): ";
			getline(cin,ngayChuyen);
			cout << "[-]Nhap noi chuyen: ";
			getline(cin,noiChuyen);
		}

		void display(){
			cout << "\t[-]Thong tin benh nhan ngoai tru thu " << getSoTT() << endl;
			BenhNhan::display();
			cout << "\t\t[+]Ngay chuyen: " << this-> ngayChuyen << endl;
			cout << "\t\t[+]Noi chuyen: " << this->noiChuyen << endl;
		}
		bool check(string x){
			vector<int> token = chuyenDoi(getNs());
			vector<int> X = chuyenDoi(x);
			if(token[2] > X[2]) return true;
			else if (token[1] > X[1]) return true;
			else if (token[0] > X[0]) return true;
			return false;
		} 
};
class List_BenhNhan{
	private:
		vector<BenhNhan*> list;
	public:
		List_BenhNhan(){}
		void import(int n, int m){
			cout << "\t\t\tNHAP DANH SACH BENH NHAN NOI TRU\n";
			for(int i = 0; i < n;i++){
				cout << "[-]Nhap thong tin benh nhan noi tru thu " << i + 1 << endl;
				BenhNhan *noiTru  = new BenhNhanNoiTru();
				noiTru->import();
				noiTru->setSoTT(i+1);
				list.push_back(noiTru);
			}
			cout << "\t\t\tNHAP DANH SACH BENH NHAN NGOAI TRU\n";
			for(int i = 0; i < m;i++){
				cout << "[-]Nhap thong tin benh nhan ngoai tru thu " << i + 1 << endl;
				BenhNhan*ngoaiTru = new BenhNhanNgoaiTru();
				ngoaiTru->import();
				ngoaiTru->setSoTT(i+1);
				list.push_back(ngoaiTru);
			}
		}
		void display(){
			cout << "\t\t\tDANH SACH BENH NHAN\n";
			for(BenhNhan* bn : list){
				bn->display();
			}
		}
		void soLuongHoSo(string x){
			int countNoiTru = 0, countNgoaiTru = 0;
			for(BenhNhan* bn : list){
				if(bn->check(x)){
					if(dynamic_cast<BenhNhanNoiTru*>(bn) != nullptr){
						countNoiTru++;
					}else if(dynamic_cast<BenhNhanNgoaiTru*>(bn) != nullptr){
						countNgoaiTru++;
					}
				}
			}
			cout << "\n[-]So luong benh nhan noi tru co ngay sinh lon hon: " << x  << " la: " << countNoiTru << endl;
			cout << "[-]So luong benh nhan ngoai tru co ngay sinh lon hon: " << x  << " la: " << countNgoaiTru << endl;
		}
};
int main(){
	cout << "[*]Nhap so luong benh nhan noi tru: ";
	int n; cin >> n;
	cout << "[*]Nhap so luong benh nhan ngoai tru: ";
	int m; cin >> m;
	List_BenhNhan list;
	list.import(n,m);
	list.display();
	cout << "[-]Nhap ngay sinh X: ";
	string x;getline(cin,x);
	list.soLuongHoSo(x);
	return 0;
}


