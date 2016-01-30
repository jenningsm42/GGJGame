#ifndef COMMAND_H
#define COMMAND_H
#include "Weapontypes.h"

enum struct CommandType
{
    None,
    Move,
    Place
};

struct Command
{
    CommandType commandType;
	weapontype weapontype;
    float x;
    float y;
};

#endif // COMMAND_H
