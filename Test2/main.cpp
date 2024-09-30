#include <iostream>
#include <vector>
using namespace std;

class Vemaybay {
private:
    string tenChuyen; //SG-HN  == Sai Gon ra Ha Noi
    int ngaybay; //241001 == nam 2024 thang 10 ngay 1
    int giave;
public:
    //Tao ve may bay
    Vemaybay(){
    tenChuyen="";
    ngaybay=0;
    giave=0;
    }
    Vemaybay(string chuyenBay, int date, int cost) : tenChuyen(chuyenBay),ngaybay(date),giave(cost){}

    //Ham huy ve
    ~Vemaybay(){
        cout<<endl<<"Huy ve thanh cong!"<<endl;
    }

    //Ham nhap
    friend istream& operator>>(istream &input, Vemaybay& ve ){
        cout<<"Ten chuyen bay: "<<endl;
        input>>ve.tenChuyen;
        cout<<"Ngay bay: "<<endl;
        input>>ve.ngaybay;
        cout<<"Gia ve may bay: "<<endl;
        input>>ve.giave;
        return input;
    }

    //Ham xuat
    friend ostream& operator<<(ostream &output, const Vemaybay& ve ){
    output<<endl<<"-------------------------------------------------"<<endl
    <<"Ten chuyen bay: "<<ve.tenChuyen<<'\n'
    <<"Ngay bay: "<<ve.ngaybay<<'\n'
    <<"Gia ve may bay: "<<ve.giave<<" vnd"<<endl;
    return output;
    }

    //Ham tra ve gia ve
    int getgiave(){
        return giave;
    }

    friend class HanhKhach;
};

class Nguoi{
private:
    string hoten;
    string gioitinh;
    int tuoi;
public:
    //Ham tao
    Nguoi() : hoten(""),gioitinh(""), tuoi(0){}
    Nguoi(string name, string gender, int age) : hoten(name),gioitinh(gender),tuoi(age) {}

    //Ham huy
    ~Nguoi(){
    cout<<endl<<"Huy thong tin Nguoi dung thanh cong!";}

    //Ham nhap
    friend istream& operator>>(istream &input, Nguoi& ng ){
        cout<<"Ho_va_ten: ";
        input>>ng.hoten;
        cout<<"Gioi tinh: ";
        input>>ng.gioitinh;
        cout<<"Tuoi: ";
        input>>ng.tuoi;
        return input;
    }

    //Ham xuat
    friend ostream& operator<<(ostream &output, const Nguoi& ng ){
    output<<endl<<"-------------------------------------------------"<<endl
    <<"Ho va ten: "<<ng.hoten<<'\n'
    <<"Gioi tinh: "<<ng.gioitinh<<'\n'
    <<"Tuoi: "<<ng.tuoi<<endl;
    return output;
    }

    friend class HanhKhach;
};

class HanhKhach {
private:
    Nguoi nguoi;
    Vemaybay* ves;
    int soluong;
public:
    //ham tao
    HanhKhach(){}
    HanhKhach(Nguoi ng, int quantity):nguoi(ng),soluong(quantity){
    ves = new Vemaybay[soluong];
    }

    //Ham huy
    ~HanhKhach(){
     cout<<endl<<"Huy thong tin Hanh Khach thanh cong!";
     delete[] ves;}

    //Ham nhap
    friend istream& operator>>(istream& in, HanhKhach & customer){
        cout << "Nhap thong tin khach hang:" << endl;
        in >> customer.nguoi;
        cout << "Nhap so luong ve may bay: ";
        in >> customer.soluong;
        customer.ves = new Vemaybay[customer.soluong];
        for (int i = 0; i < customer.soluong; i++) {
            cout << "Nhap thong tin ve may bay " << (i + 1) << ":" << endl;
            in >> customer.ves[i];
        }
        return in;
    }

    int sumVe()const {
     int total = 0;
        for (int i = 0; i < soluong; i++) {
            total += ves[i].getgiave(); //
        }
        return total;
    }

    //Ham xuat
    friend ostream& operator<<(ostream &output, const HanhKhach& customer ){
    output<<endl<<"-------------------------------------------------"<<endl
          << customer.nguoi
          << "So luong ve may bay: " << customer.soluong<<endl
          << "Tong so tien: "
          << "Danh sach ve may bay:" << endl;
        for (int i = 0; i < customer.soluong; i++) {
            output << customer.ves[i]; // Output each ticket
        };
        output<<"Tong gia ve: "<<customer.sumVe()<<" vnd"<<endl;
        return output;
    }

    static void bubbleSort(HanhKhach* customers, int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (customers[j].sumVe() < customers[j + 1].sumVe()) {
                    // Swap customers
                    HanhKhach temp= customers[j];
                    customers[j] = customers[j+1];
                    customers[j+1] = temp;
                }
            }
        }
    }
};



    int main()
{
     int n;
    cout << "Nhap so luong khach hang: ";
    cin >> n; // Number of customers
    HanhKhach* customers = new HanhKhach[n];

    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin cho khach hang " << (i + 1) << ":" << endl;
        cin >> customers[i];
    }


    HanhKhach::bubbleSort(customers,n);
    cout << endl << "Danh sach khach hang:" << endl;
    for (int i = 0; i < n; i++) {
        cout << customers[i];
    }


    delete[] customers; // Free allocated memory for customers
    return 0;

}
