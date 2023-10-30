#include <iostream>
#include <string>
#include <algorithm>
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
        // cout << "Ten chuyen: " << this->tenChuyen << endl;
        // cout << "Ngay bay: " << this->ngayBay << endl;
    }
};

class Nguoi
{
private:
    string hoTen, gioiTinh, tuoi;

public:
    // Ham tao
    Nguoi(string _hoTen = " ", string _gioiTinh = " ", string _tuoi = " "); // Khai Bao Tham So
                                                                            // this->hoTen = this->gioiTinh = this->tuoi = "";
    Nguoi(const Nguoi &nguoi); // Khai bao sao chep
    ~Nguoi();

    // this->hoTen = this->gioiTinh = this->tuoi = "";

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
        // cout << "Gioi tinh: " << this->gioiTinh << endl;
        // cout << "Tuoi: " << this->tuoi << endl;
    }
};

class hanhKhach : public Nguoi
{
private:
    int soLuong = 0;
    veMayBay ve[1000];
    int tongTien = 0;

public:
    // Ham tao
    hanhKhach()
    {
        this->soLuong = 0;
        ve[this->soLuong];
        tongTien = 0;
    }
    hanhKhach(const hanhKhach &khach)
    {
        soLuong = khach.soLuong;
        tongTien = khach.tongTien;
    }
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
        // cout << "----------Thong Tin Chuyen Bay----------" << endl;
        // for (int i = 0; i < this->soLuong; i++)
        // {
        //     ve[i].exportTicket();
        // }
        cout << "==> Tong tien: " << this->tongTien << endl;
    }
    bool operator<(const hanhKhach &obj)
    {
        if (this->tongTien < obj.tongTien)
            return true;
        else
            return false;
    }

    // Ham Huy
    ~hanhKhach()
    {
    }
};

// Sort
void sort(hanhKhach a[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] < a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}
int main()
{
    int n;
    cout << "Nhap so luong khach hang: ";
    cin >> n;
    cin.ignore(32767, '\n');
    hanhKhach *arr = new hanhKhach[n];
    for (int i = 0; i < n; i++)
    {
        arr[i].enterInfor();
    }

    sort(arr, n);
    cout << "----------Output----------" << endl;
    for (int i = 0; i < n; i++)
    {
        arr[i].exportInfor();
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
