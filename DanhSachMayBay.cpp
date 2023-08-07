#include "DanhSachMayBay.h"
#include "LinkedList.h"

/********************************************
* @Description Hàm xử lý đọc file cho Danh Sách Máy Bay
********************************************/

template <class MayBay>
void DanhSachMayBay<MayBay>::xuLyDocFile() {
	ifstream ifile("MayBay.txt");
	if (!ifile) {
		cout << "Khong mo duoc file MayBay.txt!" << endl;
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
		if (dataTemp.size() != 2) {
			continue;
		}
		//Khởi tạo một đối tượng Máy Bay mới
		MayBay* newItem = new MayBay();
		//Set các thuộc tính cho đối tượng
		newItem->setSoHieuMayBay(dataTemp[0]);
		newItem->setSoCho(dataTemp[1]);

		//Thêm vào danh sách máy bay
		LinkedList<MayBay>::addTail(*newItem);
	}
	ifile.close();
}

/********************************************
* @Description Hàm tìm kiếm Máy bay cho Danh Sách Máy Bay
* @parameter Chuỗi Số hiệu máy bay cần tìm
* @return Trả về địa chỉ của Máy Bay tìm thấy, nếu không tìm thấy thì trả về NULL
********************************************/

template <class MayBay>
MayBay* DanhSachMayBay<MayBay>::timKiemMayBay(string soHieuMayBay) {
	Node<MayBay>* pWalker = LinkedList<MayBay>::getHead();
	while (pWalker != NULL) {
		if (pWalker->_data.getSoHieuMayBay() == soHieuMayBay) {
			return &(pWalker->_data);
		}
		pWalker = pWalker->_pNext;
	}
	return NULL;
}