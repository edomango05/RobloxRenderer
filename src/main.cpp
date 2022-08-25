#include <iostream>
#include <rbxlx_parser.h>

int main(int argc ,char**argv)
{
    if(argc < 2){
        std::cout << "No .rbxlx file provided\n";
        return 1;
    }
    Rbxlx parsed_xml(argv[1]); 
    
    return 0;
}
