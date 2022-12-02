#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char** argv) {
  if(argc != 2) {
    std::cerr << "usage: " << argv[0] << " n" << std::endl;
    return -1;
  }

  std::string str; 
  int calories = 0;
  std::vector<int> elves;
  while(getline(std::cin, str)){
    if(str=="") {
      elves.push_back(calories);
      calories = 0;
    }
    else {
      calories += stoi(str);
    }
  }
  std::sort(elves.begin(), elves.end(), [](int a, int b){ return a > b; });
  int answer = 0;
  
  if(*argv[1] == '1') {
    std::cout << elves[0] << std::endl;
  }
  else {
    for(int i=0; i<3; i++) {
      answer += elves[i];
    }
    std::cout << answer << std::endl;
  }
  return 0;
}
