#include <stdio.h>
#include <math.h>
#include <opencv\cv.h>
#include <opencv\highgui.h>
#include <opencv2\objdetect\objdetect.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <vector>

using namespace cv;
using namespace std;

int main()
{
	CascadeClassifier face_cascade_classifier, eye_cascade_classifier;

	if (!face_cascade_classifier.load("F:\\msdn\\OpenCv\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_alt2.xml"))
	{
		printf("face cascade file yüklenemedi.");
		return 1;
	}

	if (!eye_cascade_classifier.load("F:\\msdn\\OpenCv\\opencv\\sources\\data\\haarcascades\\haarcascade_eye.xml"))
	{
		printf("eye cascade file yuklenemedi.");
		return 1;
	}

	string filename = "Videotracktest.MOV";
	VideoCapture capture(filename);
	Mat cap_img, gray_img;

	if (!capture.isOpened())
	{
		printf("video oynatilamadi");
		return 1;
	}

	vector<Rect> faces_rects, eye_rects;
	while (1)
	{
		capture >> cap_img;
		waitKey(100);
		cvtColor(cap_img, gray_img, CV_BGR2GRAY);
		cv::equalizeHist(gray_img, gray_img);
		face_cascade_classifier.detectMultiScale(gray_img, faces_rects, 1.1, 10, CV_HAAR_SCALE_IMAGE | CV_HAAR_DO_CANNY_PRUNING, cvSize(0, 0), cvSize(300, 300));

		for (auto i = 0; i < faces_rects.size(); i++)
		{
			Point pt1_point(faces_rects[i].x + faces_rects[i].width, faces_rects[i].y + faces_rects[i].height);
			Point ptr2_point(faces_rects[i].x, faces_rects[i].y);
			Mat face_mat = gray_img(faces_rects[i]);
		//	eye_cascade_classifier.detectMultiScale(face_mat, eye_rects, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, cvSize(30, 30));

		/*	for (size_t j = 0; j < eye_rects.size(); j++)
			{
				Point center(faces_rects[i].x + eye_rects[j].x + eye_rects[j].width*0.5, faces_rects[i].y + eye_rects[j].y + eye_rects[j].height*0.5);
				int elips = cvRound((eye_rects[j].width + eye_rects[j].height)*0.25);
				circle(cap_img, center, elips, Scalar(255, 0, 0), 2, 8, 0);

			}*/

			rectangle(cap_img, pt1_point, ptr2_point, cvScalar(0, 255, 0), 2, 8, 0);
			imshow("trac", cap_img);
			waitKey(3);
			char c = waitKey(3);
			if (c == 27)
				break;
		}
	}
}