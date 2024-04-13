#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Define a 3D point (homogeneous coordinates)
    cv::Mat point3D = (cv::Mat_<double>(4,1) << 1.0, 2.0, 3.0, 1.0);

    // Define a 3D transformation matrix (4x4)
    cv::Mat H = (cv::Mat_<double>(4,4) <<
                 1, 0, 0, 1,
                 0, 1, 0, 2,
                 0, 0, 1, 3,
                 0, 0, 0, 1);

    std::cout << "Original Point: " << point3D.t() << std::endl;

    // Apply the 3D homography transformation
    cv::Mat transformedPoint = H * point3D;

    std::cout << "Transformed Point: " << transformedPoint.t() << std::endl;

    return 0;
}
