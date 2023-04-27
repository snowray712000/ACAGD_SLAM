#pragma once
// 專案屬性已設定
// include目錄： $(SolutionDir)include ; $(SolutionDir)include/eigen;
// lib額外目錄： $(SolutionDir)lib;

#define GLAD_GL_IMPLEMENTATION 
#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <Eigen/Dense>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "EasyIO.hpp"

// 連結 glfw 函式庫
// lib 資料夾提供了 3 個常見版本，若 Visual Studio 不是這3個版本的，請自行去 glfw 官網下載
// https://www.glfw.org/download.html 64-bit windows binaries 版
// #pragma comment(lib,"glfw3_x64_v2017.lib")
#pragma comment(lib,"glfw3_x64_v2019.lib")
// #pragma comment(lib,"glfw3_x64_v2022.lib")

// 連結 opencv 函式庫
#ifdef _DEBUG
#pragma comment(lib,"opencv_world470d.lib")
#else
#pragma comment(lib,"opencv_world470.lib")
#endif // DEBUG
