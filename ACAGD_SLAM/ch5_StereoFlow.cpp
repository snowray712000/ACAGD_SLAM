#include "ch5_StereoFlow.h"
#include <glad/gl.h>
#include "EasyIO.hpp"
#include <opencv2/opencv.hpp>
void ch5_StereoFlow::gldraw() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-300,500,-300,500,10000,-10000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	glPointSize(2);
	glBegin(GL_POINTS);
	double mx[3] = { 99999,99999,99999 };
	double mmx[3] = { -99999,-99999,-99999 };
	for (auto& a1 : pointClouds) {
		auto r1 = a1[3];
		glColor3f(r1, r1, r1);
		glVertex3dv(a1.data());

		// xyz
		for (size_t i = 0; i < 3; i++)
		{
			auto v = a1[i];
			if (v < mx[i]) {
				mx[i] = v;
			}
			if (v > mmx[i]) {
				mmx[i] = v;
			}
		}
	}
	glEnd();

	std::cout << mx[0] << " " << mx[1] << " " << mx[2] << " " << mmx[0] << " " << mmx[1] << " " << mmx[2] << "\n";
}

void ch5_StereoFlow::main() {
	// 内参
	double fx = 718.856, fy = 718.856, cx = 607.1928, cy = 185.2157;
	// 基线
	double b = 0.573;

	// 讀檔
	auto r1 = EasyIO::getExeDir() + "/../../doc/ch5_stereo/left.png";
	auto r2 = EasyIO::getExeDir() + "/../../doc/ch5_stereo/right.png";
	auto left = cv::imread(r1);
	auto right = cv::imread(r2);
	//cv::imshow("left", left);
	//cv::imshow("right", right);

	cv::Ptr<cv::StereoSGBM> sgbm = cv::StereoSGBM::create(
		0, 96, 9, 8 * 9 * 9, 32 * 9 * 9, 1, 63, 10, 100, 32);    // 神奇的参数
	cv::Mat disparity_sgbm, disparity;
	sgbm->compute(left, right, disparity_sgbm);
	disparity_sgbm.convertTo(disparity, CV_32F, 1.0 / 16.0f);
	cv::imshow("disparity", disparity / 96.0);

	using Eigen::Vector4d;
	// 如果你的机器慢，请把后面的v++和u++改成v+=2, u+=2
	for (int v = 0; v < left.rows; v++) {
		for (int u = 0; u < left.cols; u++) {
			if (disparity.at<float>(v, u) <= 0.0 || disparity.at<float>(v, u) >= 96.0) continue;

			Vector4d point(0, 0, 0, left.at<uchar>(v, u) / 255.0); // 前三维为xyz,第四维为颜色

			// 根据双目模型计算 point 的位置
			double x = (u - cx) / fx;
			double y = (v - cy) / fy;
			double depth = fx * b / (disparity.at<float>(v, u));
			point[0] = x * depth;
			point[1] = y * depth;
			point[2] = depth;

			pointClouds.push_back(point);
		}
	}

}