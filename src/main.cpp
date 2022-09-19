#include <iostream>
#include <memory> 

#include "includes/game.h"
#include "includes/utils.h"
#include "includes/imagebuffer.h"
using std::cout;
using std::endl;

int main(int argc, char **argv)
{
    cout << "Starting..." << endl;
    cout << "Choose image resolution with this format AAAAxBBBB ( for example 1920x1080 )" << endl;
    std::string resolution;
    std::cin >> resolution;
    
    std::size_t delimiter = resolution.find("x");
    int width = std::stoi(resolution.substr(0, delimiter));
    int height = std::stoi(resolution.substr(0, delimiter));
    cout << "Selected image resolution:\n ~ Width: " << width << "\n ~ Height: " << height << endl;
    // ImageBuffer buffer(10, 10, 3);
    // RGBA red(255,0,0,1,1.092);
    // buffer.draw_pixel(1,1,red);
    // buffer.draw_pixel(1,2,red);
    // buffer.draw_pixel(1,3,red);
    if (argc < 2)
    {
        cout << "You need to provide a valid rbxlx file path" << endl;
        return 1;
    }

    cout << "creating game object..." << endl;
    
    Game game_obj(argv[1]);

    return 0;
}