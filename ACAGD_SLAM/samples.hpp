#pragma once
#include <Eigen/Dense>
#include "EasyIO.hpp"
#include <opencv2/opencv.hpp>

inline void sample_eigen() {
    // TODO: Eigen 使用範例
    Eigen::MatrixXd m(2, 2);
    m(0, 0) = 3;
    m(1, 0) = 2.5;
    m(0, 1) = -1;
    m(1, 1) = m(1, 0) + m(0, 1);
}
inline void sample_opencv() {
    auto r1 = EasyIO::getExeDir() + "\\..\\..\\doc\\ch5_stereo\\left.png";
    if (EasyIO::fileExists(r1)) {
        auto r2 = cv::imread(r1);
        cv::imshow("按下esc繼續", r2);
        cv::waitKey(0);
    }
    else {
        std::cout << "檔案不存在";
    }
}