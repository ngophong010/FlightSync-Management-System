#include "Ve.h"

/********************************************
* @Description Hàm khởi tạo Vé mới
********************************************/

Ve::Ve() {
	_strMaVe = "";
	_strMaChuyenBay = "";
	_iSoGhe = 0;
	_lTimestamp = 0;
	_strDate = "";
}

/********************************************
* @Description Hàm khởi tạo Vé mới
* @parameter Chuỗi mã vé, chuỗi mã chuyến bay, chuỗi CMND/CCCD, chuỗi Họ Tên
********************************************/

Ve::Ve(string maVe, string maChuyenBay, string CMND, string hoTen) {
	_strMaVe = maVe;
	_strMaChuyenBay = maChuyenBay;
	_strCMND = CMND;
	_strHoTen = hoTen;
	_lTimestamp = 0;
	_strDate = "";
}

/********************************************
* @Description Hàm khởi tạo Vé mới
* @parameter Chuỗi mã vé, chuỗi mã chuyến bay, chuỗi CMND/CCCD, chuỗi Họ Tên, số ghế
********************************************/

Ve::Ve(string maVe, string maChuyenBay, string CMND, string hoTen, int soGhe) {
	_strMaVe = maVe;
	_strMaChuyenBay = maChuyenBay;
	_strCMND = CMND;
	_strHoTen = hoTen;
	_iSoGhe = soGhe;
	_lTimestamp = 0;
	_strDate = "";
}

/********************************************
* @Description Hàm khởi tạo Vé mới
* @parameter Chuỗi mã vé, chuỗi mã chuyến bay, chuỗi CMND/CCCD, chuỗi Họ Tên, số ghế, ngày tạo
********************************************/

Ve::Ve(string maVe, string maChuyenBay, string CMND, string hoTen, int soGhe, string date) {
	_strMaVe = maVe;
	_strMaChuyenBay = maChuyenBay;
	_strCMND = CMND;
	_strHoTen = hoTen;
	_iSoGhe = soGhe;
	_lTimestamp = 0;
	_strDate = date;
}

/********************************************
* @Description Hàm set số ghế cho Vé
* @parameter Chuỗi số ghế
* @attention Chuyển từ chuỗi số ghế thành số ghế, sau đó cập nhật cho Vé
********************************************/

void Ve::setSoGhe(string temp) {
	stringstream ss(temp);
	int soGhe;
	ss >> soGhe;
	_iSoGhe = soGhe;
}

/********************************************
* @Description Hàm lấy thông tin của Vé để chuẩn bị ghi file
* @return Chuỗi thông tin của Vé, ngăn cách bởi "|"
********************************************/

string Ve::thongTinFile() {
	string result = "";
	stringstream ss;
	ss << _iSoGhe;
	string soGheString;
	ss >> soGheString;
	result = _strMaVe + "|" + _strMaChuyenBay + "|" + _strCMND + "|" + _strHoTen + "|" + soGheString + "|" + _strDate;
	return result;
}

/********************************************
* @Description Hàm hiển thị thông tin của Vé
********************************************/

void Ve::display() {
	cout << _strMaVe << "|" << _strMaChuyenBay << "|" << _strCMND << "|" << _strHoTen << "|" << _iSoGhe << "|" << _strDate;
}

/********************************************
* @Description Hàm hiển thị thông tin chi tiết của Vé
********************************************/

void Ve::displayDetail() {
	cout << setw(20) << left << _strMaVe;
	cout << setw(20) << left << _strMaChuyenBay;
	cout << setw(20) << left << _strCMND;
	cout << setw(20) << left << _strHoTen;
	cout << setw(20) << left << _iSoGhe;
	cout << setw(50) << left << _strDate << endl;
}

/********************************************
* @Description Hàm lấy thông tin mã chuyến bay của Vé
* @return Chuỗi mã chuyến bay của Vé
********************************************/

string Ve::getMaChuyenBay() {
	return _strMaChuyenBay;
}

/********************************************
* @Description Hàm lấy thông tin mã vé của Vé
* @return Chuỗi mã vé của Vé
********************************************/

string Ve::getMaVe() {
	return _strMaVe;
}

/********************************************
* @Description Hàm lấy thông tin số ghế của Vé
* @return Số ghế của Vé
********************************************/

int Ve::getSoGhe() {
	return _iSoGhe;
}

/********************************************
* @Description Hàm lấy thông tin họ tên của Vé
* @return Chuỗi họ tên của Vé
********************************************/

string Ve::getHoTen() {
	return _strHoTen;
}

/********************************************
* @Description Hàm lấy thông tin ngày tạo của Vé
* @return Chuỗi ngày tạo của Vé
********************************************/

string Ve::getDate() {
	return _strDate;
}

/********************************************
* @Description Hàm tạo file mới với tên là Mã vé của Vé
********************************************/

void Ve::createFile() {
	char* fileName;
	ofstream ofile;
	string strFile =  _strMaVe + ".txt";
	fileName = new char[strFile.length() + 1];
	strcpy(fileName, strFile.c_str());
	if (fileName != NULL)
	{
		ofile.open(fileName, ios_base::out);
		ofile << thongTinFile();
		ofile.close();
	}
	delete[] fileName;
}

/********************************************
* @Description Hàm xóa file vé đã được tạo với tên là Mã vé của Vé
********************************************/

void Ve::deleteFile() {
	string strFile = _strMaVe + ".txt";
	char* fileName;
	fileName = new char[strFile.length() + 1];
	strcpy(fileName, strFile.c_str());
	int status = remove(fileName);
	if (status != 0) {
		cout << "Error delete file." << endl;
	} 
}

/********************************************
* @Description Hàm set ngày tạo cho Vé
* @parameter Chuỗi ngày tháng 
********************************************/

void Ve::setDate(string date) {
	_strDate = date;
}

/********************************************
* @Description Hàm set timestamp cho Vé
********************************************/

void Ve::setTimestamp() {
	string temp;
	stringstream s(_strDate);
	vector<string> separateData;
	vector<int> result;
	while (getline(s, temp, ' ')) {
		separateData.push_back(temp);
	}
	if (separateData.size() == 2) {
		stringstream ss;
		ss << (separateData[0]);
		while (getline(ss, temp, '/')) {
			stringstream sss(temp);
			int data;
			sss >> data;
			result.push_back(data);
		}
		stringstream ssss;
		ssss << (separateData[1]);
		while (getline(ssss, temp, ':')) {
			stringstream sssss(temp);
			int data;
			sssss >> data;
			result.push_back(data);
		}
		long convertTimestamp = convertDateToTimestamp(result[0], result[1], result[2], result[3], result[4], 0);
		_lTimestamp = convertTimestamp;
	}
}


