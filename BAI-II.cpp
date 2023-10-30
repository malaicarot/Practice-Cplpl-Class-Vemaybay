#include <iostream>
#include <string>
using namespace std;

class veMayBay
{
private:
    int giaVe;
    string tenChuyen, ngayBay;

public:
    // Getter
    int getGiaVe();
    // Ham tao
    veMayBay(int _giaVe = 1000000, string _tenChuyen = "Hanoi", string _ngayBay = "30/10/2023"); // Khai Bao Tham So
    veMayBay(const veMayBay &ve);                                                                // Khai bao sao chep
    ~veMayBay();

    // Ham Nhap - Xuat
    void enterTicket()
    {
        cout << "Nhap thong tin ve (gia ve, ten, ngay)" << endl;
        cin >> this->giaVe;
        cin.ignore(32767, '\n'); // Xoa bo nho dem hoac xoa khi gap ki tu xuong dong
        getline(cin, this->tenChuyen);
        getline(cin, this->ngayBay);
    }
    void exportTicket()
    {
        cout << "Gia ve: " << this->giaVe << endl;
        cout << "Ten chuyen: " << this->tenChuyen << endl;
        cout << "Ngay bay: " << this->ngayBay << endl;
    }
};

class Nguoi
{
public:
    string hoTen, gioiTinh, tuoi;

public:
    // Ham tao
    Nguoi(string _hoTen = "Nguyen Van A", string _gioiTinh = "Nam", string _tuoi = "20"); // Khai Bao Tham So
    Nguoi(const Nguoi &nguoi);                                                            // Khai bao sao chep
    ~Nguoi();

    // Ham Nhap - Xuat
    void enterInfor()
    {
        cout << "Nhap thong tin (ten, gioi tinh, tuoi)" << endl;
        getline(cin, this->hoTen);
        getline(cin, this->gioiTinh);
        getline(cin, this->tuoi);
    }

    void exportInfor()
    {

        cout << "Ho ten: " << this->hoTen << endl;
        cout << "Gioi tinh: " << this->gioiTinh << endl;
        cout << "Tuoi: " << this->tuoi << endl;
    }
};

class hanhKhach : public Nguoi
{
public:
    int soLuong = 0;
    veMayBay ve[1000];
    int tongTien = 0;

public:
    // Ham tao
    hanhKhach(int _soLuong = 1);
    hanhKhach(const hanhKhach &khach);

    // Ham nhap - xuat
    void enterInfor()
    {
        Nguoi::enterInfor();
        cout << "Nhap so luong ve: ";
        cin >> this->soLuong;
        ve[this->soLuong];
        for (int i = 0; i < this->soLuong; i++)
        {
            ve[i].enterTicket();
            tongTien += ve[i].getGiaVe();
        }
    }
    void exportInfor()
    {
        cout << "----------Thong Tin Hanh Khach----------" << endl;
        Nguoi::exportInfor();
        cout << "----------Thong Tin Chuyen Bay----------" << endl;
        for (int i = 0; i < this->soLuong; i++)
        {
            ve[i].exportTicket();
        }
        cout << "==> Tong tien: " << this->tongTien << endl;
    }
    // Ham Huy
    ~hanhKhach();
};

int main()
{
    int n;
    cout << "Nhap so luong khach hang: ";
    cin >> n;
     cin.ignore(32767, '\n');
    hanhKhach khach[n];
    for (int i = 0; i < n; i++)
    {
        khach[i].enterInfor();
    }
    cout << "Output" << endl;
    for (int i = 0; i < n; i++)
    {
        khach[i].exportInfor();
    }


    system("pause");
    return 0;
}

/*Dinh nghia Class Ve May Bay*/

// Ham Khoi Tao
veMayBay::veMayBay(int _giaVe, string _tenChuyen, string _ngayBay)
{
    giaVe = _giaVe;
    tenChuyen = _tenChuyen;
    ngayBay = _ngayBay;
}
veMayBay::veMayBay(const veMayBay &nguoi)
{
    giaVe = nguoi.giaVe;
    tenChuyen = nguoi.tenChuyen;
    ngayBay = nguoi.ngayBay;
}
// Ham tra ve gia ve
int veMayBay::getGiaVe()
{
    return this->giaVe;
}
veMayBay::~veMayBay()
{
}

/*Dinh nghia Class Nguoi*/
// Ham Khai bao
Nguoi::Nguoi(string _hoTen, string _gioiTinh, string _tuoi)
{
    hoTen = _hoTen;
    gioiTinh = _gioiTinh;
    tuoi = _tuoi;
}
Nguoi::Nguoi(const Nguoi &nguoi)
{
    hoTen = nguoi.hoTen;
    gioiTinh = nguoi.gioiTinh;
    tuoi = nguoi.tuoi;
}
// Ham Huy
Nguoi::~Nguoi()
{
}

/*Dinh nghia Class Hanh Khach*/
// Ham tao
hanhKhach::hanhKhach(int _soLuong)
{
    soLuong = _soLuong;
}
hanhKhach::hanhKhach(const hanhKhach &khach)
{
    soLuong = khach.soLuong;
}

// Ham Tinh Tong Tien

// Ham Huy
hanhKhach::~hanhKhach()
{
}