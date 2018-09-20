#ifndef book_h
#define book_h
#include "node.h"
#include "list.h"
#include <fstream>
class Book
{
private:
	string tensach;
	string tacgia;
	int nam;
	int sotrang;
public:
	Book()
	{
		tensach = "";
		tacgia = "";
		nam = 0;
		sotrang = 0;
	};
	Book(string a, string b, int c, int d)
	{
		tensach = a;
		tacgia = b;
		nam	 = c;
		sotrang = d;
	};
	~Book(){};
	friend istream & operator >> (istream &cin, Book &a)
	{
		cout<<"Nhap ten sach: ";
		cin.ignore(); getline(cin,a.tensach);
		cout<<"Nhap ten tac gia: ";
		cin.ignore(); getline(cin,a.tacgia);
		cout<<"Nhap nam xuat ban: "; cin>>a.nam;
		cout<<"Nhap so trang: "; cin>>a.sotrang;
		return cin;
	};

	friend ostream & operator << (ostream &cout, Book &a)
	{
		cout<<a.tensach<<endl;
		cout<<a.tacgia<<endl;
		cout<<a.nam<<endl;
		cout<<a.sotrang<<endl;
		return cout;
	};
};

void ThemSach(List<Book> &l)
{
	Book b;
	cin>>b;
	l.PushBack(b);
};
void HienThi(List<Book> &l) 
{
	l.PrintAll();
};
void LuuXuongFile(List<Book> &l) 
{
	l.SaveFile();
};
void MoTuFile(List<Book> &l) 
{
	l.OpenFile();
};

void SuaSach(List<Book> &l) 
{
	int pos;
	cout<<"Nhap vi tri sach: ";
	cin>>pos;
	cout<<"Nhap ten sach:";
	Book b;
	cin>>b;
	l.Change(b,pos);
};
void XuatHTML(List<Book> &l)
{
	
};
int Menu()
{
	cout<<"CHUONG TRINH QUAN LY SINH VIEN\n";
	cout<<"1. Them sach.\n";
	cout<<"2. Hien thi danh sach. \n";
	cout<<"3. Luu xuong file. \n";
	cout<<"4. Mo tu file. \n";
	cout<<"5. Sua sach. \n";
	cout<<"6. Xuat HTML. \n";
	cout<<"0. Ket thuc.\n";
	int c;
	cin>>c;
	return c;
}
#endif