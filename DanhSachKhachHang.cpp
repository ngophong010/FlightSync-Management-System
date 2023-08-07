#include "DanhSachKhachHang.h"

/********************************************
* @Description Hàm xử lý đọc file cho Danh Sách Khách Hàng
********************************************/

template <class KhachHang>
void DanhSachKhachHang<KhachHang>::xuLyDocFile() {
	ifstream ifile("KhachHang.txt");
	if (!ifile) {
		cout << "Khong mo duoc file KhachHang.txt!" << endl;
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
		if (dataTemp.size() != 3) {
			continue;
		}
		//Khởi tạo đối tượng Khách Hàng mới với 2 tham số
		KhachHang* newItem = new KhachHang(dataTemp[1], dataTemp[2]);
		//Set các thuộc tính cho Khách Hàng vừa tạo
		newItem->setSoThuTu(dataTemp[0]);

		//Thêm vào Danh Sách Khách Hàng
		LinkedList<KhachHang>::addTail (*newItem);
	}
	ifile.close();
}

/********************************************
* @Description Hàm xử lý ghi file cho Danh Sách Khách Hàng
* @parameter Khách Hàng muốn ghi thêm vào file
********************************************/

template <class KhachHang>
void DanhSachKhachHang<KhachHang>::xuLyGhiFile(KhachHang data) {
	ofstream ofile;
	ofile.open("KhachHang.txt", ios::in | ios::app);
	if (LinkedList<KhachHang>::getSize() != 1) {
		ofile << endl;
	}
	ofile << data.thongTinFile();
	ofile.close();
}

/********************************************
* @Description Hàm tìm kiếm một Khách Hàng dựa trên CMND hoặc CCCD trong Danh Sách Khách Hàng
* @parameter CMND/CCCD muốn tìm
* @return Trả về địa chỉ của Khách hàng tìm thấy, nếu không tìm thấy trả về NULL
********************************************/

template <class KhachHang>
KhachHang* DanhSachKhachHang<KhachHang>::timKiemKhachHang(string CMND) {
	Node<KhachHang>* pWalker = LinkedList<KhachHang>::getHead();
	while (pWalker != NULL) {
		if (pWalker->_data.getCMND() == CMND) {
			return &(pWalker->_data);
		}
		pWalker = pWalker->_pNext;
	}
	return NULL;

}