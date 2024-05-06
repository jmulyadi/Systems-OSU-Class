//Josh Mulyadi
// structs.h
#ifndef STRUCTS_H
#define STRUCTS_H

struct Sim
{
    void *mascots;
    void *coins;
    double elapsed;
};
struct Buckeye 
{
    double x_position;
    double y_position;
    double y_velocity;
    double x_velocity;
    double jump_velocity;
    int color;
    int loot;
    struct Sim *sim;
};
struct Coin
{
    int color;
    double x_position;
    double y_position;
};

#endif // STRUCTS_H
