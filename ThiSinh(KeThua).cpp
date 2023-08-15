#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
class Nguoi{
	private:
		string name;
		int dateOfBirth;
	public:
		Nguoi(){
			name = "";
			dateOfBirth = 1;
		}
		void import(){
			fflush(stdin);
			cout << "[-]Nhap ho va ten: ";
			getline(cin,name);
			cout << "[-]Nhap nam sinh: ";
			cin >> dateOfBirth;
		}
		void display(){
			cout << "\t\t[+]Ho va ten: " << name << endl;
			cout << "\t\t[+]Nam sinh: " << dateOfBirth << endl;
		}
};
class ThiSinh : public Nguoi{
	private:
		string id;
		float toan,ly,hoa;
	public:
		ThiSinh():Nguoi(){
			id = "";
			toan = ly = hoa = 0.0;
		}
		void import(){
			Nguoi::import();
			cout <<"[-]Nhap so bao danh: ";
			fflush(stdin);
			getline(cin,id);
			cout <<"[-]Nhap diem toan: ";
			cin >> toan;
			cout <<"[-]Nhap diem ly: "; 
			cin >> ly;
			cout <<"[-]Nhap diem hoa: ";
			cin >> hoa;
		}
		void display(){
			Nguoi::display();
			cout << "\t\t[+]So bao danh: " << id << endl;
			cout << "\t\t[+]Diem toan: " << toan << endl;
			cout << "\t\t[+]Diem ly: " << ly << endl;
			cout << "\t\t[+]Diem hoa: " << hoa << endl;
			cout << "\t\t[+]Diem tong: " << getTongDiem() << endl;
		}
		float getTongDiem(){
			return toan + hoa + ly;
		}
		void import_list(ThiSinh ts[], int n){
			cout << "\t\t\t\tNHAP DANH SACH\n";
			for(int i = 0 ; i < n;i++){
			 	cout << "[-]Nhap thong tin thi sinh thu " << i + 1 << endl;
			 	ts[i].import();
			}
		}
		void display_list(ThiSinh ts[], int n){
			cout << "\t\t\t\tXUAT DANH SACH\n";
			for(int i = 0 ; i < n;i++){
			 	cout << "[-]Thong tin thi sinh thu " << i + 1 << endl;
			 	ts[i].display();
			}
		}
		static bool cmp(ThiSinh a, ThiSinh b){
				return a.getTongDiem() < b.getTongDiem();
		}
       void sort_Diem(ThiSinh ts[],int n){
			sort(ts,ts + n,cmp);
			cout << "\t\t\t\tXUAT DANH SACH SAU KHI SAP XEP\n";
			for(int i = 0 ; i < n;i++){
			 	cout << "[-]Thong tin thi sinh thu " << i + 1 << endl;
			 	ts[i].display();
			}
		}
		void search(ThiSinh ts[],int n){
			cout << "[-]Nhap so bao danh muon tim: ";
			fflush(stdin);
			string s; getline(cin,s);
			bool check = false;
			for(int i = 0; i < n;i++){
				if(ts[i].id == s){
					cout << "[+]Tim thay!" << endl;
					cout << "[-]Thong tin thi sinh thu " << i + 1 << endl;
			 		ts[i].display();
			 		check = true;
			 		break;
			 		
				}
			}
			if(!check){
				cout << "[+]Khong tim thay!" << endl;
			}
		}
		void thongKe(ThiSinh ts[] , int n){
			int count = 0;
			for(int i = 0; i < n;i++){
				if(ts[i].toan >= 5 && ts[i].ly >= 5 && ts[i].hoa >= 5){
					count++;
				}
			}
			cout << "[+]So phan tram thi sinh dat yeu cau: " << float(count) / n * 100 << "%" << endl;
			cout << "[+]So phan tram thi sinh khong dat yeu cau: " << 100 - (float(count) / n * 100) << "%" << endl;
		}
};

int main()
{
	cout << "[*]Nhap so luong thi sinh: ";
	int n; cin >> n;
	ThiSinh ts[n];
	ts[n].import_list(ts,n);
	ts[n].display_list(ts,n);
	ts[n].sort_Diem(ts,n);
	ts[n].search(ts,n);
	ts[n].thongKe(ts,n); 
	return 0;
}


