#ifndef FUNC_H
#define FUNC_H

static float rgb(float x) {
        x = x/255;
        float value = (int)(x * 100 + .5);
        return (float)value / 100;
}

#endif