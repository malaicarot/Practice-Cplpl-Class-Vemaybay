#include <iostream>
#include <string>

using namespace std;

// Class ve may bay
class VeMayBay
{
private:
    string tenChuyen, ngayBay;
    int giaVe;

public:
    // Getter
    int getGiaVe();
    // Ham tao
    VeMayBay(string _tenChuyen = "Hanoi", string _ngayBay = "6/11/2023", int _giaVe = 2000000);
    // Ham Nhap - Xuat
    void enterTicket()
    {
        cout << "Ten chuyen bay: ";
        getline(cin, this->tenChuyen);
        cout << "Ngay bay: ";
        getline(cin, this->ngayBay);
        cout << "Gia ve: ";
        cin >> this->giaVe;
        cin.ignore();
    }
    void exportTicket()
    {
        cout << "Ten chuyen bay: " << this->tenChuyen << endl;
        cout << "Ngay bay: " << this->ngayBay << endl;
        cout << "Gia ve: " << this->giaVe << endl;
    }

    ~VeMayBay();
};

// Class Nguoi
class Nguoi
{
private:
    string hoTen, gioiTinh;
    int tuoi;

public:
    // Ham tao
    Nguoi(string _hoTen = "Pham Anh Khoa", string _gioiTinh = "Nam", int _tuoi = 19);

    // Ham Nhap - Xuat
    void enterInfor()
    {
        cout << "Ho ten: ";
        getline(cin, this->hoTen);
        cout << "Gioi tinh: ";
        getline(cin, this->gioiTinh);
        cout << "tuoi: ";
        cin >> this->tuoi;
    }
    void exportinFor()
    {
        cout << "Ten chuyen bay: " << this->hoTen << endl;
        cout << "Ngay bay: " << this->gioiTinh << endl;
        cout << "Gia ve: " << this->tuoi << endl;
    }
    // Ham huy
    ~Nguoi();
};

Nguoi::Nguoi(string _hoTen, string _gioiTinh, int _tuoi)
{
    hoTen = _hoTen;
    gioiTinh = _gioiTinh;
    tuoi = _tuoi;
}

Nguoi::~Nguoi()
{
    hoTen = "";
    gioiTinh = "";
    tuoi = 0;
}

// Class Hanh Khach
class HanhKhach : public Nguoi
{
private:
    int soLuong, tongTien;
    VeMayBay ve[100];

public:
    // Ham Tao
    HanhKhach()
    {
        this->soLuong = soLuong;
        ve[this->soLuong];
        this->tongTien = 0;
    }
    // Ham Nhap - Xuat
    void enterPassenger()
    {
        cout << "Nhap thong tin hanh khach" << endl;
        Nguoi::enterInfor();
        cout << "So luong ve: ";
        cin >> soLuong;
        cin.ignore();
        ve[soLuong];
        for (int i = 0; i < soLuong; i++)
        {
            ve[i].enterTicket();
            tongTien += ve[i].getGiaVe();
        }
    }
    void exportPassenger()
    {
        cout << "********Thong tin khach hang********" << endl;
        Nguoi::exportinFor();
        for (int i = 0; i < soLuong; i++)
        {
            ve[i].exportTicket();
        }
        cout << "Tong tien: " << tongTien << endl;
    }

    // Ham xu ly sap xep
    bool operator<(HanhKhach p)
    {
        if (this->tongTien < p.tongTien)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Ham huy
    ~HanhKhach()
    {
        soLuong = 0;
        tongTien = 0;
    }
};

// Sap xep danh sach giam dan theo tong tien ve ( bubble sort)
void sortBaseSumOfCost(HanhKhach a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
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
    cin >> n;
    cin.ignore();
    HanhKhach *arr = new HanhKhach[n];
    for (int i = 0; i < n; i++)
    {
        arr[i].enterPassenger();
    }

    cout << "---------OUTPUT---------" << endl;
    for (int i = 0; i < n; i++)
    {
        arr[i].exportPassenger();
    }

    cout << "---------SAP XEP---------" << endl;
    sortBaseSumOfCost(arr, n);
    for (int i = 0; i < n; i++)
    {
        arr[i].exportPassenger();
    }

    system("pause");
    return 0;
}

/*Class ve may bay*/
VeMayBay::VeMayBay(string _tenChuyen, string _ngayBay, int _giaVe)
{
    tenChuyen = _tenChuyen;
    ngayBay = _ngayBay;
    giaVe = _giaVe;
}

// Getter
int VeMayBay::getGiaVe()
{
    return this->giaVe;
}

// Ham Huy
VeMayBay::~VeMayBay()
{
    tenChuyen = "";
    ngayBay = "";
    giaVe = 0;
}