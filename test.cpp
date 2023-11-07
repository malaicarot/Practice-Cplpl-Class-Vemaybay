// 32767
#include <iostream>
#include <string>

using namespace std;

// Lop ve
class veMayBay
{
private:
    int giaVe;
    string ngayBay, tenChuyenBay;

public:
    // Getter
    int getGiaVe();
    // Ham tao
    veMayBay(int _giaVe = 0, string _ngayBay = " ", string _tenChuyenBay = " ");
    veMayBay(const veMayBay &ve);

    // Ham nhap - xuat
    void enterTicket()
    {
        cout << "Nhap thong tin ve (gia, ten, ngay)" << endl;
        cin >> this->giaVe;
        cin.ignore(32767, '\n');
        getline(cin, this->tenChuyenBay);
        getline(cin, this->ngayBay);
    }
    void exportTicket()
    {
        cout << "Gia ve: " << this->giaVe;
    }

    // Ham Huy
    ~veMayBay();
};

// Lop nguoi
class Nguoi
{
private:
    string ten, gioiTinh, tuoi;

public:
    // Ham tao
    Nguoi(string _ten = " ", string _gioiTinh = " ", string _tuoi = " ");
    Nguoi(const Nguoi &nguoi);

    // Ham nhap - xuat

    void enterInfor()
    {
        cout << "Nhap thong tin ca nhan (ten, gioi tinh, tuoi)" << endl;
        getline(cin, this->ten);
        getline(cin, this->gioiTinh);
        getline(cin, this->tuoi);
    }
    void exportInfor()
    {
        cout << "Ho va ten: " << this->ten << endl;
    }

    // Ham huy
    ~Nguoi();
};

// Lop khach
class hanhKhach : public Nguoi
{
private:
    veMayBay ve[1000];
    int soLuongVe;
    int tongTien;

public:
    // Ham tao
    hanhKhach()
    {
        this->soLuongVe = 0;
        ve[this->soLuongVe];
        this->tongTien = 0;
    }
    // Ham nhap - xuat
    void enterInfor()
    {
        cout << "Nhap thong tin hanh khach" << endl;
        Nguoi::enterInfor();
        cout << "Nhap so luong ve: " << endl;
        cin >> this->soLuongVe;
        ve[this->soLuongVe];
        for (int i = 0; i < this->soLuongVe; i++)
        {
            ve[i].enterTicket();
            tongTien += ve[i].getGiaVe();
        }
    }
    void exportInfor()
    {
        cout << "Thong tin hanh khach" << endl;
        Nguoi::exportInfor();
        cout << "Tong tien: " << this->tongTien << endl;
    }

    bool operator<(const hanhKhach &khach)
    {
        if (this->tongTien < khach.tongTien)
            return true;
        else
            return false;
    }

    // Ham huy
    ~hanhKhach()
    {
    }
};

void sort(hanhKhach khach[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (khach[j] < khach[j + 1])
            {
                swap(khach[j], khach[j + 1]);
            }
        }
    }
}

int main()
{
    int n;
    cout << "Nhap so luong hanh khach: ";
    cin >> n;
    cin.ignore(32767, '\n');
    hanhKhach *arr = new hanhKhach[n];
    for (int i = 0; i < n; i++)
    {
        arr[i].enterInfor();
    }
    sort(arr, n);
    cout << "---------OUTPUT---------" << endl;
    for (int i = 0; i < n; i++)
    {
        arr[i].exportInfor();
    }

    system("pause");
    return 0;
}

/*Dinh Nghia*/

/*******Ve May Bay*******/

// Ham tao
veMayBay::veMayBay(int _giaVe, string _ngayBay, string _tenChuyenBay)
{
    giaVe = _giaVe;
    ngayBay = _ngayBay;
    tenChuyenBay = _tenChuyenBay;
}
veMayBay::veMayBay(const veMayBay &ve)
{
    giaVe = ve.giaVe;
    ngayBay = ve.ngayBay;
    tenChuyenBay = ve.tenChuyenBay;
}
int veMayBay::getGiaVe()
{
    return this->giaVe;
}

// Ham Huy
veMayBay::~veMayBay()
{
}

/*******Nguoi*******/
Nguoi::Nguoi(string _ten, string _gioiTinh, string _tuoi)
{
    ten = _ten;
    gioiTinh = _gioiTinh;
    tuoi = _tuoi;
}
Nguoi::Nguoi(const Nguoi &nguoi)
{

    ten = nguoi.ten;
    gioiTinh = nguoi.gioiTinh;
    tuoi = nguoi.tuoi;
}
// Ham huy
Nguoi::~Nguoi()
{
}
