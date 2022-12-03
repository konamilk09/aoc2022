#include <iostream>
#include <vector>
#include <cassert>

int pri(char c) {
  if('a'<=c && c<='z') {
    return c - 'a' + 1;
  }
  if('A'<=c && c<='Z') {
    return c - 'A' + 27;
  }
  return -1;
}

void part1() {
  int answer = 0;
  std::string line;
  while(getline(std::cin, line)) {
    int len = line.length();
    std::vector<int> c1(53, 0); // a-zA-Z
    for(int i=0; i<len/2; i++) {
      int v = pri(line[i]);
      assert(v!=-1);
      c1[v]++;
    }
    for(int i=len/2; i<len; i++) {
      int v = pri(line[i]);
      assert(v!=-1);
      if(c1[v]>0) {
        answer += v;
        break;
      }
    }
  }
  std::cout << answer << std::endl;
}

void part2() {
  int answer = 0;
  std::string line1, line2, line3;
  while(getline(std::cin, line1)
    &&getline(std::cin, line2)
    &&getline(std::cin, line3)) {

    std::vector<int> c1(53, 0); // a-zA-Z
    std::vector<int> c2(53, 0); // a-zA-Z
    for(int i=0; i<line1.length(); i++) {
      int v = pri(line1[i]);
      assert(v!=-1);
      c1[v]++;
    }
    for(int i=0; i<line2.length(); i++) {
      int v = pri(line2[i]);
      assert(v!=-1);
      c2[v]++;
    }
    for(int i=0; i<line3.length(); i++) {
      int v = pri(line3[i]);
      assert(v!=-1);
      if(c1[v]>0 && c2[v]>0) {
        answer+=v;
        break;
      }
    }
  }
  std::cout << answer << std::endl;
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
