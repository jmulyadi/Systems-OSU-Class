//Josh Mulyadi
/* Copyright 2024 Neil Kirby */
// Not for disclosure without permission
#define BUFFER_SIZE 12
struct Sim
{
	void *mascots;
	void *coins;
	double elapsed;
	char buffer[BUFFER_SIZE];
	int buffer_count;
	int bonus;
};

struct Coin
{
	int color;
	double x_position, y_position;
};

struct Buckeye 
{
	int color, loot;
	double x_position, y_position, x_velocity, y_velocity, jump_velocity;
	struct Sim *world;
	double movement_velocity;
};
//My code below
typedef struct Node
{
	struct Node *next;
	void *data;
}Node;
typedef void (*Move)(struct Buckeye *brutus);
struct Action 
{
	int color;
	Move fp;
};