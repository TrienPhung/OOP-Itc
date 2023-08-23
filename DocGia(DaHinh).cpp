#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
class DocGia {
	protected:
		string ma,tenSach,tacGia,nguoiThue;
		int tuoi,ngayThue,ngayTra;
	public:
		 void import(){
			fflush(stdin);
			cout << "-Nhap ma sach: ";
			getline(cin,ma);
			cout << "-Nhap ten sach: ";
			getline(cin,tenSach);
			cout << "-Nhap tac gia: ";
			getline(cin,tacGia);
			cout << "-Nhap ten nguoi thue: ";
			getline(cin,nguoiThue);
			cout << "-Nhap tuoi: ";
			cin >> tuoi;
			cout << "-Nhap ngay thue: ";
			cin >> ngayThue;
			cout << "-Nhap ngay tra: ";
			cin >> ngayTra;
			fflush(stdin);
		}
		 void display(){
			cout << "\t\t[+]Ma sach: " << ma << endl;
			cout << "\t\t[+]Ten sach: " << tenSach << endl;
			cout << "\t\t[+]Tac gia: " << tacGia << endl;
			cout << "\t\t[+]Ten nguoi thue: " << nguoiThue << endl;
			cout << "\t\t[+]Tuoi: " << tuoi << endl;
			cout << "\t\t[+]Ngay thue: " << ngayThue << endl;
			cout << "\t\t[+]Ngay tra: " << ngayTra << endl;
		}
		string getMa(){
			return ma;
		}
		string getTacGia(){
			return tacGia;
		}
		virtual int thanhTien() = 0;
		virtual bool check() = 0; 
};
class DocGiaTreEm : public DocGia{
	private: 
		string tenGiamHo;
	public:
		void import(){
			DocGia::import();
			cout << "-Nhap ten nguoi giam ho: ";
			getline(cin,tenGiamHo);
		}
		void display(){
			DocGia::display();
			cout << "\t\t[+]Ten nguoi giam ho: " << tenGiamHo << endl;
			cout <<	"\t\t[+]Thanh tien: " << thanhTien() << endl;
		}
		int thanhTien(){
			return (ngayTra - ngayThue) * 2000;
		}
		bool check(){
		 	return true;
		}
};
class DocGiaNguoiLon: public DocGia{
	private: 
		string soCmt;
	public:
		void import(){
			DocGia::import();
			cout << "-Nhap so chung minh thu: ";
			getline(cin,soCmt);
		}
		void display(){
			DocGia::display();
			cout << "\t\t[+]So chung minh thu: " << soCmt << endl;
			cout <<	"\t\t[+]Thanh tien: " << thanhTien() << endl;
		}
		int thanhTien(){
			return (ngayTra - ngayThue) * 3000;
		}
		bool check(){
		 	return false;
		}
};
class ThuVien{
	private:
		DocGia *dg[100];
		int n;
	public:
		void  import_list(){
			cout << "\t\t\tNHAP DANH SACH DOC GIA\n";
			cout << "[*]Nhap so luong doc gia: ";
			cin >> n;
			int choice;
			for(int i = 0; i < n;i++){
				cout << "\t[1].Doc Gia Tre Em."<< endl;
				cout <<	"\t[2].Doc Gia Nguoi Lon."<< endl;
				cout << "\t-->Nhap lua chon: ";
				cin >> choice;
				while(choice < 1 || choice > 2){
					cout << "[!]Lua chon khong ton tai=>Vui long nhap lai." << endl;
					cout << "\t-->Nhap lua chon: ";
		 	 		cin >> choice;
				}
				if(choice == 1){
					dg[i] = new DocGiaTreEm();
				}else{
					dg[i] = new DocGiaNguoiLon();
				}
				cout << "-Nhap thong tin doc gia thu " << i + 1 << endl;
				dg[i]->import();			
			}
		}
		void display_list(){
			cout << "\t\t\tXUAT DANH SACH DOC GIA\n";
			for(int i = 0; i < n;i++){
				cout << "[-]Thong tin doc gia thu " << i + 1 << endl;
				dg[i]->display();
			}
		}
		void tongThanhTien(){
			cout << "\n\t\t\tDANH SACH THANH TIEN DOC GIA\n";
			int count = 0;
			int sumTreEm = 0;
			int sumNguoiLon = 0;
			for(int i = 0; i < n ;i++){
				if(dg[i]->check()){
					int tienTreEm = dg[i]->thanhTien();
					cout << "\t\t[" << ++count << "].Ma so doc gia " 
					 << dg[i]->getMa() << " : Thanh Tien = " << tienTreEm << endl;
					 sumTreEm+= tienTreEm;
				}else{
					int tienNguoiLon = dg[i]->thanhTien();
					cout << "\t\t[" << ++count << "].Ma so doc gia " 
					 << dg[i]->getMa() << " : Thanh Tien = " << tienNguoiLon << endl;
					 sumNguoiLon+= tienNguoiLon;
				}
			}
			cout << "==>Tong thanh tien cho tat ca doc gia tre em: " << sumTreEm << endl;
			cout << "==>Tong thanh tien cho tat ca doc gia nguoi lon: " << sumNguoiLon << endl;
		}
		static bool cmp(DocGia *a , DocGia *b){
			return a->getTacGia() < b->getTacGia();
		}
		void sort_list(){
			cout << "\n\t\t\tDANH SACH DOC GIA SAU KHI SAP XEP\n";
			sort(dg,dg + n,cmp);
			for(int i = 0; i < n;i++){
				cout << "[-]Thong tin doc gia thu " << i + 1 << endl;
				dg[i]->display();
			}
		}
};
int main(){
	ThuVien *list = new ThuVien();
	list->import_list();
	list->display_list();
	list->tongThanhTien();
	list->sort_list();
	return 0;
}


