// Created by Admin on 25.04.2021.
//
#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string, stoi
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds
#include <sstream>      // stringstream

#include "data_structure.hpp"

using namespace std;
using namespace itis;

// абсолютный путь до набора данных и папки проекта
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};
static constexpr auto kProjectPath = string_view{PROJECT_SOURCE_DIR};

int main() {
  const auto path = string(kDatasetPath);
  cout << "Path to the 'dataset/' folder: " << path << endl;

  auto input_file = ifstream(path + "/getSum//data(100).csv");
  int data[100];
  FenwickTree *fenwickTree;

  if (input_file) {
    int line_number = 0;
    for (string line; getline(input_file, line, ','); /* ... */) {
      auto ss = stringstream(line);  // оборачиваем строку в объект "поток"
      for (int i = 0; i < sizeof(data); i++) {
        data[i] = stoi(line);
      }
      line_number++;
    }
  }
  for (int i = 0; i < sizeof(data); i++) {
    fenwickTree->constructFenwick(data, sizeof(data));
  }

  const auto time_point_before = chrono::high_resolution_clock::now();
  fenwickTree->getSum(data, 4, 7);
  const auto time_point_after = chrono::high_resolution_clock::now();

  // переводим время в наносекунды
  const auto time_diff = time_point_after - time_point_before;
  const long time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();

  cout << "Time elapsed (ns): " << time_elapsed_ns << '\n';

  return 0;
}