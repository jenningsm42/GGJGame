#ifndef COMMAND_H
#define COMMAND_H

enum struct CommandType
{
    None,
    Move,
    Place
};

struct Command
{
    CommandType commandType;
    float x;
    float y;
};

#endif // COMMAND_H
