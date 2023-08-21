#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
class Sach{
	protected:
		string ma;
		float price;
		int count;
		string product;
	public:
		virtual void import(){
			fflush(stdin);
			cout << "-Nhap ma sach: ";
			getline(cin,ma);
			cout << "-Nhap don gia: ";
			cin >> price;
			cout << "-Nhap so luong: ";
			cin >> count;
			fflush(stdin);
			cout << "-Nhap nha xuat ban: ";
			getline(cin,product);		
		}
		virtual void display(){
			cout << "\t\t[+]Ma sach: " << this->ma << endl;
			cout << "\t\t[+]Don gia: " << this->price << endl;
			cout << "\t\t[+]So luong: " << this->count << endl;
			cout << "\t\t[+]Nha xuat ban: " << this->product << endl; 
		}
		virtual	float getThanhTien() = 0;
		virtual bool checkSach() = 0;
};
class SachGK : public Sach{
	private:
		bool tinhTrang;
	public:
		void import(){
			Sach::import();
			cout << "-Nhap tinh trang sach(1/0): ";
			cin >> tinhTrang;
		}
		void display(){
			Sach::display(); 
			cout << "\t\t[+]Tinh trang: ";
			cout << (tinhTrang ? "moi" : "cu")  << endl;
			cout << "\t\t[+]Thanh tien: " << getThanhTien() << endl;
		}
		float getThanhTien(){
			return this->tinhTrang  ? (count * price) : (count * price * 0.5);
		}
		bool checkSach(){
		 	return true;
		}
};
class SachTK : public Sach{
	private:
		float thue;
	public:
		void import(){
			Sach::import();
			cout << "-Nhap thue: ";
			cin >> thue;
		}
		void display(){
			Sach::display();
			cout << "\t\t[+]Thue: " << thue << endl;
			cout << "\t\t[+]Thanh tien: " << getThanhTien() << endl;
		}
		float getThanhTien(){
			return count * price + (thue*count*price);;
		}
		 bool checkSach() {
		 	return false;
		 }
};
class list_sach{
	private:
		Sach *list[100];
		int n;
	public:
		void import_list(){
			cout << "\t\t\tNHAP DANH SACH SACH\n";
			cout << "[*]Nhap so luong sach: ";
			cin >> n;
			int choice;
			for(int i = 0; i < n;i++){
				cout << "\t[1].Sach Giao Khoa."<< endl;
				cout <<	"\t[2].Sach Tham Khoa."<< endl;
				cout << "\t-->Nhap lua chon: ";
				cin >> choice;
				while(choice < 1 || choice > 2){
					cout << "[!]Lua chon khong ton tai=>Vui long nhap lai." << endl;
					cout << "\t-->Nhap lua chon: ";
			 	 	cin >> choice;
				}
				if(choice == 1){
					list[i] = new SachGK();
				}else{
					list[i] = new SachTK();
				}
				cout << "-Nhap thong tin cho sach thu " << i + 1 << endl;
				list[i]->import();
			}
		}
		void display_list(){
			cout << "\t\t\tXUAT DANH SACH SACH\n";
			for(int i = 0; i < n;i++){
				cout  << "[-]Xuat thong tin cho sach "
					  << (list[i]->checkSach() ? "giao khoa" : "tham khao") 
					  << " thu " << i + 1 << endl;
				list[i]->display();
			}
		}
		void sumTypeBook(){
			cout <<  "\t\t\tTONG THANH TIEN CHO TUNG LOAI\n";
			double sumBookGK = 0.0,sumBookTK = 0.0;
			for(int i = 0;i < n;i++){
				if(list[i]->checkSach())sumBookGK += list[i]->getThanhTien();
				else sumBookTK += list[i]->getThanhTien();
			}
			cout << "-->Giao Khoa: " << sumBookGK << endl;
			cout << "-->Tham Khao: " << sumBookTK << endl;		
		}
		void import_BookGK(){
			cout << "\t\t\tDANH SACH CAC SACH GIAO KHOA\n";
			bool check = 0;
			for(int i = 0; i < n;i++){
				if(list[i]->checkSach()){
					cout << "[-]Thong tin danh sach giao khoa thu " << i + 1 << endl;
					list[i]->display();
					check = 1;
				}
			}
			if(!check){
				cout << "-->Khong co sach giao khoa nao!" << endl;
			}
		}
		
};
int main(){
	list_sach *list = new list_sach();
	list->import_list();
	list->display_list();
	list->sumTypeBook();
	list->import_BookGK();
	return 0;
}


