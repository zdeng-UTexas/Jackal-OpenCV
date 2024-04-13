#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Read the image file
    cv::Mat image = cv::imread("./data/front_view_robot.png");
    if (image.empty()) {
        std::cout << "Could not open or find the image" << std::endl;
        return -1;
    }

    cv::Mat image_gray;
    // Convert the image to grayscale
    cv::cvtColor(image, image_gray, cv::COLOR_BGR2GRAY);

    // Save the grayscale image
    cv::imwrite("./data/gray_image.jpg", image_gray);

    std::cout << "Image converted to grayscale and saved!" << std::endl;
    return 0;
}
