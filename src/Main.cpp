#include "headers/SpaceInvaders.h"

int main()
{
    space::SpaceInvaders spaceInvaders;

    spaceInvaders.init();
    spaceInvaders.run();
    spaceInvaders.shutdown();
}
