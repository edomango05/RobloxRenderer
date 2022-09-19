#include <memory>
#include <map>
#include "utils.h"
#ifndef BASEPART_H
#define BASEPART_H

using std::byte;
typedef unsigned int uint_32;


class ImageBuffer
{
private:
    int buffer_size;
    int width;
    int height;
    int bytesPerPixel;
    std::unique_ptr<byte[]> buffer;
    std::map<uint_32,double>depth_by_pixel_offset;
public:
    ImageBuffer(uint_32 width_, uint_32 height_,uint_32 bytesPerPixel_);
    ~ImageBuffer();
    void draw_pixel(uint_32 pos_x, uint_32 pos_y, RGBA &rgba);
};

#endif