#pragma once
#include <opencv.hpp>

class HexMat
{
public:
	HexMat();
	~HexMat();
public:
	void test(cv::Mat _mat);
public:
	HexMat(cv::Mat _mat);
	HexMat(cv::Mat _mat, int _type);

public:
	int type = 0;
	
	

};

