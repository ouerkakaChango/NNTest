#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

#include<opencv2/core/core.hpp>  
#include<opencv2/highgui/highgui.hpp>  

using namespace std;
using namespace cv;
class cvUtil
{
public:
	cvUtil();
	~cvUtil();
};
vector<int> GetVecFromImg(string path,int channel=3);
void log(vector<int>& vec);
double rand_n1_1();

vector<int>& GetInputOf(int n);
vector<int>& GetOutputOf(int n);

