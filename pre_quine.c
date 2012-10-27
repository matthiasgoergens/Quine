/* This program will print its own source when run.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* q = "%s";

char* escape (char* input) {
  char translateFrom[] = "\a\b\f\n\r\t\v\\\"\'";
  char translateTo[] = "abfnrtv\\\"\'";

  /* In the worst case, we will have to escape every character, so at
     most the size of the string doubles.  +1 for trailing \0.
  */
  char* output = (char*) calloc ((2*strlen(input)+1), sizeof(char));
  char* outputStart = output;

  for (;*input; input++) {
    char* pos;
    if (NULL != (pos = strchr(translateFrom, *input))) {
      *output++ = '\\';
      *output++ = translateTo[pos-translateFrom];
    }
    else
      *output++ = *input;
  }
  return outputStart;
}

int main() {
  printf (q, escape(q));
  return 0;
}
