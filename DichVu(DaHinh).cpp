#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
class DichVu{
	protected:
		double donGia;
		string loai;
	public:
		virtual void import(){
			fflush(stdin);
			cout << "\t-Nhap loai(san pham cua dich vu): ";
			getline(cin,loai);
			cout << "\t-Nhap don gia: ";
			cin >> donGia;
		}
		virtual void display(){
			cout << "\t\t[+]Loai: " << loai << endl;
			cout << "\t\t[+]Don gia: " << donGia << endl;
		}
		virtual double thanhTien() = 0;
		virtual bool checkDichVu() = 0;
};
class DV_Giat:public DichVu{
	private:
		double kgQuanAo;
		double tienDichVuThem;
	public:
		static string chuanHoa(string s){
			string result = "";
			stringstream ss(s);
			string ans = "";
			while(ss >> ans){
				result += ans + " ";
			}
			result = result.substr(0,result.length() - 1);
			string kq = "";
			for(int i = 0; i < result.length();i++){
				kq += tolower(result[i]);
			}
			return kq;
		}
		void import(){
			DichVu::import();
			cout << "\t-Nhap so kg quan ao: ";
			cin >> kgQuanAo;
			if(chuanHoa(loai) == "ao vest" || chuanHoa(loai) == "ao lua"){
				cout << "\t-Nhap tien dich vu them: ";
				cin >> tienDichVuThem;
			}else{
				this->tienDichVuThem = 0;
			}
		}
		
		double thanhTien(){
			double thanhTien = kgQuanAo * donGia + tienDichVuThem;
			if(kgQuanAo > 5){
				thanhTien = thanhTien*0.95;
			}
			return thanhTien;
		};
		void display(){
			DichVu::display();
			cout << "\t\t[+]So kg quan ao: " << kgQuanAo << endl;
			cout << "\t\t[+]Tien dich vu them: " << tienDichVuThem << fixed << setprecision(0) << " VND "<< endl;
			cout << "\t\t[+]Thanh tien: "<< fixed << setprecision(0) << thanhTien() << " VND " << endl;
		}
		bool checkDichVu(){
			return true;
		};
};
class DV_ThueXe:public DichVu{
	private:
		double soGio;
	public:
		void import(){
			DichVu::import();
			cout << "\t-Nhap so gio thue: ";
			cin >> soGio;
		}
		void display(){
			DichVu::display();
			cout << "\t\t[+]So gio thue: " << soGio << endl;
			cout << "\t\t[+]Thanh tien: "<< fixed << setprecision(0) << thanhTien() << " VND "<< endl;
		}
		double thanhTien(){
			double thanhTien = soGio * donGia;
			if(soGio > 10) thanhTien = thanhTien*0.9;
			return thanhTien;
		}
		bool checkDichVu(){
			return false;
		};
};
class HoaDon{
	private:
		string maHD,maKH,tenKH;
		int n;
		DichVu *cacDichVu[1000];
	public:
		void import(){
			fflush(stdin);
			cout << "-Nhap ma hoa don: ";
			getline(cin,maHD);
			cout << "-Nhap ma khach hang: ";
			getline(cin,maKH);
			cout << "-Nhap ten khach hang: ";
			getline(cin,tenKH);
			cout << "-Nhap so luong dich vu khach hang su dung: ";
			cin >> n;
			int choice;
			for(int i = 0; i < n;i++){
				cout << endl;
				cout << "\t\t[1].Dich Vu Giat."<< endl;
				cout <<	"\t\t[2].Dich Vu Thue Xe."<< endl;
				cout << "\t\t-->Nhap lua chon: ";
				cin >> choice;
				while(choice < 1 || choice > 2){
					cout << "\t[!]Lua chon khong ton tai=>Vui long nhap lai." << endl;
					cout << "\t\t-->Nhap lua chon: ";
			 	 	cin >> choice;
				}
				if(choice == 1){
					cacDichVu[i] = new  DV_Giat();
				}else{
					cacDichVu[i] = new  DV_ThueXe();
				}
				cout << "\t-Nhap thong tin cho dich vu " 
				     << (cacDichVu[i]->checkDichVu() ? "giat":"thue xe")
					 << " thu: " << i + 1 << endl;
			 	cacDichVu[i]->import();
			}
		}
		double tongTienDichVu(){
			double sum = 0.0;
			for(int i = 0; i < n;i++){ 
				sum += cacDichVu[i]->thanhTien();
			}
			return sum;
		}
	 	double tongTienDichVuGiat(){
	 		double sum = 0.0;
	 		for(int i = 0; i < n;i++){
	 			if(cacDichVu[i]->checkDichVu()){
	 				sum += cacDichVu[i]->thanhTien();
				 }
			 }
			 return sum;
		 }
		 double tongTienDichVuThueXe(){
	 		double sum = 0.0;
	 		for(int i = 0; i < n;i++){
	 			if(cacDichVu[i]->checkDichVu() == false){
	 				sum += cacDichVu[i]->thanhTien();
				 }
			 }
			 return sum;
		 }
		void display(){
			cout << "\t[-]Ma hoa don: " << maHD << endl;
			cout << "\t[-]Ma khach hang: " << maKH << endl;
			cout << "\t[-]Ten khach hang: " << tenKH << endl;
			cout << "\t[-]So luong dich vu khach hang su dung: " << n << endl;
			for(int i = 0; i < n; i++){
				cout << "\t-Thong tin cho dich vu " 
				     << (cacDichVu[i]->checkDichVu() ? "giat":"thue xe")
					 << " thu " << i + 1 << endl;
			 	cacDichVu[i]->display();
			}
			cout << "\t[-]Tong tien khach hang phai tra: " << fixed << setprecision(0)<< tongTienDichVu() << " VND "  << endl;
		}
		bool check_DV_Giat(){
			for(int i = 0; i < n;i++){
				if(cacDichVu[i]->checkDichVu() && cacDichVu[i]->thanhTien() > 10000000){
					return true;
				} 
			}
			return false;
		}
};
void nhapHoaDon(HoaDon *cacHoaDon[],int n){
	cout << "\n\t\t\tNHAP DANH SACH HOA DON\n";
	for(int i = 0; i < n;i++){
		cout << "-Nhap thong tin hoa don thu: " << i + 1 << endl;
		cacHoaDon[i]->import();
	}
}
void inHoaDon(HoaDon *cacHoaDon[],int n){
	cout << "\n\t\t\tIN DANH SACH HOA DON\n";
	for(int i = 0; i < n;i++){
		cout << "-Thong tin hoa don thu: " << i + 1 << endl;
		cacHoaDon[i]->display();
	}
}
void tienTungLoaiDV(HoaDon *cacHoaDon[],int n){
	cout << "\n\t\t\tDANH SACH TIEN CUA TUNG LOAI DICH VU\n";
	for(int i = 0; i < n;i++){
		cout << "-Tien cua loai hoa don thu: " << i + 1 << endl;
		cout << "\t[+]Tien dich vu giat: " << cacHoaDon[i]-> tongTienDichVuGiat() << fixed << setprecision(0)<< " VND " << endl;
		cout << "\t[+]Tien dich vu thue xe: " << cacHoaDon[i]-> tongTienDichVuThueXe() << fixed << setprecision(0)<< " VND "  << endl;
	}
}
void tongTienKS(HoaDon *cacHoaDon[],int n){
	cout << "\n\t\t\tTONG TIEN KHACH SAN NHAN DUOC\n";
	double sumMoney = 0.0;
	for(int i = 0; i < n;i++){
		cout <<"[-]Tong tien cua loai hoa don thu: " << i + 1 << " la: "
			<< cacHoaDon[i]->tongTienDichVu() << endl;
		sumMoney +=  cacHoaDon[i]->tongTienDichVu();
	}
	cout << "\n==>Tong tien khach san nhan duoc la: "<< fixed << setprecision(0) << sumMoney << " VND " << endl;
}
void in_DV_Giat(HoaDon *cacHoaDon[],int n){
	cout << "\n\t\t\tDANH SACH DICH VU GIAT CO TIEN > 10TR\n";
	bool check = false;
	for(int i = 0; i < n;i++){
		if(cacHoaDon[i]->check_DV_Giat()){
			cout << "\t[-]Thong tin hoa don thu: " << i + 1 << endl;
			cacHoaDon[i]->display();
			check = true;
		}
	}
	if(!check){
		cout << "\n==>Khong ton tai dich vu giat > 10tr!\n";
	}
}
void menu(){
	cout << endl;
	cout << "\t\t\t*----------------------------M_E_N_U----------------------------*\n";
	cout << "\t\t\t| [1].Nhap hoa don.                                             |\n";
	cout << "\t\t\t| [2].In hoa don.                                               |\n";
	cout << "\t\t\t| [3].Tinh tien cua tung dich vu ma khach su dung.              |\n";
	cout << "\t\t\t| [4].Tinh tong tien khach san duoc nhan.                       |\n";
	cout << "\t\t\t| [5].Loc ra nhung dich vu giat la co tien dich vu > 10 trieu.  |\n";
	cout << "\t\t\t| [0].Ket thuc.                                                 |\n";
	cout << "\t\t\t*-----------------------------E_N_D-----------------------------*\n";
}
void ChuongTrinh(HoaDon *cacHoaDon[],int n){
	int choice;
	while(true){
		system("cls");
		menu();
		cout << "[=>]Nhap lua chon: ";
		cin >> choice;
		switch(choice){
			case 0:
				cout << "-->Ban da thoat chuong trinh." << endl;
				return;
			case 1:
				nhapHoaDon(cacHoaDon,n);
				system("pause");
				break;
			case 2:
				inHoaDon(cacHoaDon,n);
				system("pause");
				break;
			case 3:
				tienTungLoaiDV(cacHoaDon,n);
				system("pause");
				break;
			case 4:
				tongTienKS(cacHoaDon,n);
				system("pause");
				break;
			case 5:
				in_DV_Giat(cacHoaDon,n);
				system("pause");
				break;
			default:
				cout << "[!]Lua chon khong ton tai!" << endl;
				cout << "==>Vui long an enter de nhap lai!" << endl;
				system("pause");
		}
	}
}
int main(){
	cout << "[*]Nhap so luong hoa don: ";
	int n; cin >> n;
	HoaDon *cacHoaDon[n];
	for (int i = 0; i < n; i++) {
    	cacHoaDon[i] = new HoaDon();
	}	
	ChuongTrinh(cacHoaDon,n);
	for (int i = 0; i < n; i++) {
    	delete cacHoaDon[i];
	}
	delete[] cacHoaDon;
	return 0;
}


