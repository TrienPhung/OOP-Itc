#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
class NhanVien{
	protected:
		int maSo;
	public:
		virtual void nhapThongTin() = 0;
		virtual double tinhLuong() = 0;
		virtual int id_Tyle_Employee() = 0;
		int getMaSo(){
			return maSo;
		}
		void setMaSo(int id){
			maSo = id;
		}
};
class QuanLy : public NhanVien{
	private:
		double luongCoDinh;
	public :
		void nhapThongTin(){
			cout << "-Nhap luong co dinh cho quan ly: ";
			cin >> luongCoDinh;
		}
		double tinhLuong(){
			return luongCoDinh;
		}
		int id_Tyle_Employee(){
			return 1;
		}
};
class CongNhanGio : public NhanVien{
	private:
		double luongCoBanTheoGio;
		double soGioLamViec;
	public:
		void nhapThongTin(){
			cout << "-Nhap luong co ban theo gio: ";
			cin >> luongCoBanTheoGio;
			cout << "-Nhap so gio lam viec: ";
			cin >> soGioLamViec;
		}
		double tinhLuong(){
			double tongLuong = luongCoBanTheoGio*soGioLamViec;
			if(soGioLamViec > 40){
				tongLuong += (soGioLamViec - 40)* (1.5*luongCoBanTheoGio);
			}
			return tongLuong;
		}
		int id_Tyle_Employee(){
			return 2;
		}
};
class CongNhanLoiNhuan : public NhanVien{
	private:
		double luongCoBan;
		double doanhSoBanHang;
	public:
		void nhapThongTin(){
			cout << "-Nhap luong co ban cho cong nhan theo loi nhuan: ";
			cin >> luongCoBan;
			cout << "-Nhap doanh so ban hang: ";
			cin >> doanhSoBanHang;
		}
		double tinhLuong(){
			return luongCoBan*0.07*doanhSoBanHang;
		}
		int id_Tyle_Employee(){
			return 3;
		}
};
class CongNhanSanPham : public NhanVien{
	private:
		double luongTheoSanPham;
		int soSanPhamLamDuoc;
	public:
		void nhapThongTin(){
			cout << "-Nhap luong theo san pham: ";
			cin >> luongTheoSanPham;
			cout << "-Nhap so san pham lam duoc: ";
			cin >> soSanPhamLamDuoc;
		}
		double tinhLuong(){
			return luongTheoSanPham*soSanPhamLamDuoc;
		}
		int id_Tyle_Employee(){
			return 4;
		}
		int getSoSanPhamLamDuoc(){
			return soSanPhamLamDuoc;
		}
};
class List_NhanVien{
	private:
		vector<NhanVien*> list;
		int n;
	public:
		void nhapThongTin(){
			cout << "[*]Nhap so luong nhan vien: ";
			cin >> n;
			int type;
			for(int i = 0; i < n;i++){
				cout << "\t*---------------TYPE---------------*\n";
				cout << "\t|[1].Quan Ly.                      |\n";
				cout <<	"\t|[2].Cong Nhan Lam Theo Gio.       |\n";
				cout << "\t|[3].Cong Nhan Theo Loi Nhuan.     |\n";
				cout << "\t|[4].Cong Nhan Theo San Pham.      |\n";
				cout << "\t*----------------------------------*\n";
				cout << "\t-->Nhap loai nhan vien: ";
				cin >> type;
				NhanVien *nhanVien;
				switch(type){
					case 1:
						nhanVien = new QuanLy();
						break;
					case 2:
						nhanVien = new CongNhanGio();
						break;
					case 3:
						nhanVien = new CongNhanLoiNhuan();
						break;
					case 4:
						nhanVien = new CongNhanSanPham();
						break;
					default:
						cout << "[!]Loai nhan vien khong hop le!"<< endl;
						--i;
						continue;
				}
				nhanVien->setMaSo(i + 1);
				nhanVien->nhapThongTin();
				list.push_back(nhanVien);
			}
		}
		void Sum_Salary(){
			cout << "\n\t\t\tDANH SACH LUONG CUA NHAN VIEN\n";
			int count = 0;
			double sumSalary = 0.0;
			for(NhanVien *nv : list){
				double salary = nv->tinhLuong();
				cout << "\t\t[" << ++count << "].Ma so nhan vien " 
					 << nv->getMaSo() << " : Luong = " << salary << endl;
				sumSalary += salary;
			}
			cout << "==>Tong luong cho tat ca nhan vien: " << sumSalary << endl;
		}
//		static bool cmp(NhanVien * a , NhanVien * b){
//			CongNhanSanPham* cnspA = dynamic_cast<CongNhanSanPham*>(a);
//    		CongNhanSanPham* cnspB = dynamic_cast<CongNhanSanPham*>(b);
//			if(cnspA != nullptr && cnspB != nullptr){
//				return cnspA->getSoSanPhamLamDuoc() > cnspB->getSoSanPhamLamDuoc();
//			}
//			return false;
//		}
		void sort_list_numberSP(){
			cout << "\n\t\t\tDANH SACH NHAN VIEN SAU KHI SAP XEP\n";
//			sort(list.begin(),list.end(),cmp);
			for(int i = 0; i < n - 1;i++){
				for(int j = i + 1; j < n;j++){
					if(list[i]->id_Tyle_Employee() == 4 && list[j]->id_Tyle_Employee() == 4){
						CongNhanSanPham* cnspA = dynamic_cast<CongNhanSanPham*>(list[i]);
			    		CongNhanSanPham* cnspB = dynamic_cast<CongNhanSanPham*>(list[j]);
			    		if(cnspA->getSoSanPhamLamDuoc() < cnspB->getSoSanPhamLamDuoc()){
			    			swap(list[i],list[j]);
						}
					}
				}
			}
			for(NhanVien *nv : list){
				if(nv->id_Tyle_Employee() == 4){
					CongNhanSanPham* cnsp = dynamic_cast<CongNhanSanPham*>(nv);
					cout << "\t\t[+]Ma so nhan vien " << cnsp->getMaSo() << " : Luong = " << cnsp->tinhLuong()
						 <<  " : So san pham: " << cnsp->getSoSanPhamLamDuoc() << endl;
			
				}else
				cout << "\t\t[+]Ma so nhan vien " 
					 << nv->getMaSo() << " : Luong = " << nv->tinhLuong() << endl;
			}
		}
};
int main(){
	List_NhanVien *list = new List_NhanVien();
	list->nhapThongTin();
	list->Sum_Salary(); 
	list->sort_list_numberSP();
	return 0;
}


