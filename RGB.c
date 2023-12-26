#include <math.h>
#include <raylib.h>
#include <stdbool.h>

#define FPS 60
#define SEC (1.0 / (double)FPS)
#define WIDTH 800
#define HEIGHT 600

double absv(double n) { return (n < 0.0) ? -n : n; }

double easeSinCos(double t) {
    return absv(sin(3.0 * t * PI * 0.5)) * absv(cos(2 * t * PI));
}

double easeSinCosL(double t) { return (0.5 + 0.5 * easeSinCos(t)) * t; }

double easeInQuartSin(double t) {
    return t * t * t * t * absv(sin(4 * t * PI) + 1);
}

typedef int second;

int main() {
    int framesCounter = 0;
    Color bg = BLACK;
    second duration = 5;

    double rt = 0.0, gt = 0.0, bt = 0.0;
    bool r = false, g = false, b = false;

    InitWindow(WIDTH, HEIGHT, "image_RGBier");
    HideCursor();
    SetTargetFPS(FPS);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground((Color){255 * easeSinCosL(rt), 255 * easeSinCos(gt),
                255 * easeInQuartSin(bt), 255});

        if (IsKeyPressed(KEY_R))
            r = !r;
        if (IsKeyPressed(KEY_G))
            g = !g;
        if (IsKeyPressed(KEY_B))
            b = !b;

        if (r && rt <= 1.0)
            rt += SEC / duration;
        if (g && gt <= 1.0)
            gt += SEC / duration;
        if (b && bt <= 1.0)
            bt += SEC / duration;

        if (!r && rt >= 0.0)
            rt -= SEC / duration;
        if (!g && gt >= 0.0)
            gt -= SEC / duration;
        if (!b && bt >= 0.0)
            bt -= SEC / duration;

        if (!r && rt <= 0.0)
            rt = 0.0;
        if (!g && gt <= 0.0)
            gt = 0.0;
        if (!b && bt <= 0.0)
            bt = 0.0;

        if (r && rt >= 1.0)
            rt = 1.0;
        if (g && gt >= 1.0)
            gt = 1.0;
        if (b && bt >= 1.0)
            bt = 1.0;

        EndDrawing();
    }

    CloseWindow();
}
