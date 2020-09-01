//
// Document Search
// Link: https://www.acmicpc.net/problem/1543
//

#include <cstdio>
#include <cstring>

using namespace std;

char document[2510];
char word[60];

int len_document, len_word;

int main() {
  scanf("%[^\n]\n", document);
  scanf("%[^\n]\n", word);
  len_document = strlen(document);
  len_word = strlen(word);

  int idx = 0;
  int match_count = 0;
  while (idx + len_word - 1 < len_document) {
    bool is_match = true;
    for (int i = 0; i < len_word && is_match; i++) {
      if (document[idx + i] != word[i]) is_match = false;
    }
    if (is_match) {
      match_count++;
      idx += len_word;
    }
    else idx++;
  }
  printf("%d\n", match_count);

  return 0;
}
