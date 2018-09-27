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

	string GetTenSach()
	{
		return tensach;
	};
	string GetTacGia()
	{
		return tacgia;
	};
	int GetNam()
	{
		return nam;
	};
	int GetSoTrang()
	{
		return sotrang;	
	};
	friend istream & operator >> (istream &cin, Book &a)
	{
		cout<<"Nhap ten sach: ";
		cin.ignore(); getline(cin,a.tensach);
		cout<<"Nhap ten tac gia: ";
		getline(cin,a.tacgia);
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
	int k = l.Len();
	cout<<"STT \t"<<"Ten Sach \t"<<"Tac Gia \t"<<"Nam XB \t"<<"So Trang "<<endl;
	for(int i = 1;i<= k;i++)
	{
		cout<<i<<"\t";
		Book a = l.GetAnItem(i);
		cout<<a.GetTenSach()<<"\t";
		cout<<a.GetTacGia()<<"\t";
		cout<<a.GetNam()<<"\t";
		cout<<a.GetSoTrang()<<"\t"<<endl;
	}	
};
void LuuXuongFile(List<Book> l) 
{
	ofstream fout;
	//fout.open("data.txt",ios::out|ios::app); // doc tiep vao cuoi file;
	fout.open("data.txt");
 
	int k = l.Len();
	fout<<k<<endl;

	for(int i = 1;i<= k;i++)
	{
		Book a = l.GetAnItem(i);
		fout<<a.GetTenSach()<<endl;
		fout<<a.GetTacGia()<<endl;
		fout<<a.GetNam()<<endl;
		fout<<a.GetSoTrang()<<endl;
	}

};
void MoTuFile(List<Book> &l) 
{
	ifstream fin("data.txt");
	int k;
	fin>>k;
	char * t[100];
	for(int i = 1;i<= k;i++)
	{
		string ts; string tg; int n; int st;
		fin.ignore();
		getline(fin,ts);

		getline(fin,tg);
		fin>>n;
		fin>>st;
		l.PushBack(Book(ts,tg,n,st));
	}
	fin.close();
};

void SuaSach(List<Book> &l) 
{
	int pos;
	cout<<"Nhap vi tri sach muon sach? ";
	cin>>pos;
	Book b;
	cin>>b;
	l.Change(b,pos);
};
void XuatHTML(List<Book> l)
{
	char fileName[100];
	cout<<"Nhap ten file chua du lieu: ";
	cin.ignore();
	cin.getline(fileName,100);
	ofstream fout(fileName);

	int k = l.Len();

	fout<<"<!DOCTYPE html>"<<endl;
	fout<<"	<html>"<<endl;
	fout<<"	<head>"<<endl;
	fout<<"		<title>Quan ly thu vien</title> "<<endl;
	fout<<"		<style type=\"text/css\"> \n";
    fout<<" 			th{ \n";
    fout<<"      			text-align: center; \n";
    fout<<"  			} \n";
    fout<<"  			td{ \n";
    fout<<"      				text-align: center;  \n";
    fout<<" 					}\n";
  	fout<<"			</style> \n";
	fout<<"	</head>"<<endl;
	fout<<"	<body>"<<endl;
	fout<<"		<h2>Quan ly thu vien</h2>\n";
	fout<<"		<table style=\"width:70%\" border = \"1\" >\n";
	fout<<"			<tr>\n";
	fout<<"					<th>STT</th>\n";
	fout<<"					<th>Ten sach</th>\n";
	fout<<"					<th>Tac gia</th>\n";
	fout<<"					<th>Nam XB</th>\n";
	fout<<"					<th>So trang</th>\n";
	fout<<"				</tr>\n";
	for(int i = 1;i<=k;i++)
	{
		Book a = l.GetAnItem(i);
		fout<<"			<tr>\n";
		fout<<"				<td>"<<i<<"</td>\n";
		fout<<"				<td>"<<a.GetTenSach()<<"</td>\n";
		fout<<"				<td>"<<a.GetTacGia()<<"</td>\n";
		fout<<"				<td>"<<a.GetNam()<<"</td>\n";
		fout<<"				<td>"<<a.GetSoTrang()<<"</td>\n";
		fout<<"			</tr>\n";
	}
	fout<<"		</table>\n";
	fout<<"	</body>\n";
	fout<<"	</html>\n";
	fout.close();
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