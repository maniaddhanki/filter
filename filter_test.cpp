#include "filter.h"
#include "gtest/gtest.h"
#include <vector>
#include <iostream>

using namespace std;

TEST(MeanFilterTest,SameArrayWithVarriyingFilterSize){
  vector<float> image {1,2,3,4,5,6,7,8,9,10};

  int filter_size = 3;
  vector<float> expected_image {2,3,4,5,6,7,8,9};
  vector<float> filtered_image = mean_filter(image,filter_size);
  EXPECT_EQ(expected_image,filtered_image);

  int filter_size1 = 2;
  vector<float> expected_image1 {1.5,2.5,3.5,4.5,5.5,6.5,7.5,8.5,9.5};
  vector<float> filtered_image1 = mean_filter(image,filter_size1);
  EXPECT_EQ(expected_image1,filtered_image1);
}

TEST(MeanFilterTest,DifferentArrays){
  vector<float> image {1,2,3,4,5};
  int filter_size = 3;
  vector<float> expected_image {2,3,4};
  vector<float> filtered_image = mean_filter(image,filter_size);
  EXPECT_EQ(expected_image,filtered_image);

  vector<float> image1 {1,2,3,4,5,6,7,8};
  int filter_size1 = 2;
  vector<float> expected_image1 {1.5,2.5,3.5,4.5,5.5,6.5,7.5};
  vector<float> filtered_image1 = mean_filter(image1,filter_size1);
  EXPECT_EQ(expected_image1,filtered_image1);
}

TEST(MeanFilterTest, ArrayWithPointNumbers){
  vector<float> image {1.5,2.5,3.5,4.0,5.0};
  int filter_size = 2;
  vector<float> expected_image {2,3,3.75,4.5};
  vector<float> filtered_image = mean_filter(image,filter_size);
  EXPECT_EQ(expected_image,filtered_image);
}

TEST(MedianFilterTest,SameArrayWithVarriyingFilterSize){
  vector<float> image {1,2,3,4,5,6,7,8,9,10};

  int filter_size = 3;
  vector<float> expected_image {2,3,4,5,6,7,8,9};
  vector<float> filtered_image = median_filter(image,filter_size);
  EXPECT_EQ(expected_image,filtered_image);

  int filter_size1 = 2;
  vector<float> expected_image1 {1.5,2.5,3.5,4.5,5.5,6.5,7.5,8.5,9.5};
  vector<float> filtered_image1 = median_filter(image,filter_size1);
  EXPECT_EQ(expected_image1,filtered_image1);
}

TEST(MedianFilterTest,UnorderedImages){
  vector<float> image {1,5,4,3,2,4};
  int filter_size = 3;
  vector<float> expected_image {4,4,3,3};
  vector<float> filtered_image = median_filter(image,filter_size);
  EXPECT_EQ(expected_image,filtered_image);

  vector<float> image1 {2,1,3,7,6,5,4,9,8};
  int filter_size1 = 2;
  vector<float> expected_image1 {1.5,2,5,6.5,5.5,4.5,6.5,8.5};
  vector<float> filtered_image1 = median_filter(image1,filter_size1);
  EXPECT_EQ(expected_image1,filtered_image1);
}


TEST(MedianFilterTest, ArrayWithPointNumbers){
  vector<float> image {1.5,2.5,3.5,4.0,5.0};
  int filter_size = 3;
  vector<float> expected_image {2.5,3.5,4.0};
  vector<float> filtered_image = median_filter(image,filter_size);
  EXPECT_EQ(expected_image,filtered_image);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}