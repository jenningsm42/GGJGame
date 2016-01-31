#ifndef COMMAND_H
#define COMMAND_H
#include "WeaponTypes.h"

enum struct CommandType
{
    None,
    Move,
    Place
};

struct Command
{
    CommandType commandType;
	WeaponType weaponType;
    float x;
    float y;
};

#endif // COMMAND_H
