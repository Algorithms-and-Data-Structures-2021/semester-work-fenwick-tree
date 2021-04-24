#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string, stoi
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds
#include <sstream>

// подключаем вашу структуру данных
#include "data_structure.hpp"

using namespace std;
using namespace itis;

// абсолютный путь до набора данных и папки проекта
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};
vector<int> split(const string& s, char delimiter) {
  vector<int> tokens;
  string token;
  istringstream tokenStream(s);
  while (getline(tokenStream, token, delimiter)) {
    tokens.push_back(stoi(token));
  }
  return tokens;
}

int main() {
  const auto path = string(kDatasetPath);
  cout << "Path to the 'dataset/' folder: " << path << endl;

  int trials = 1;
  string files[1] = {"01"};
  FenwickTree* fenwickTree;
  vector<int> ourTree;
  for(string elem : files) {
    for (int i = 0; i < trials; i++) {
      string line = "1";
      auto input_file = ifstream(path + "/find/data(100).txt");

      if (input_file) {
        while (line != "") {
          getline(input_file, line);
          if (line == "") {
            break;
          }
          // fenwickTree->PreProc(stoi(line));
          vector<int> intValues = split(line, ' ');
          ourTree = fenwickTree->PreProc(intValues);
        }

        const auto time_point_before = chrono::steady_clock::now();  //find, remove, splay, split
        fenwickTree->getSumFromZero(ourTree, 5);
        const auto time_point_after = chrono::steady_clock::now();
        input_file.close();
        const auto time_diff = time_point_after - time_point_before;
        const long time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();
        cout << time_elapsed_ns<<"sjdhvbhev" << endl;

      }
    }
  }
  return 0;
}
