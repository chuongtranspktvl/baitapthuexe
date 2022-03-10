#include <iostream>
#include <string>
using namespace std;
class XE
{
protected:
    string ten;
    float sogiothue;

public:
    XE() {}
    ~XE()
    {
        ten = "";
        sogiothue = 0;
    }
    void xuat()
    {
        cout << "\nTen nguoi thue : ";
        cout << ten;
        cout << "\nSo gio thue : ";
        cout << sogiothue;
    }
    void nhap()
    {
        cout << "\nNhap ten : ";
        fflush(stdin);
        getline(cin, ten);
        cout << "Nhap so gio thue : ";
        cin >> sogiothue;
    }
    float tinhtienxe();
};
class XEDAP : public XE
{
private:
public:
    XEDAP() {}
    float tinhtienxe()
    {
        return (10000 + (sogiothue - 1) * 8000);
    }
    void nhap()
    {
        cout << "NHAP THONG TIN THUE XE DAP";
        XE::nhap();
    }
};
class XEMAY : public XE
{
private:
    int loaixe;
    string bienso;

public:
    XEMAY() {}
    ~XEMAY() {}
    int getloaixe()
    {
        return loaixe;
    }
    float tinhtienxe()
    {
        if (loaixe == 250)
        {
            return ((sogiothue - 1) * 100000 + 250000);
        }
        else
            return ((sogiothue - 1) * 100000 + 150000);
    }
    void nhap()
    {
        cout << "NHAP THONG TIN THUE XE MAY";
        XE::nhap();
        cout << "Nhap loai xe 100cc hoac 250cc : ";
        cin >> loaixe;
        fflush(stdin);
        cout << "Nhap bien so xe : ";
        getline(cin, bienso);
    }
    void xuat()
    {
        XE::xuat();
        cout << "\nLoai xe 100cc va 250cc: ";
        cout << loaixe;
        cout << "\nBien so xe : ";
        cout << bienso;
    }
};
float tinhtien_all(XEDAP xedap[], int n, XEMAY xemay[], int m)
{
    float tong = 0;
    for (int i = 0; i < n; i++)
    {
        tong += xedap[i].tinhtienxe();
    }
    for (int j = 0; j < n; j++)
    {
        tong += xemay[j].tinhtienxe();
    }
    return tong;
}
float tinhtien250cc(XEMAY xemay[], int m)
{
    float tong = 0;
    for (int i = 0; i < m; i++)
    {
        if (xemay[i].getloaixe() == 250)
        {
            tong += xemay[i].tinhtienxe();
        }
    }
    return tong;
}
void xuat_all(XEDAP xedap[], int n, XEMAY xemay[], int m)
{
    cout << "\nTHONG TIN NGUOI THUE XE DAP";
    cout << "\n-------------------------";
    for (int i = 0; i < n; i++)
    {
        xedap[i].xuat();
        cout << "\nSo tien thue : ";
        cout << (size_t)xedap[i].tinhtienxe();
    }
    cout << "\n-------------------------";
    cout << "\nTHONG TIN NGUOI THUE XE MAY";
    cout << "\n-------------------------";
    for (int j = 0; j < m; j++)
    {
        xemay[j].xuat();
        cout << "\nSo tien thue : ";
        cout << (size_t)xemay[j].tinhtienxe();
    }
    cout << "\n-------------------------";
}
void xuatxedap(XEDAP xedap[], int n)
{
    cout << "\nTHONG TIN NGUOI THUE XE DAP";
    cout << "\n-------------------------";
    for (int i = 0; i < n; i++)
    {
        xedap[i].xuat();
    }
    cout << "\n-------------------------";
}
void Menu(XEDAP xedap[], int &n, XEMAY xemay[], int &m)
{
    int luachon;
    while (true)
    {
        system("cls");
        cout << "=================MENU=================";
        cout << "\n 1. Chon thue xe dap hoac xe may.";
        cout << "\n 2. Xuat tat ca thong tin thue xe(va tien thue xe).";
        cout << "\n 3. Tinh tong tien thue xe dap va xe may.";
        cout << "\n 4. Xuat tat ca thong tin lien quan den viec thue xe dap.";
        cout << "\n 5. Tinh tong so tien thue xe 250cc.";
        cout << "\n 0. Ket thuc.";
        cout << "\n ================END=================";
        cout << "\n Nhap chon lua : ";
        fflush(stdin);
        cin >> luachon;
        if (luachon == 0)
        {
            break;
        }
        else if (luachon == 1)
        {
            int chon;
            system("cls");
            while (true)
            {
                system("cls");
                cout << "====================";
                cout << "\n 1.Thue xe dap.";
                cout << "\n 2.Thue xe may.";
                cout << "\n 0.Quay lai.";
                cout << "\n====================";
                cout << "\n Nhap chon lua : ";
                fflush(stdin);
                cin >> chon;
                if (chon == 0)
                {
                    break;
                }
                else if (chon == 1)
                {
                    XEDAP x;
                    x.nhap();
                    xedap[n] = x;
                    n++;
                }
                else if (chon == 2)
                {
                    XEMAY y;
                    y.nhap();
                    xemay[m] = y;
                    m++;
                }
            }
        }
        else if (luachon == 2)
        {
            xuat_all(xedap, n, xemay, m);
            system("pause");
        }
        else if (luachon == 3)
        {
            cout << "\nTONG TIEN THUE XE DAP VA XE MAY : ";
            cout << (size_t)tinhtien_all(xedap, n, xemay, m);
            system("pause");
        }
        else if (luachon == 4)
        {
            xuatxedap(xedap, n);
            system("pause");
        }
        else if (luachon == 5)
        {
            cout << "\nTONG TIEN THUE XE MAY 250cc : ";
            cout << (size_t)tinhtien250cc(xemay, m);
            system("pause");
        }
    }
}
int main()
{
    int m = 0, n = 0;
    XEDAP dsxedap[100];
    XEMAY dsxemay[100];
    Menu(dsxedap, n, dsxemay, m);
}