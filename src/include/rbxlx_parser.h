#ifndef RBXLX_PARSER_H
#define RBXLX_PARSER_H
#include <libxml/parser.h>

class Rbxlx {
    private:
        xmlDocPtr doc;

        void get_tree();
    public:

        char * path;

        Rbxlx(char *path_);
        ~Rbxlx();
};

#endif