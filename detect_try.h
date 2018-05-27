#include "opencv2/ximgproc/segmentation.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
 
using namespace cv;
using namespace cv::ximgproc::segmentation;

class Detect{
    int H_low, H_high;
    int S_low, S_high; 
    int V_low, V_high;
    std::vector<Rect> rects; 
public:
    Detect (int, int, int, int, int, int);
    void select_search (Mat);
    std::vector<Rect> get_rects (); 
    std::vector<Rect> select_rects (Mat); //find the rects that we want here by color (hsv)
 };

Detect::Detect (int hl, int hh, int sl, int sh, int vl, int vh){
    H_low = hl; H_high = hh; 
    S_low = sl; S_high = sh; 
    V_low = vl; V_high = vh;
 }
 
void Detect::select_search (Mat im) { //turns out this is too slow 
    // create Selective Search Segmentation Object using default parameters
    Ptr<SelectiveSearchSegmentation> ss = createSelectiveSearchSegmentation();
    // set input image on which we will run segmentation
    ss->setBaseImage(im);
 
    // Switch to fast but low recall Selective Search method
    ss->switchToSelectiveSearchFast();
 
    // run selective search segmentation on input image
    ss->process(rects);
    std::cout << "Total Number of Region Proposals: " << rects.size() << std::endl;
    int numRect = 100;
    rects.resize(numRect); 
}

std::vector<Rect> Detect::get_rects ()  { 
    return rects;
}

std::vector<Rect> Detect::select_rects (Mat im) { // this is paired with select search, not robust to lighting and such changes 
    std::vector<Rect> s_rects;
    // find the rects we want by color (hsv)
    for(int i = 0; i < rects.size(); i++) {
        Mat roi (im, rects[i]);
        Mat roiHSV;
        cvtColor(roi, roiHSV, COLOR_BGR2HSV); //Convert the select rect from BGR to HSV
        std::vector<Mat> channels;
        split(roiHSV, channels);
        int h = mean(channels[0])[0];
        int s = mean(channels[1])[0];
        int v = mean(channels[2])[0];
        // std::cout << h << std::endl; 
        if (h > H_low && h < H_high & s > S_low && s < S_high && v > V_low && v < V_high){
            s_rects.push_back (rects[i]);
        }
    }
    return s_rects; 
}