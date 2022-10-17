#include <iostream>
#include "filter.h"
#include <vector>

using namespace std;

vector<float> filter(vector<float>& image, int filter_size){
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
  return filtered_image;
}