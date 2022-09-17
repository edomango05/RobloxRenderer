#include "pugixml.hpp"
#ifndef GAME_H
#define GAME_H

using pugi::xml_node;

class Game
{
private:
    char *path;
    xml_node workspace_node;
    bool is_Empty(xml_node node);
    void get_Descendants(xml_node node);
    void set_instance(xml_node node);
public:
    int * instances_arr;
    Game(char *path_);
};

#endif