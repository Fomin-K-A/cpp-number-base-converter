#include <iostream>
#include <string>

const char* correct_simbols = "0123456789ABCDEFGHIJ";

bool Validation(std::string &N, int base_given) {
  for (char ch : N) {
    if (base_given < 11 && base_given > 1) {
      if (ch <= correct_simbols[base_given - 1]) {
        continue;
      }
    } else if (base_given > 10 && base_given < 21) {
      if (ch > '9') {
        if (ch <= correct_simbols[base_given - 1]) {
          continue;
        }
      }
      if (ch <= '9') {
        continue;
      }
    }
    std::cout << "wrong integer" << std::endl;
    return false;
  }
  return true;
}

int CharToInt(char ch) {
  if (ch <= '9') {
    return ch - '0';
  }
  return ch - 'A' + 10;
}

long long ToDec(std::string & N, int base_given) {
  long long mult = 1;
  long long result = 0;

  for (int i = N.size() - 1; i >= 0; i--) {
    result = result + CharToInt(N[i]) * mult;
    mult = mult * base_given;
  }
    
  return result;
}

std::string ToBase(long long number_dec, int base_to) {
  std::string result = "";
  while (number_dec != 0) {
    int number = number_dec % base_to;
    result += correct_simbols[number];
    number_dec = number_dec / base_to;
  }
  return result;
}

int main(int argc, char* argv[]) {
  std::string N;
  int base_given;
  int base_to;

  std::cin >> N >> base_given >> base_to;

  bool is_valid = true;


  is_valid = Validation(N, base_given);
  if (is_valid == false) {
    return 0;
  }

  long long number_dec = 0;

  number_dec = ToDec(N, base_given);

  std::string result = ToBase(number_dec, base_to);

  for (int i = result.size() - 1; i >= 0; i--) {
    std::cout << result[i];
  }
  return 0;
}