#include <iostream>
#include <vector>
#include <cassert>
#include <functional>

bool check(int b1, int e1, int b2, int e2) {
  if(b1<=b2 && e2<=e1) return true;
  if(b2<=b1 && e1<=e2) return true;
  return false;
}

bool check2(int b1, int e1, int b2, int e2) {
  if(b1<=b2 && e2<=e1) return true;
  if(b2<=b1 && e1<=e2) return true;
  if(e1>=b2 && b1<=e2) return true;
  if(b1<=e2 && e1>=b2) return true;
  return false;
}

void score(std::function<bool(int,int,int,int)> cal) {
  int answer = 0;
  std::string line;
  while(getline(std::cin, line)) {

    std::string first, second;
    int start = 0, del = line.find(","), end = line.size();
    first = line.substr(start, del-start);
    second = line.substr(del+1, end-del-1);

    int b1, e1, b2, e2;
    del = first.find("-");
    end = first.size();
    b1 = stoi(first.substr(start,del-start));
    e1 = stoi(first.substr(del+1, end-del-1));
    
    del = second.find("-");
    end = second.size();
    b2 = stoi(second.substr(start,del-start));
    e2 = stoi(second.substr(del+1, end-del-1));

    //std::cout << b1 << "," << e1 << "," << b2 << "," << e2 << std::endl;

    if(cal(b1, e1, b2, e2)) answer++;
  }
  std::cout << answer << std::endl;
}

void part1() {
  score(check);
}

void part2() {
  score(check2);
}

int main(int argc, char** argv) {
  if(argc!=2) {
    printf("usage: %s n\n", argv[0]);
    return EXIT_FAILURE;
  }
  if(*argv[1]=='1')
    part1();
  else 
    part2();
  return 0;
}
