#include "stdafx.h"
#include "cvUtil.h"


cvUtil::cvUtil()
{
}


cvUtil::~cvUtil()
{
}

vector<int> GetVecFromImg(string path,int channel) {
	vector<int> re;
	Mat mat = imread(path, CV_LOAD_IMAGE_UNCHANGED);
	if (mat.empty()) {
		cout << "Í¼Ïñ¼ÓÔØÊ§°Ü£¡" << endl;
		throw;
		return re;
	}
	if (channel == 3) {
		cout << "rows:" << mat.rows << " cols:" << mat.cols << " channels:" << mat.channels() << endl;
		int flag = 1;
		for (int i = 0; i < mat.rows; i++) {
			uchar *data = mat.ptr<uchar>(i);
			for (int j = 0; j < mat.cols*mat.channels(); j++) {
				flag++;
				if (flag == 3) {
					flag = 0;
					if ((int)data[j] == 255) {
						//°×
						re.push_back(0);
					}
					else {
						re.push_back(1);
					}
				}
			}
		}
	}
	return re;
}

void log(vector<int>& vec) {
	for (auto& i : vec) {
		cout << i << endl;
	}
}

double rand_n1_1() {
	static std::random_device rd;
	static std::mt19937 gen1(rd());
	static uniform_real_distribution<> dis1(-1.0, 1.0);
	return dis1(gen1);
}
vector<int>& GetInputOf(int n) {
	static vector<int> re0, re1, re2, re3, re4, re5, re6, re7, re8, re9;
	if (re0.size() == 0) {
		re0= GetVecFromImg("D:\\XCNNtest\\zero_5.bmp");
	}
	if (re1.size() == 0) {
		re1= GetVecFromImg("D:\\XCNNtest\\one_5.bmp");
	}
	if (re2.size() == 0) {
		re2 = GetVecFromImg("D:\\XCNNtest\\two_5.bmp");
	}
	if (re3.size() == 0) {
		re3 = GetVecFromImg("D:\\XCNNtest\\three_5.bmp");
	}
	if (re4.size() == 0) {
		re4 = GetVecFromImg("D:\\XCNNtest\\four_5.bmp");
	}
	if (re5.size() == 0) {
		re5 = GetVecFromImg("D:\\XCNNtest\\five_5.bmp");
	}
	if (re6.size() == 0) {
		re6 = GetVecFromImg("D:\\XCNNtest\\six_5.bmp");
	}
	if (re7.size() == 0) {
		re7 = GetVecFromImg("D:\\XCNNtest\\seven_5.bmp");
	}
	if (re8.size() == 0) {
		re8 = GetVecFromImg("D:\\XCNNtest\\eight_5.bmp");
	}
	if (re9.size() == 0) {
		re9 = GetVecFromImg("D:\\XCNNtest\\nine_5.bmp");
	}
	//////////////////////////////////
	if (n == 0) {
		return re0;
	}
	else if (n == 1) {
		return re1;
	}
	else if (n == 2) {
		return re2;
	}
	else if (n == 3) {
		return re3;
	}
	else if (n == 4) {
		return re4;
	}
	else if (n == 5) {
		return re5;
	}
	else if (n == 6) {
		return re6;
	}
	else if (n == 7) {
		return re7;
	}
	else if (n == 8) {
		return re8;
	}
	else if (n == 9) {
		return re9;
	}
	else {
		throw;
		return vector<int>();
	}
}

vector<int>& GetOutputOf(int n) {
	static vector<int> re0,re1,re2,re3,re4,re5,re6,re7,re8,re9;
	if (n == 0) {
		if (re0.size() == 0) {
			re0.push_back(1);
			re0.push_back(0);
			re0.push_back(0);
			re0.push_back(0);
			re0.push_back(0);
			re0.push_back(0);
			re0.push_back(0);
			re0.push_back(0);
			re0.push_back(0);
			re0.push_back(0);
		}
		return re0;
	}
	else if (n == 1) {
		if (re1.size() == 0) {
			re1.push_back(0);
			re1.push_back(1);
			re1.push_back(0);
			re1.push_back(0);
			re1.push_back(0);
			re1.push_back(0);
			re1.push_back(0);
			re1.push_back(0);
			re1.push_back(0);
			re1.push_back(0);
		}
		return re1;
	}
	else if (n == 2) {
		if (re2.size() == 0) {
			re2.push_back(0);
			re2.push_back(0);
			re2.push_back(1);
			re2.push_back(0);
			re2.push_back(0);
			re2.push_back(0);
			re2.push_back(0);
			re2.push_back(0);
			re2.push_back(0);
			re2.push_back(0);
		}
		return re2;
	}
	else if (n == 3) {
		if (re3.size() == 0) {
			re3.push_back(0);
			re3.push_back(0);
			re3.push_back(0);
			re3.push_back(1);
			re3.push_back(0);
			re3.push_back(0);
			re3.push_back(0);
			re3.push_back(0);
			re3.push_back(0);
			re3.push_back(0);
		}
		return re3;
	}
	else if (n == 4) {
		if (re4.size() == 0) {
			re4.push_back(0);
			re4.push_back(0);
			re4.push_back(0);
			re4.push_back(0);
			re4.push_back(1);
			re4.push_back(0);
			re4.push_back(0);
			re4.push_back(0);
			re4.push_back(0);
			re4.push_back(0);
		}
		return re4;
	}
	else if (n == 5) {
		if (re5.size() == 0) {
			re5.push_back(0);
			re5.push_back(0);
			re5.push_back(0);
			re5.push_back(0);
			re5.push_back(0);
			re5.push_back(1);
			re5.push_back(0);
			re5.push_back(0);
			re5.push_back(0);
			re5.push_back(0);
		}
		return re5;
	}
	else if (n == 6) {
		if (re6.size() == 0) {
			re6.push_back(0);
			re6.push_back(0);
			re6.push_back(0);
			re6.push_back(0);
			re6.push_back(0);
			re6.push_back(0);
			re6.push_back(1);
			re6.push_back(0);
			re6.push_back(0);
			re6.push_back(0);
		}
		return re6;
	}
	else if (n == 7) {
		if (re7.size() == 0) {
			re7.push_back(0);
			re7.push_back(0);
			re7.push_back(0);
			re7.push_back(0);
			re7.push_back(0);
			re7.push_back(0);
			re7.push_back(0);
			re7.push_back(1);
			re7.push_back(0);
			re7.push_back(0);
		}
		return re7;
	}
	else if (n == 8) {
		if (re8.size() == 0) {
			re8.push_back(0);
			re8.push_back(0);
			re8.push_back(0);
			re8.push_back(0);
			re8.push_back(0);
			re8.push_back(0);
			re8.push_back(0);
			re8.push_back(0);
			re8.push_back(1);
			re8.push_back(0);
		}
		return re8;
	}
	else if (n == 9) {
		if (re9.size() == 0) {
			re9.push_back(0);
			re9.push_back(0);
			re9.push_back(0);
			re9.push_back(0);
			re9.push_back(0);
			re9.push_back(0);
			re9.push_back(0);
			re9.push_back(0);
			re9.push_back(0);
			re9.push_back(1);
		}
		return re9;
	}
	else {
		return vector<int>();
	}
}