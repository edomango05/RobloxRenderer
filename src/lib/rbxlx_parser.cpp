#include <iostream>
#include <rbxlx_parser.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

Rbxlx::Rbxlx(char *path_)
{
    LIBXML_TEST_VERSION

    path = path_;

    get_tree();

    xmlCleanupParser();
    xmlMemoryDump();
    
}

Rbxlx::~Rbxlx() {}

void Rbxlx::get_tree() {
    doc = xmlReadFile(path, "utf-8", 0);

    if (!doc) { 
        std::cout << "Failed to parse" << path << std::endl;
        return;
    }

    std::cout << "Document at address: " << doc << std::endl;
    std::cout << "Content: " << doc->children->content << std::endl;

    xmlFreeDoc(doc);
}