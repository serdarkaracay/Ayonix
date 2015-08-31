//
//#include "opencv2/highgui/highgui.hpp"
//
//int main() {
//	std::string filename = "Videotracktest.MOV";
//	cv::VideoCapture capture(filename);
//	cv::Mat frame;
//
//	if (!capture.isOpened())
//		throw "Error when reading steam_avi";
//
//	cv::namedWindow("w", 1);
//	for (;;)
//	{
//		capture >> frame;
//		if (frame.empty())
//			break;
//		imshow("w", frame);
//		cv::waitKey(20); // waits to display frame
//	}
//	cv::waitKey(0); // key press to cl
//
//	return 0;
//}