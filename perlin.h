// Source code is stolen from https://gist.github.com/nowl/828013

#ifndef PERLIN_H
#define PERLIN_H

#include <stdio.h>

void set_seed(int new_seed);

void generate_new_hash();

static int noise2(int x, int y);

static float lin_inter(float x, float y, float s);

static float smooth_inter(float x, float y, float s);

static float noise2d(float x, float y);

float perlin2d(float x, float y, float freq, int depth);

#endif // PERLIN_H
