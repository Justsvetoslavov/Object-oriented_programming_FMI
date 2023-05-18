#include "Guest.h"

#include <cstdlib>

Guest::Guest()
        : Player(rand())
{

}

bool Guest::LevelUp()
{
    return false;
}
