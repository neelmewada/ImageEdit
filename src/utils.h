#pragma once

#include <wx/wx.h>
//#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace cv;

wxImage wx_from_mat(Mat& img);
Mat mat_from_wx(wxImage& wx);

wxImage wx_from_mat(Mat& img) 
{
    Mat im2;
    if (img.channels() == 1) { cvtColor(img, im2, COLOR_GRAY2RGB); }
    else if (img.channels() == 4) { cvtColor(img, im2, COLOR_BGRA2RGB); }
    else { cvtColor(img, im2, COLOR_BGR2RGB); }
    long imsize = im2.rows * im2.cols * im2.channels();
    wxImage wx(im2.cols, im2.rows, (unsigned char*)malloc(imsize), false);
    unsigned char* s = im2.data;
    unsigned char* d = wx.GetData();
    for (long i = 0; i < imsize; i++) { d[i] = s[i]; }
    return wx;
}

Mat mat_from_wx(wxImage& wx) 
{
    Mat im2(Size(wx.GetWidth(), wx.GetHeight()), CV_8UC3, wx.GetData());
    cvtColor(im2, im2, COLOR_RGB2BGR);
    return im2;
}