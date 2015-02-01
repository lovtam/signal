#pragma once
#include <opencv2/opencv.hpp>
#include<vector>
using namespace std;
using namespace cv;
class Classifier{
private:
	int nstructs;
public:
	Classifier();
	void prepare(const vector<Size>&scales);
	void trainFern(const vector<std::pair<std::vector<int>,int> >& fern_data,int resample);
	void trainNN(const vector<cv::Mat>& nn_data);
	void evaluate(const vector<pair<vector<int>,int> >& nNN,const vector<cv::Mat>& nNNT);
	void getFeatures(const cv::Mat& image,const int& scale_idx,std::vector<int>& fern);
	//fern members
	int getNumStructs(){return nstructs;}
	 struct Feature
      {
          uchar x1, y1, x2, y2;
          Feature() : x1(0), y1(0), x2(0), y2(0) {}
          Feature(int _x1, int _y1, int _x2, int _y2)
          : x1((uchar)_x1), y1((uchar)_y1), x2((uchar)_x2), y2((uchar)_y2)
          {}
          bool operator ()(const cv::Mat& patch) const
          { return patch.at<uchar>(y1,x1) > patch.at<uchar>(y2, x2); }
      };
	 std::vector<std::vector<Feature> > features;

};