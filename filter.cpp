#include <iostream>
#include "filter.h"

int *filter(int *image, int image_size, int filter_size)
{
  int filtered_image_size = image_size - (filter_size - 1);
  int *filtered_image = new int [filtered_image_size];

  for (size_t i = 0; i < filtered_image_size; i++)
  {
    int sum = 0;
    for (size_t j = 0; j < filter_size; j++)
    {
      sum += image[i + j];
    }
    filtered_image[i] = sum / filter_size;
  }
  return filtered_image;
}