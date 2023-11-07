#include <iostream>
#include <string>
using namespace std;

class VanDongVien
{
private:
    string hoTen, monThiDau;
    int tuoi;
    float chieuCao, CanNang;

public:
    // Ham tao
    VanDongVien(string _hoTen, int _tuoi, string _monThiDau, float _chieuCao, float _cangNang);
    VanDongVien();

    // Nap chong toan tu Nhap - Xuat
    friend istream &operator>>(istream &is, VanDongVien &p)
    {
        is.ignore();
        cout << "Ho ten: ";
        getline(is, p.hoTen);
        cout << "Tuoi: ";
        is >> p.tuoi;
        is.ignore();
        cout << "Mon thi dau: ";
        getline(is, p.monThiDau);
        cout << "Chieu cao: ";
        is >> p.chieuCao;
        cout << "Can nang: ";
        is >> p.CanNang;
        return is;
    }

    friend ostream &operator<<(ostream &os, VanDongVien p)
    {
        os << "Ho ten: " << p.hoTen << endl;
        os << "Tuoi: " << p.tuoi << endl;
        os << "Mon thi dau: " << p.monThiDau << endl;
        os << "Chieu cao: " << p.chieuCao << "m" << endl;
        os << "Can nang: " << p.CanNang << "kg" << endl;
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
            if (this->CanNang > p.CanNang)
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

    //  Ham Huy
    ~VanDongVien();
};

VanDongVien::VanDongVien(string _hoTen, int _tuoi, string _monThiDau, float _chieuCao, float _cangNang) // co tham so
{
    hoTen = _hoTen;
    tuoi = _tuoi;
    monThiDau = _monThiDau;
    CanNang = _cangNang;
    chieuCao = _chieuCao;
}
VanDongVien::VanDongVien() // khong tham so
{

    hoTen = " ";
    tuoi = 0;
    monThiDau = " ";
    CanNang = 0;
    chieuCao = 0;
}

VanDongVien::~VanDongVien()
{
    // hoTen = " ";
    // tuoi = 0;
    // monThiDau = " ";
    // CanNang = 0;
    // chieuCao = 0;
}

// sap xep dua theo chieu cao (can nang), Bubble Sort
void sortAtoZ(VanDongVien a[], int n)
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

    // VanDongVien p("Ngo Nguyen Ngoc Chau", 19, "The Duc Dung Cu", 1.65, 52);
    // cout << p;

    int n;
    cin >> n;
    VanDongVien *arr = new VanDongVien[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin van dong vien thu " << i + 1 << endl;
        cin >> arr[i];
    }
    cout << "------------OUTPUT------------" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Thong tin van dong vien thu " << i + 1 << endl;
        cout << arr[i];
        cout << "------------------------------" << endl;
    }
    cout << "------------Sap Xep-----------" << endl;
    sortAtoZ(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << "Thong tin van dong vien thu " << i + 1 << endl;
        cout << arr[i];
        cout << "------------------------------" << endl;
    }

    system("pause");
    return 0;
}