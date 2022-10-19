#include <iostream>
#include "filter.h"
#include <vector>
#include <chrono>

using namespace std;

namespace chrono = std::chrono;

int main()
{
  auto start = chrono::steady_clock::now();
  vector<float> image {2,5,1,7,8,3,6,4};
  int filter_size = 3;
  vector<float> filtered_image = mean_filter(image,filter_size);

  // std::cout << "Vector address in Main " << &filtered_image << "\n";
  cout << "Mean filter output put is : \n";
  for(int i = 0; i < filtered_image.size(); i++){
    cout << filtered_image[i] << "\n";
  }

  vector<float> median_filtered_image = median_filter(image,filter_size);
  cout << "Median filter output put is : \n";
  for(int i = 0; i < filtered_image.size(); i++){
    cout << median_filtered_image[i] << "\n";
  }


  auto end = chrono::steady_clock::now();
  auto time = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
  std::cout << "\n\ntime elapsed : " << time << " ns\n";
}