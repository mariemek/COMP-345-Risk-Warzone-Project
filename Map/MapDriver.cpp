#include "MapLoader.h"
using namespace std;

int main()
{
    string filename("solar.map");
    Map& map = MapLoader::createMap(filename);
}