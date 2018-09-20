#ifndef main_cpp
#define main_cpp
#include <iostream>
using namespace std;
#include "book.h"
#include "list.h"
#include <stdlib.h>

int main()
{
	List<Book> l;

	int option;

	bool f = true;
	do
	{
		system("clear");
		option = Menu();
		switch(option)
		{
			case 1:
				ThemSach(l);
				break;
			case 2:
				HienThi(l);
				break;
			case 3:
				LuuXuongFile(l);
				break;
			case 4: 
				MoTuFile(l);
				break;
			case 5:
				SuaSach(l);
			case 6:
				
				break;
			case 0:
				break;
		};
		if(option == 0)
			f = false;
		else
		{
			cout<<"\n Nhap phim Enter de tiep tuc ->";
			cin.ignore();
			cin.get();
		}
	}
	while(f);
	return 0;
}
#endif