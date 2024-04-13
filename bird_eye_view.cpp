#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>

cv::Mat eulerAnglesToRotationMatrix(double roll, double pitch, double yaw) {
    cv::Mat R_x = (cv::Mat_<double>(3,3) <<
                   1, 0, 0,
                   0, cos(roll), -sin(roll),
                   0, sin(roll), cos(roll)
                  );
    cv::Mat R_y = (cv::Mat_<double>(3,3) <<
                   cos(pitch), 0, sin(pitch),
                   0, 1, 0,
                   -sin(pitch), 0, cos(pitch)
                  );
    cv::Mat R_z = (cv::Mat_<double>(3,3) <<
                   cos(yaw), -sin(yaw), 0,
                   sin(yaw), cos(yaw), 0,
                   0, 0, 1
                  );
    return R_z * R_y * R_x;
}

int main() {
    double pitch = -CV_PI / 2, roll = 0, yaw = 0; // Adjust pitch for a top-down view
    cv::Mat image = cv::imread("/home/zdeng/aeroplan/code/Jackal-OpenCV/data/front_view_robot.png");
    cv::Mat output;

    if (image.empty()) {
        std::cout << "Could not open or find the image" << std::endl;
        return -1;
    }

    cv::Mat K = (cv::Mat_<double>(3,3) <<
                 560.1915283203125, 0, 490.475341796875,
                 0, 560.1915283203125, 296.8459777832031,
                 0, 0, 1);
    cv::Mat R = eulerAnglesToRotationMatrix(roll, pitch, yaw);
    cv::Mat H = K * (R.inv());
    H = H / H.at<double>(2,2);

    std::cout << "Rotation Matrix: " << R << std::endl;
    std::cout << "Intrinsic Matrix: " << K << std::endl;
    std::cout << "Homography Matrix: " << H << std::endl;

    cv::warpPerspective(image, output, H.inv(), image.size(), cv::INTER_LINEAR, cv::BORDER_CONSTANT);
    cv::imshow("Bird's Eye View", output);
    cv::waitKey(0);

    return 0;
}
