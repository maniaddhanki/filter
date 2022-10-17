#include <iostream>
#include "filter.h"
#include <vector>

using namespace std;

int main()
{
  vector<float> image {1,2,3,4,5,6,7,8,9,10};
  int image_size;
  cin >> image_size;
  vector<float> filtered_image = filter(image,image_size);

  cout << "out put is : \n";
  for(int i = 0; i < filtered_image.size(); i++){
    cout << filtered_image[i] << "\n";
  }
}