#pragma once


#include <wx/wx.h>
//#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;


wxImage wx_from_mat(Mat& img);
Mat mat_from_wx(wxImage& wx);


