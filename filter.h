#pragma once
#include <vector>

using namespace std;

vector<float> mean_filter(vector<float>& image, int filter_size);
vector<float> median_filter(vector<float>& image, int filter_size);