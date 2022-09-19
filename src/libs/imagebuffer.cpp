#include "../includes/imagebuffer.h"

ImageBuffer::ImageBuffer(uint_32 width_, uint_32 height_, uint_32 bytesPerPixel_)
{
    width = width_;
    height = height_;
    bytesPerPixel = bytesPerPixel_;
    
    buffer_size = width_ * height_ * bytesPerPixel_;
    buffer = std::make_unique<byte[]>(bytesPerPixel * width * height);
}

void ImageBuffer::draw_pixel(uint_32 pos_x, uint_32 pos_y, RGBA &rgba)
{
    int pixelOffset = bytesPerPixel * pos_y * width + pos_x;
    buffer[pixelOffset + 0] = rgba.r;
    buffer[pixelOffset + 1] = rgba.g;
    buffer[pixelOffset + 2] = rgba.b;
    buffer[pixelOffset + 3] = rgba.a;
    depth_by_pixel_offset[pixelOffset,rgba.depth];
}

