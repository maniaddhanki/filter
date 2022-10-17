#include "filter.h"
#include "gtest/gtest.h"
#include <vector>

using namespace std;

TEST(FilterTest,SameArrayWithVarriyingFilterSize){
  vector<float> image {1,2,3,4,5,6,7,8,9,10};

  int filter_size = 3;
  vector<float> expected_image {2,3,4,5,6,7,8,9};
  vector<float> filtered_image = filter(image,filter_size);
  EXPECT_EQ(expected_image,filtered_image);

  int filter_size1 = 2;
  vector<float> expected_image1 {1.5,2.5,3.5,4.5,5.5,6.5,7.5,8.5,9.5};
  vector<float> filtered_image1 = filter(image,filter_size1);
  EXPECT_EQ(expected_image1,filtered_image1);
}

TEST(FilterTest,DifferentArrays){
  vector<float> image {1,2,3,4,5};
  int filter_size = 3;
  vector<float> expected_image {2,3,4};
  vector<float> filtered_image = filter(image,filter_size);
  EXPECT_EQ(expected_image,filtered_image);

  vector<float> image1 {1,2,3,4,5,6,7,8};
  int filter_size1 = 2;
  vector<float> expected_image1 {1.5,2.5,3.5,4.5,5.5,6.5,7.5};
  vector<float> filtered_image1 = filter(image1,filter_size1);
  EXPECT_EQ(expected_image1,filtered_image1);
}

TEST(FilterTest, ArrayWithPointNumbers){
  vector<float> image {1.5,2.5,3.5,4.0,5.0};
  int filter_size = 2;
  vector<float> expected_image {2,3,3.75,4.5};
  vector<float> filtered_image = filter(image,filter_size);
  EXPECT_EQ(expected_image,filtered_image);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}