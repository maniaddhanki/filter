#include <iostream>
#include "filter.h"


int main()
{
  int image_size = 10;
  int *image =new int[image_size]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int filter_size = 3;

  int *filtered_image = filter(image, image_size, filter_size);
  for (size_t i = 0; i < 8; i++)
  {
    std::cout << *(filtered_image + i) << "\n";
  }
  delete[] filtered_image;
}