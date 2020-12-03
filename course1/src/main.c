#include "platform.h"
#include "course1.h"

#define MAX_LENGTH (10)
char buffer[MAX_LENGTH];

/* A pretty boring main file */
int main(void) {
#if defined COURSE1
  course1();
#endif
  return 0;
}

