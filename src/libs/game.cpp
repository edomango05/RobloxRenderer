#include "../headers/game.h"
#include <iostream>
#include "pugixml.hpp"

using pugi::xml_node;
using std::cout;
using std::endl;

bool Game::is_Empty(xml_node node)
{
    return node.children("Item").empty();
}

void Game::get_Descendants(xml_node node)
{
    for (xml_node item : node.children("Item"))
    {
        const pugi::char_t *item_class = item.attribute("class").value();

        if (item_class == "Part")
        {
            
        }
        if (is_Empty(node))
            continue;
        get_Descendants(item);
    }
}

Game::Game(char *path_)
{
    path = path_;
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(path_, 116U);
    if (!result)
    {
        cout << "No result found for " << path_ << endl;
        return;
    };
    workspace_node = doc.child("roblox").find_child_by_attribute("class", "Workspace");
    if (!workspace_node)
    {
        cout << "No workspace node found for " << path_ << " ..." << endl;
        return;
    }
    cout << "Workspace referent: " << workspace_node.attribute("referent").value() << endl;
    get_Descendants(workspace_node);
}
