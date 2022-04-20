#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "opencv2/core/utils/logger.hpp"
#include <stdint.h>
#include <bits/stdc++.h>
#include <fstream>
using namespace cv;
using namespace std;





void main() {
	cv::utils::logging::setLogLevel(cv::utils::logging::LogLevel::LOG_LEVEL_SILENT);
	ifstream ifile;
	ifile.open("ASCII VALUES/Values.txt");
	vector<int> grey_value;
	for (int i = 0; i < (126 - 33 + 1); i++) {
		int x; 
		ifile >> x >> x;
		grey_value.push_back(x);
	}
	float max = *max_element(grey_value.begin(), grey_value.end());
	for (int i = 0; i < (126 - 33 + 1); i++) {
		grey_value[i] = 255 - grey_value[i] / max * 255;
	}
	cout << "Enter image file path (add file extension) :";
	string imgname;
	getline(cin, imgname, '\n');
	cout << "Enter output txt file path (add .txt at the end): ";
	string of;
	getline(cin, of, '\n');
	float Scale = 1;
	cout << "Enter Scale (1 low quality - 4 high quality): ";
	cin >> Scale;
	Mat img = imread(imgname);
	ofstream ofile;
	ofile.open(of);
	cout << "add contrast 0-2 (1-1.5 recommended): ";
	double c;
	cin >> c;
	Mat imgBW,imgC;
	cvtColor(img, imgBW, COLOR_BGR2GRAY);
	imgBW.convertTo(imgC, -1, c, 0);
	
	int incr, incc;
	
	incr = 50 * Scale;
	incc = incr * 2 * (float)img.cols / img.rows;

	for (int r = 0; r < imgC.rows; r+=img.rows/incr) {
		for (int c = 0; c < imgC.cols; c+=img.cols/incc) {
			if (imgC.at<uint8_t>(r, c) == 255) {
				ofile << " ";
				continue;
			}
			int x = imgC.at<uint8_t>(r, c);
			int ci = 0;
			for (int a = 34; a <= 126; a++) { 
				if (abs(grey_value[ci] - x) > abs(grey_value[a - 33] - x))
					ci = a - 33;
			}
			ofile << (char)(ci + 33);
		}
		ofile << endl;
	}
	Mat res;
	if (img.cols > 900)
		resize(imgC, res, Size((float)img.cols / img.rows * 400, 400), INTER_LINEAR);
	else
		res = imgC;
	imshow("BW with contrast", res);
	waitKey(0);
}