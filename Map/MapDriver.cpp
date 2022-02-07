#include "MapLoader.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    string filename("solar.map");
    Map& map = MapLoader::createMap(filename);
    cout << map.validate();
} 