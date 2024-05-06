/* Josh Mulyadi */

bool close_enough( double x1, double y1, double x2, double y2);
bool is_left_of_flag(void *data, void *helper);
void jump(struct Buckeye *brutus);
void left(struct Buckeye *brutus);
void move_everyone(struct Sim *world);
void react_to_input(double oldX, double oldY, struct Buckeye *brutus);
void right(struct Buckeye *brutus);
void stop(struct Buckeye *brutus);
void take_action(double oldX, double oldY, struct Buckeye *brutus);
