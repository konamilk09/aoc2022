#include <iostream>
#include <cassert>


int to_int(char c) {
  if(c=='A') return 0;
  if(c=='B') return 1;
  if(c=='C') return 2;
  if(c=='X') return 0;
  if(c=='Y') return 1;
  if(c=='Z') return 2;
  return EXIT_FAILURE;
}

int choice_point(int me) {
  return me+1;
}

int round_point(int me, int opp) {
  int a = (me - opp + 3) % 3;
  if(a == 1) return 6;
  if(a == 2) return 0;
  assert(me == opp);
  return 3;
}

void part1() {
  std::string str;
  int opp, me;
  int score = 0;
  while(getline(std::cin, str)) {
    assert(str.length()==3);
    opp = to_int(str[0]);
    me = to_int(str[2]);
    score += choice_point(me) + round_point(me, opp);
    // std::cout << "choice" << choice_point(me) << std::endl;
    // std::cout << "round" << round_point(me, opp) << std::endl;
  }
  std::cout << "final " << score << std::endl;
}

void part2() {
  std::string str;
  int opp, me;
  int score = 0;
  while(getline(std::cin, str)) {
    assert(str.length()==3);
    opp = to_int(str[0]);
    me = to_int(str[2]);
    if(me == 0) me = (opp + 2) % 3;
    else if(me == 1) me = opp;
    else if(me == 2) me = (opp + 1) % 3;
    score += choice_point(me) + round_point(me, opp);
    // std::cout << "choice" << choice_point(me) << std::endl;
    // std::cout << "round" << round_point(me, opp) << std::endl;
  }
  std::cout << "final " << score << std::endl;
}

int main(int argc, char** argv) {
  if(argc != 2) {
    std::cerr << "usage: ./2.o n" << std::endl;
    return -1;
  }
  if(*argv[1] == '1')
    part1();
  else 
    part2();
  return 0;
}
