/* This program will print its own source when run.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* q = "/* This program will print its own source when run.\n */\n#include <stdio.h>\n#include <string.h>\n#include <stdlib.h>\n\nchar* q = \"%s\";\n\nchar* escape (char* input) {\n  char translateFrom[] = \"\\a\\b\\f\\n\\r\\t\\v\\\\\\\"\\\'\";\n  char translateTo[] = \"abfnrtv\\\\\\\"\\\'\";\n\n  /* In the worst case, we will have to escape every character, so at\n     most the size of the string doubles.  +1 for tailing \\0.\n  */\n  char* output = (char*) calloc ((2*strlen(input)+1), sizeof(char));\n  char* outputStart = output;\n\n  for (;*input; input++) {\n    char* pos;\n    if (NULL != (pos = strchr(translateFrom, *input))) {\n      *output++ = \'\\\\\';\n      *output++ = translateTo[pos-translateFrom];\n    }\n    else\n      *output++ = *input;\n  }\n  return outputStart;\n}\n\nint main() {\n  printf (q, escape(q));\n  return 0;\n}\n";

char* escape (char* input) {
  char translateFrom[] = "\a\b\f\n\r\t\v\\\"\'";
  char translateTo[] = "abfnrtv\\\"\'";

  /* In the worst case, we will have to escape every character, so at
     most the size of the string doubles.  +1 for tailing \0.
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
