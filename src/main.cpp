#include <iostream>
#include "headers/game.h"

using std::cout;
using std::endl;

int main(int argc, char **argv){
    if (argc < 2) {
        cout << "You need to provide a valid rbxlx file path" << endl;
        return 1;
    }
    Game game_obj(argv[1]);
    return 0;
}