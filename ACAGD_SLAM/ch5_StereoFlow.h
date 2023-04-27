#pragma once
#include <vector>
#include <Eigen/Core>
class ch5_StereoFlow {
public:
    void gldraw();
    void main();

    std::vector<Eigen::Vector4d> pointClouds;
};