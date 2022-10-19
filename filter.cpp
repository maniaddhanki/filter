#include <iostream>
#include "filter.h"
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<float> mean_filter(vector<float>& image, int filter_size){
  int filtered_image_size = image.size() - (filter_size - 1);
  vector<float> filtered_image{};

  for(size_t i = 0; i < filtered_image_size ; i++){
    float sum = 0;

    for(size_t j = 0; j < filter_size ; j++){
      sum += image[i + j];
    }

    float aggrigate = (sum * 1.0) / filter_size;
    filtered_image.push_back(aggrigate);
  }
  // std::cout << "Vector address in filter function  "<< &filtered_image << "\n";
  return filtered_image;
}

float calculate_median(vector<float> &range){
  sort(range.begin(),range.end());
  int center_position = range.size() /  2;
  float median = range[center_position];

  if(range.size() % 2 == 0){
    float sum = range[center_position] + range[center_position - 1];
    median = sum / 2;
  }

  return median;
}

vector<float> median_filter(vector<float>& image, int filter_size){
  int filtered_image_size = image.size() - (filter_size - 1);
  vector<float> filtered_image{};

  for(size_t i = 0; i < filtered_image_size ; i++){
    vector<float> window {};

    for(size_t j = 0; j < filter_size ; j++){
      window.push_back(image[i + j]);
    }
    float aggrigate = calculate_median(window);
    filtered_image.push_back(aggrigate);
  }
  return filtered_image;
}