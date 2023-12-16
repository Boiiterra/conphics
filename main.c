#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "perlin.h"

void populate(char *to_fill, size_t amm) {}

int main(int argc, char *argv[]) {
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  size_t width = w.ws_col;
  size_t height = w.ws_row - 1;

  char screen[width * height];

  char *color = "\x1b[1m";
  char *reset = "\x1b[0m";

  char *shades = " .-+o";
  int x, y;

  set_seed(25);
  // generate_new_hash();
  for (y = 0; y < height; y++) {
    for (x = 0; x < width; x++)
      printf("%s%c%s", color, shades[(int)(5 * perlin2d(x, y, 0.0867, 4))],
             reset);
    printf("\n");
  }
  return 0;
}
