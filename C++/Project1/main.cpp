#include <iostream>
#include <string>
#include <algorithm>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;



int main() {


	Mat dogImg, natureImg, result, resultBlur;

	long start = getTickCount();
	natureImg = imread("nature.jpg");
	long end = getTickCount();
	cout << "Image reading duration: " << (end - start) / getTickFrequency() << endl;

	dogImg = imread("dog.jpg", IMREAD_GRAYSCALE);
	start = getTickCount();
	threshold(dogImg, result, 100, 250, THRESH_BINARY);
	end = getTickCount();
	cout << "Binary threshold duration: " << (end - start) / getTickFrequency() << endl;

	start = getTickCount();
	imwrite("output.jpg", result);
	end = getTickCount();
	cout << "Image writing duration: " << (end - start) / getTickFrequency() << endl;

	start = getTickCount();
	for (int i = 5; i < 201; i += 2) {
		result = imread("nature.jpg", IMREAD_GRAYSCALE);
		medianBlur(result, resultBlur, i);
		end = getTickCount();
		cout << "Image bluring duration, with a kernel size of " << i << ": "
			<< (end - start) / getTickFrequency() << endl;
	}

	waitKey(0);

	return 0;
}