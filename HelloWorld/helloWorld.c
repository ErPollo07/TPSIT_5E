#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
  char s[5] = "";
  int n = 0;

  for (int i = 0; i < strlen(argv[1]); i++) {
    for (int j = 97; j <= 122; j++) {
      s[n] = j;
      
      printf("%s\n", s);

      if (argv[1][i] == j) {
        n++;
        break;
      }
    }
  }

  printf("\n");
  return 0;
}