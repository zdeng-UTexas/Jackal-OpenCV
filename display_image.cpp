#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Read the image file
    cv::Mat image = cv::imread("./data/front_view_robot.png");

    // Check for failure
    if (image.empty()) {
        std::cout << "Could not open or find the image" << std::endl;
        std::cin.get();  //wait for any key press
        return -1;
    }

    // Create a window
    cv::namedWindow("Window", cv::WINDOW_NORMAL);

    // Show our image inside the created window.
    cv::imshow("Window", image);

    // Wait for any keystroke in the window
    cv::waitKey(0);

    return 0;
}
