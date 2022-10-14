#include "filter.h"
#include "gtest/gtest.h"

TEST(FilterTest,AnArray){
  int image_size = 10;
  int *image =new int[image_size]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int filter_size = 3;

  int *expected_image = new int[8]{2,3,4,5,6,7,8,9};
  int *filtered_image = filter(image,image_size,filter_size);
  for(int i = 0; i < 8; i++){
    EXPECT_EQ(expected_image[i],filtered_image[i]);
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}