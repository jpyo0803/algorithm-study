//
// Java vs C++
// Problem: https://www.acmicpc.net/problem/3613
//

#include <cstdio>
#include <cstring>

constexpr int kMaxLength = 100;

char input[kMaxLength + 1];
char output[kMaxLength * 2 + 1];  // in case of every letter is uppercase

int main() {
  scanf("%s", input);

  if (!(input[0] >= 'a' &&
        input[0] <= 'z')) {  // if first letter is not lowercase
    printf("Error!\n");
    return 0;
  }

  bool is_java{false}, is_cpp{false};
  const int length = strlen(input);

  if (!((input[length - 1] >= 'a' && input[length - 1] <= 'z') ||
        (input[length - 1] >= 'A' && input[length - 1] <= 'Z'))) {
    printf("Error!\n");
    return 0;
  }

  for (int i = 1; i < length; i++) {  // no need to check first letter
    if (input[i] == '_') {
      is_cpp = true;
    }
    if (input[i] >= 'A' && input[i] <= 'Z') {
      is_java = true;
    }
    if (is_cpp && is_java) {  // can't be both cpp and java
      printf("Error!\n");
      return 0;
    }
  }

  if (is_cpp) {
    bool was_underscore = false;
    int idx = 0;
    for (int i = 0; i < length; i++) {
      if (input[i] == '_') {
        if (was_underscore) {
          printf("Error!\n");
          return 0;
        }
        was_underscore = true;
      } else {
        if (was_underscore) {
          output[idx++] = input[i] - 32;
        } else {
          output[idx++] = input[i];
        }
        was_underscore = false;
      }
    }
  } else if (is_java) {
    int idx = 0;
    for (int i = 0; i < length; i++) {
      if (input[i] >= 'A' && input[i] <= 'Z') {
        output[idx++] = '_';
        output[idx++] = input[i] + 32;
      } else {
        output[idx++] = input[i];
      }
    }
  } else {
    strcpy(output, input);  // if neither, it is only case when only one word
  }

  printf("%s\n", output);
  return 0;
}
