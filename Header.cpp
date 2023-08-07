#include "Header.h"

/********************************************
* @Description Hàm đổi màu chữ console
* @parameter Mã màu muốn đổi
* 
0 = Black         8 = Gray
1 = Blue          9 = Light Blue
2 = Green         10 = Light Green
3 = Aqua          11 = Light Aqua
4 = Red           12 = Light Red
5 = Purple        13 = Light Purple
6 = Yellow        14 = Light Yellow
7 = White         15 = Bright White

********************************************/

void setColor(int color)
{
	WORD wColor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
}

/********************************************
* @Description Hàm đổi màu background và chữ console
* @parameter Mã màu muốn đổi
********************************************/

void setColor(int backgound_color, int text_color)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	int color_code = backgound_color * 16 + text_color;
	SetConsoleTextAttribute(hStdout, color_code);
}

/********************************************
* @Description Hàm lấy timestamp hiện tại
* @return Trả về timestamp hiện tại
********************************************/

long getCurrentTimestamp() {
	time_t now = time(0);
	return now;
}

/********************************************
* @Description Hàm chuyển đổi ngày tháng sang timestamp
* @parameter Ngày, tháng, năm, giờ, phút, giây
* @return Trả về timestamp của ngày tháng đó
********************************************/

long convertDateToTimestamp(int day, int month, int year, int hour = 0, int min = 0, int sec = 0) {
	struct tm  tm;
	time_t rawtime;
	time(&rawtime);
	tm = *localtime(&rawtime);
	tm.tm_year = year - 1900;
	tm.tm_mon = month - 1;
	tm.tm_hour = hour;
	tm.tm_min = min;
	tm.tm_sec = sec;
	tm.tm_mday = day;
	return mktime(&tm);
}

/********************************************
* @Description Hàm lấy ngày tháng hiện tại
* @return Trả về chuỗi ngày tháng hiện tại
********************************************/

string getCurrentDate() {
	string result = "";
	time_t now = time(0);
	tm* ltm = localtime(&now);
	string day, month, year, hour, min;
	stringstream days;
	days << ltm->tm_mday;
	days >> day;
	stringstream months;
	months << (1 + ltm->tm_mon);
	months >> month;
	stringstream years;
	years << (1900 + ltm->tm_year);
	years >> year;
	stringstream hours;
	hours << ltm->tm_hour;
	hours >> hour;
	stringstream mins;
	mins << ltm->tm_min;
	mins >> min;
	if (1 + ltm->tm_mon < 10) {
		month = "0" + month;
	}
	if (ltm->tm_mday < 10) {
		day = "0" + day;
	}
	if (ltm->tm_hour < 10) {
		hour = "0" + hour;
	}
	if (ltm->tm_min < 10) {
		min = "0" + min;
	}
	result = day + "/" + month + "/" + year + " " + hour + ":" + min;
	return result;
}

/********************************************
* @Description Hàm loading
* @parameter Số giây delay và số lần chạy "|"
********************************************/

void loading(int sleep, int n) {
	setColor(0, 6);
	cout << "\n\n\n\n\t\t\t\t\tLOADING...\n\t\t";
	for (int i = 0; i < n; i++) {
		cout << "|";
		Sleep(sleep);
	}
}	

/********************************************
* @Description Hàm xóa khoảng trắng và chuyển thành chữ UpperCase
* @parameter Một chuỗi cần chuyển
* @return Trả về chuỗi sau khi thực hiện
********************************************/

string convertUpperCaseAndDeleteSpace(string x) {
	string result = "";
	for (int i = 0; i < x.size(); i++) {
		if (x[i] >= 'a' && x[i] <= 'z') {
			x[i] = x[i] - 32;
		}
		if (x[i] != ' ') {
			result = result + x[i];
		}
	}
	return result;
}

/********************************************
* @Description Hàm chuyển thành chữ UpperCase
* @parameter Một chuỗi cần chuyển
* @return Trả về chuỗi sau khi thực hiện
********************************************/

string convertUpperCase(string x) {
	for (int i = 0; i < x.size(); i++) {
		if (x[i] >= 'a' && x[i] <= 'z') {
			x[i] = x[i] - 32;
		}
	}
	return x;
}

/********************************************
* @Description Hàm mã hóa chuỗi thành dấu "*"
* @parameter Độ dài của chuỗi tối đa
* @return Trả về chuỗi gốc nhưng hiển thị màn hình thành dấu "*"
********************************************/

string passwordInput(int maxLength) {	
	string pw = "";
	for (char c; (c = getch()); )
	{
		if (c == '\n' || c == '\r') { 
			cout << "\n";
			break;
		}
		else if (c == '\b') { 
			if (!pw.empty()) {
				pw.erase(pw.size() - 1);
				cout << "\b \b";
			}
		}
		else if (isprint(c) && pw.size() < maxLength) {
			cout << '*';
			pw += c;
		}
	}
	return pw;	
}

/********************************************
* @Description Hàm kiểm tra chuỗi có chứa khoảng trắng hay không
* @parameter Một chuỗi cần kiểm tra
* @return Trả về true nếu chuỗi có khoảng trắng, ngược lại trả về false
********************************************/

bool checkContainsSpacing(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			return true;
		}
	}
	return false;
}

/********************************************
* @Description Hàm kiểm tra chuỗi có bao gồm các kí tự số hay không
* @parameter Một chuỗi cần kiểm tra
* @return Trả về true nếu chuỗi toàn kí tự số, ngược lại trả về false
********************************************/

bool checkIsNumberString(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] < '0' || s[i] > '9') {
			return false;
		}
	}
	return true;
}


/********************************************
* @Description Hàm hiển thị menu chức năng
********************************************/

void menuChucNang() {
	setColor(2);
	cout << "\t\t\t\t\t";
	cout << "MENU CHUC NANG:" << endl;
	setColor(7);
	cout << setfill('=');
	cout << "\t\t\t";
	setColor(14);
	cout << setw(50) << "=" << endl;
	cout << setfill(' ');
	cout << "\t\t\t";
	cout << " |";
	cout << "\t";
	setColor(7);
	cout << "0. Thoat chuong trinh. ";
	setColor(14);
	cout << "\t\t\t";
	cout << "|";
	cout << endl;
	cout << "\t\t\t";
	cout << " |";
	cout << "\t";
	setColor(7);
	cout << "1. Hien thi danh sach chuyen bay.  ";
	setColor(14);
	cout << "\t";
	cout << "|";
	cout << endl;
	cout << "\t\t\t";
	cout << " |";
	cout << "\t";
	setColor(7);
	cout << "2. Dat ve.";
	setColor(14);
	cout << "\t\t\t\t";
	cout << "|";
	cout << endl;
	cout << "\t\t\t";
	cout << " |";
	cout << "\t";
	setColor(7);
	cout << "3. Quan ly.";
	setColor(14);
	cout << "\t\t\t\t";
	cout << "|";
	cout << endl;
	cout << "\t\t\t";
	cout << " |";
	cout << "\t";
	setColor(7);
	cout << "Moi ban chon thao tac:";
	setColor(14);
	cout << "\t\t\t";
	cout << "|";
	cout << endl;
	cout << setfill('=');
	cout << "\t\t\t";
	setColor(7);
	setColor(14);
	cout << setw(50) << "=" << endl;
	cout << setfill(' ');
	setColor(7);
	setColor(4);
	cout << "\t\t\t\t Nhap thao tac muon chon: ";
	setColor(7);
}

/********************************************
* @Description Hàm hiển thị menu đăng nhập nhân viên
* @parameter Chuỗi username và password
********************************************/

void dangNhapNhanVien(string& username, string& password) {
	cin.ignore();
	setColor(14);
	cout << setfill('*');
	cout << "\t\t\t";
	cout << setw(60) << "*" << endl;
	cout << setfill(' ');
	setColor(7);
	setColor(14);
	cout << "\t\t\t";
	cout << "*";
	setColor(7);

	setColor(2);
	cout << "                    DANG NHAP HE THONG                    ";
	setColor(7);
	setColor(14);
	cout << "*" << endl;
	setColor(7);
	setColor(14);
	cout << setfill('*');
	cout << "\t\t\t";
	cout << setw(60) << "*" << endl;
	cout << setfill(' ');
	setColor(7);
	setColor(2);
	cout << "\t\t\t";
	cout << "     User";
	setColor(7);
	cout << ":     ";
	getline(cin, username);
	cout << endl;
	setColor(2);
	cout << "\t\t\t";
	cout << "     Password";
	setColor(7);
	cout << ": ";
	password = passwordInput(10);
}

/********************************************
* @Description Hàm hiển thị menu chức năng của nhân viên
********************************************/

void menuAdmin() {
	setColor(2);
	cout << "\t\t\t";
	cout << "\t\t";
	cout << "MENU CHUC NANG NHAN VIEN:" << endl;
	setColor(7);
	cout << setfill('=');
	cout << "\t\t\t";
	setColor(14);
	cout << setw(50) << "=" << endl;
	cout << setfill(' ');
	cout << "\t\t\t";
	cout << " |";
	cout << "\t";
	setColor(7);
	cout << "0. Quay lai. ";
	setColor(14);
	cout << "\t\t\t\t";
	cout << "|";
	cout << endl;
	cout << "\t\t\t";
	cout << " |";
	cout << "\t";
	setColor(7);
	cout << "1. Xu ly dat ve.  ";
	setColor(14);
	cout << "\t\t\t";
	cout << "|";
	cout << endl;
	cout << "\t\t\t";
	cout << " |";
	cout << "\t";
	setColor(7);
	cout << "2. Xu ly tra ve.";
	setColor(14);
	cout << "\t\t\t";
	cout << "|";
	cout << endl;
	cout << "\t\t\t";
	cout << " |";
	cout << "\t";
	setColor(7);
	cout << "3. Thong ke.";
	setColor(14);
	cout << "\t\t\t\t";
	cout << "|";
	cout << endl;
	cout << "\t\t\t";
	cout << " |";
	cout << "\t";
	setColor(7);
	cout << "Moi ban chon thao tac:";
	setColor(14);
	cout << "\t\t\t";
	cout << "|";
	cout << endl;
	cout << setfill('=');
	cout << "\t\t\t";
	setColor(7);
	setColor(14);
	cout << setw(50) << "=" << endl;
	cout << setfill(' ');
	setColor(7);
	setColor(4);
	cout << "\t\t\t\t Nhap thao tac muon chon: ";
	setColor(7);
}

/********************************************
* @Description Hàm hiển thị menu chức năng thống kê của nhân viên
********************************************/

void menuAdminThongKe() {
	setColor(2);
	cout << "\t\t\t";
	cout << "\t\t";
	cout << "MENU CHUC NANG NHAN VIEN:" << endl;
	setColor(7);
	cout << setfill('=');
	cout << "\t\t\t";
	setColor(14);
	cout << setw(65) << "=" << endl;
	cout << setfill(' ');
	cout << "\t\t\t";
	cout << " |";
	cout << "\t";
	setColor(7);
	cout << "0. Quay lai. ";
	setColor(14);
	cout << "\t\t\t\t\t\t";
	cout << "|";
	cout << endl;
	cout << "\t\t\t";
	cout << " |";
	cout << "\t";
	setColor(7);
	cout << "1. Thong ke theo ma chuyen bay.  ";
	setColor(14);
	cout << "\t\t\t";
	cout << "|";
	cout << endl;
	cout << "\t\t\t";
	cout << " |";
	cout << "\t";
	setColor(7);
	cout << "2. Thong ke so lan thuc hien chuyen bay theo may bay.";
	setColor(14);
	cout << "\t";
	cout << "|";
	cout << endl;
	cout << "\t\t\t";
	cout << " |";
	cout << "\t";
	setColor(7);
	cout << "Moi ban chon thao tac:";
	setColor(14);
	cout << "\t\t\t\t\t";
	cout << "|";
	cout << endl;
	cout << setfill('=');
	cout << "\t\t\t";
	setColor(7);
	setColor(14);
	cout << setw(65) << "=" << endl;
	cout << setfill(' ');
	setColor(7);
	setColor(4);
	cout << "\t\t\t\t Nhap thao tac muon chon: ";
	setColor(7);
}