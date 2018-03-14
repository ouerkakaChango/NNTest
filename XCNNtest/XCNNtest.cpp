// XCNNtest.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "windows.h"

#include "cvUtil.h"
#include "SimpleNN.h"

//图片大小:width=32,height=64
int main()
{
	//auto tVec = GetVecFromImg("D:\\XCNNtest\\one_5.bmp");
	//log(GetInputOf(0));
	//log(GetInputOf(1));
	//log(GetInputOf(2));
	//log(GetInputOf(3));
	//log(GetInputOf(4));
	//log(GetInputOf(5));
	//log(GetInputOf(6));
	//log(GetInputOf(7));
	//log(GetInputOf(8));
	//log(GetInputOf(9));
	
	//destroyWindow("MyWindow");

	//隐藏层5节点，输出层10节点，数字0-9
	SimpleNN nn(25,6,10);
	double err = 1.0;
	for (int i = 0; i <= 9; i++) {
		while (1) {
			nn.feed(GetInputOf(i));
			err = nn.GetError(GetOutputOf(i));
			//cout << "误差:" << err << endl;
			if (err < 0.1) {
				cout << "充分训练后的结果:" << nn.GetResult()<<endl;
				break;
			}
			nn.bp(GetOutputOf(i));
		}
	}

	for (int i = 0; i <= 9; i++) {
		nn.feed(GetInputOf(i));
		cout << "识别结果：" << nn.GetResult() << endl;
	}

	system("pause");
    return 0;
}

