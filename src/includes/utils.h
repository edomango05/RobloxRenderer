#include <memory>
#include <algorithm>
#ifndef __UTILS__H
#define __UTILS__H

using std::byte;

struct RGBA
{
    byte r;
    byte g;
    byte b;
    byte a;
    double depth;
    RGBA(int r_, int g_, int b_, int a_, double depth_)
    {
        byte r{r_};
        byte g{g_};
        byte b{b_};
        byte a{a_};
        depth = depth_;
    };
};

#endif