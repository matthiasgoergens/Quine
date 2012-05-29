/* Intron
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* q = "/* Intron\n */\n#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n\nchar* q = \"%s\";\n\nchar* repr (char* s) {\n  char* r = (char*) malloc ((2*strlen(s)+1)*sizeof(char));;\n  int i = 0;  int j = 0;\n  for (; (r[j] = s[i++]);)\n    switch (r[j]) {\n    case '\\\\': r[j++] = '\\\\'; r[j++] = '\\\\'; break;\n    case '\\n': r[j++] = '\\\\'; r[j++] = 'n'; break;\n    case '\"':  r[j++] = '\\\\'; r[j++] = '\"'; break;\n    default: j++; break;\n    }\n  return r;\n}\n\nint main(int argc, char** args) {\n  printf (q, repr(q));\n  return 0;\n}\n";

char* repr (char* s) {
  char* r = (char*) malloc ((2*strlen(s)+1)*sizeof(char));;
  int i = 0;  int j = 0;
  for (; (r[j] = s[i++]);)
    switch (r[j]) {
    case '\\': r[j++] = '\\'; r[j++] = '\\'; break;
    case '\n': r[j++] = '\\'; r[j++] = 'n'; break;
    case '"':  r[j++] = '\\'; r[j++] = '"'; break;
    default: j++; break;
    }
  return r;
}

int main(int argc, char** args) {
  printf (q, repr(q));
  return 0;
}
