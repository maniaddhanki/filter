#include <iostream>

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