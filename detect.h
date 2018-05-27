#include "opencv2/ximgproc/segmentation.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
 
using namespace cv;
using namespace cv::ximgproc::segmentation;
using namespace std;

class Detect{
public:
    Mat edge_extract (Mat); // canny edge detector
    vector<vector<Point> > contour_extract (Mat); // extract contour from edges 
    vector<vector<Point> > approx_poly (vector<vector<Point> >); // approximate polygons
    vector<vector<Point> > find_postit_from_poly (vector<vector<Point> >); // find polygon from the polygons 
 };
 
Mat Detect::edge_extract (Mat im) { 
    Mat gray; // convert image to grayscale
    cvtColor(im, gray, CV_RGB2GRAY);
    Mat edges;
    Canny(gray, edges, 30,150); // canny edge detection
    // dilation 
    int dilation_size = 10; 
    Mat dst; 
    Mat di_element = getStructuringElement(MORPH_CROSS,
       Size( 2*dilation_size + 1, 2*dilation_size+1 ),
       Point( dilation_size, dilation_size ) );
    dilate( edges, dst, di_element );
    // erosion
    int erosion_size = 9;  // create strct element
    Mat element = getStructuringElement(MORPH_CROSS,
        Size(2 * erosion_size + 1, 2 * erosion_size + 1),
        Point(erosion_size, erosion_size) );
    erode(dst, edges, element); 
    return edges;
}

vector<vector<Point> > Detect::contour_extract (Mat edg) { 
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    findContours(edg, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);
    return contours;
}

vector<vector<Point> > Detect::approx_poly (vector<vector<Point> > contours) {
    // approximate polygons from a contour
    vector<vector<Point> > approx_out; 
    for( int i = 0; i< contours.size(); i++ ){
        double epsilon = 0.1*arcLength(contours[i], true);
        vector<Point> approx_poly;
        approxPolyDP(contours[i], approx_poly, epsilon, true);
        // only interested in rectangles 
        if (approx_poly.size() == 4){
            approx_out.push_back(approx_poly);
        }
    }
    return approx_out;
}

vector<vector<Point> > Detect::find_postit_from_poly (vector<vector<Point> > polys) {
    vector<vector<Point> > selected;
    for( int i = 0; i < polys.size(); i++ ){
        // check if there are other contours inside it 
        for( int j = 0; j < polys.size(); j++ ){
            if (j != i){
                if (pointPolygonTest(polys[i], polys[j][0], false) > 0){
                    selected.push_back(polys[i]);
                    break;
                }
            }
        }
    }
    return selected; 
}

