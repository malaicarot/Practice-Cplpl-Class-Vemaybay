#include <iostream>
#include <string>

using namespace std;

class VanDongVien
{
private:
    string hoTen, monThiDau;
    int tuoi;
    float canNang, chieuCao;

public:
    // Ham khoi tao
    VanDongVien(string _hoTen, int _tuoi, string _monThiDau, float _chieuCao, float _canNang); // Co tham so
    VanDongVien();                                                                             // Khong co tham so

    // Nap chong toan tu Nhap
    friend istream &operator>>(istream &is, VanDongVien &p)
    {
        cout << "Nhap ho ten: ";
        getline(is, p.hoTen);
        cout << "Nhap tuoi: ";
        is >> p.tuoi;
        is.ignore();
        cout << "Nhap mon thi dau: ";
        getline(is, p.monThiDau);
        cout << "Nhap chieu cao: ";
        is >> p.chieuCao;
        cout << "Nhap can nang: ";
        is >> p.canNang;
        is.ignore();
        return is;
    }
    // Nap chong toan tu xuat
    friend ostream &operator<<(ostream &os, VanDongVien p)
    {
        os << "Ho ten: " << p.hoTen << endl;
        os << "Tuoi: " << p.tuoi << endl;
        os << "Mon thi dau: " << p.monThiDau << endl;
        os << "Chieu cao: " << p.chieuCao << "m" << endl;
        os << "Can nang: " << p.canNang << "kg" << endl;
        return os;
    }

    // Ham xu ly
    bool operator>(VanDongVien p)
    {
        if (this->chieuCao > p.chieuCao)
        {
            return true;
        }
        else if (this->chieuCao == p.chieuCao)
        {
            if (this->canNang > p.canNang)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }

    // Ham Huy
    ~VanDongVien();
};

// Bubble Sort
void sxDanhSachAToZ(VanDongVien a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

int main()
{
    // Xuat thong tin, dung ham khoi tao 5 tham so
    VanDongVien p("Pham Anh Khoa", 19, "Bong Da", 1.68, 56.8);
    cout << p;

    // Nhap mang van dong vien
    int n;
    cin >> n;
    cin.ignore();
    VanDongVien *arr = new VanDongVien[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin van dong vien thu " << i + 1 << endl;
        cin >> arr[i];
    }
    cout << "----------DANH SACH DAU VAO----------" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "----------Thong tin thi dau " << i + 1 << "----------" << endl;
        cout << arr[i];
    }
    cout << "----------DANH SACH SAU KHI SAP XEP----------" << endl;
    sxDanhSachAToZ(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << "----------Thong tin thi dau " << i + 1 << "----------" << endl;
        cout << arr[i];
    }
    system("pause");
    return 0;
}

/*Dinh Nghia class*/
// Ham khoi tao
VanDongVien::VanDongVien(string _hoTen, int _tuoi, string _monThiDau, float _chieuCao, float _canNang)
{
    hoTen = _hoTen;
    tuoi = _tuoi;
    monThiDau = _monThiDau;
    chieuCao = _chieuCao;
    canNang = _canNang;
}
VanDongVien::VanDongVien()
{
    hoTen = "";
    tuoi = 0;
    monThiDau = "";
    chieuCao = 0;
    canNang = 0;
}
// Ham huy
VanDongVien::~VanDongVien()
{
}
