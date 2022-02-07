#include "MapLoader.h"
#include <iostream>
using namespace std;

int main()
{
    string filename("solar.map");
    Map& map = MapLoader::createMap(filename);
    cout << map.validate();
} 