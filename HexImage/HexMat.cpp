#include "HexMat.h"

HexMat::HexMat()
{
}

HexMat::~HexMat()
{
}

void HexMat::test(cv::Mat _mat)
{
	using namespace cv;
	using namespace std;
	int x = _mat.cols;
	int y = _mat.rows;

	static double cosTheta[6] = { 0.866025, 0., -0.866025, -0.866025, 0., 0.866025 };
	static double sinTheta[6] = { 0.5,1,0.5,-0.5,-1,-0.5 };

	cout << "_mat: [" << x << "," << y << "]" << endl;

	Mat img = Mat(x * 3, y * 3,CV_8UC3,Scalar(64,64,64));

	Point point[1][6];
	int np[] = { 6 };
	const Point* pp[1] = { point[0] };

	double dx, dy, c0 = 1, c1 = sqrt(3)*c0;

	Scalar C;
	int i, j;
	for (i = 0; i < x; i++)
	{
		for ( j = 0; j < y; j++)
		{
			j % 2 ? dx = (i - 0.5) * c1 : dx = i * c1;
			dy = c0 * j * 1.5;
			for (int k = 0; k < 6; k++)
			{
				point[0][k].x = cvRound(dx+c0 * cosTheta[k]);
				point[0][k].y = cvRound(dy+c0 * sinTheta[k]);
			}
			C = _mat.at<Vec3b>(j, i);
			fillConvexPoly(img, *pp, *np, C, LINE_AA);

			
		}
	}
	cout << "Cycle: [" << i << "," << j << "]" << endl;
	namedWindow("test", 256);
	imshow("test", img);
}

HexMat::HexMat(cv::Mat _mat)
{
	test(_mat);
	
}

HexMat::HexMat(cv::Mat _mat, int _type)
{
}
