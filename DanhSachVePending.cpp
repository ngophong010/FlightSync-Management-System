#include "DanhSachVePending.h"
#include "Queue.h"
#include "Ve.h"
#include "Header.h"

/********************************************
* @Description Hàm xử lý đọc file cho Danh Sách Vé Đang Chờ
********************************************/

template <class Ve>
void DanhSachVePending<Ve>::xuLyDocFile() {
	ifstream ifile("VeDangCho.txt");
	if (!ifile) {
		cout << "Khong mo duoc file VeDangCho.txt!" << endl;
		exit(1);
		return;
	}
	string s;
	while (getline(ifile, s)) {
		stringstream ss(s);
		string temp;
		vector<string> dataTemp;
		while (getline(ss, temp, '|')) {
			dataTemp.push_back(temp);
		}
		if (dataTemp.size() != 6) {
			continue;
		}
		//Khởi tạo một đối tượng Vé mới
		Ve* newItem = new Ve(dataTemp[0], dataTemp[1], dataTemp[2], dataTemp[3]);
		//Set các thuộc tính cho Vé đó
		newItem->setSoGhe(dataTemp[4]);
		newItem->setDate(dataTemp[5]);
		newItem->setTimestamp();

		//Them vào danh sách vé Cần chờ xử lý
		Queue<Ve>::enQueue(*newItem);
	}
	ifile.close();
}

/********************************************
* @Description Hàm xử lý ghi file cho Danh Sách Vé Đang Chờ
* @parameter Vé muốn ghi vào file
********************************************/

template <class Ve>
void DanhSachVePending<Ve>::xuLyGhiFile(Ve data) {
	ofstream ofile;
	ofile.open("VeDangCho.txt", ios::in | ios::app);
	if (Queue<Ve>::getSize() != 1) {
		ofile << endl;
	}
	ofile << data.thongTinFile();
	ofile.close();
}

/********************************************
* @Description Hàm xử lý cập nhật lại file cho Danh Sách Vé Đang Chờ
********************************************/

template <class Ve>
void DanhSachVePending<Ve>::updateFile() {
	ofstream ofile;
	ofile.open("VeDangCho.txt", ios::out);	
	for (int i = 0; i < Queue<Ve>::getSize(); i++) {
		Ve data = Queue<Ve>::peek();
		ofile << data.thongTinFile();
		if (i != Queue<Ve>::getSize() - 1) {
			ofile << endl;
		}
	}
	ofile.close();
}
