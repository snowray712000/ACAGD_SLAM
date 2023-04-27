#pragma once
// �M���ݩʤw�]�w
// include�ؿ��G $(SolutionDir)include ; $(SolutionDir)include/eigen;
// lib�B�~�ؿ��G $(SolutionDir)lib;

#define GLAD_GL_IMPLEMENTATION 
#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <Eigen/Dense>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "EasyIO.hpp"

// �s�� glfw �禡�w
// lib ��Ƨ����ѤF 3 �ӱ`�������A�Y Visual Studio ���O�o3�Ӫ������A�Цۦ�h glfw �x���U��
// https://www.glfw.org/download.html 64-bit windows binaries ��
// #pragma comment(lib,"glfw3_x64_v2017.lib")
#pragma comment(lib,"glfw3_x64_v2019.lib")
// #pragma comment(lib,"glfw3_x64_v2022.lib")

// �s�� opencv �禡�w
#ifdef _DEBUG
#pragma comment(lib,"opencv_world470d.lib")
#else
#pragma comment(lib,"opencv_world470.lib")
#endif // DEBUG
