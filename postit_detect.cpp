#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "detect.h"

using namespace cv;
using namespace std;
 
static void help() {
    std::cout << std::endl <<
    "Usage:" << std::endl <<
    "./ssearch input_image (f|q)" << std::endl <<
    "f=fast, q=quality" << std::endl <<
    "Use l to display less rects, m to display more rects, q to quit" << std::endl;
}
 
// RNG rng(12345); 

int main( int argc, char** argv ){

    VideoCapture cap(0); //capture the video from web cam

    if ( !cap.isOpened() )  // if not success, exit program
    {
         cout << "Cannot open the web cam" << endl;
         return -1;
    }

    while (true){
        Mat im;

        bool bSuccess = cap.read(im); // read a new frame from video

        if (!bSuccess){ //if not success, break loop{
             cout << "Cannot read a frame from video stream" << endl;
             break;
        }

        std::vector<Rect> rects;

        Detect det; 
        Mat e = det.edge_extract(im); // extract edges 
        std::vector<std::vector<Point> > c = det.contour_extract(e); // extract contour 
        std::vector<std::vector<Point> > p = det.approx_poly(c); // approximate polygon 
        
        std::vector<std::vector<Point> > r = det.find_postit_from_poly(p);
        
        // Mat imOut = Mat::zeros( e.size(), CV_8UC3 );
        Mat imOut = im.clone();
        for( int i = 0; i< r.size(); i++ ){
            // Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
            drawContours( imOut, r, i, (0, 255, 0), 2, 8 );
        }

        // show output
        imshow("Output", imOut);

        if (waitKey(30) == 27) { //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
            cout << "quit" << endl;
            break; 
        }
    }

    return 0;
}


// sample working code 
// int main(int argc, char** argv) {
//     // If image path and f/q is not passed as command
//     // line arguments, quit and display help message
//     if (argc < 2) {
//         help();
//         return -1;
//     }
 
//     // read image
//     Mat im = imread(argv[1]);
//     std::vector<Rect> rects;

//     Detect det (102, 112, 50, 100, 200, 300); 
//     det.select_search(im); 
//     // rects = det.get_rects();
//     rects = det.select_rects(im);
//     std::cout << rects.size() << std::endl; 
    
//     // create a copy of original image
//     Mat imOut = im.clone();

//     int numShowRects = 100; 
//     // itereate over all the region proposals
//     for(int i = 0; i < rects.size(); i++) {
//         if (i < numShowRects) {
//             rectangle(imOut, rects[i], Scalar(0, 255, 0));
//         }
//         else {
//             break;
//         }
//     }

//     // show output
//     imshow("Output", imOut);
//     waitKey(0);
//     return 0;
// }