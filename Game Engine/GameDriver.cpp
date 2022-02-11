#include <iostream>
#include "GameEngine.cpp"
using namespace std;

int main()
{

   GameEngine *g;
   g->start();
   delete g;
}
