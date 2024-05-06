/* Josh Mulyadi */

void cleanUp(FILE *file_pointer, int tokens);
void closeFile(FILE *file_pointer);
FILE *fileOpen(char* fileName);
bool good_input(struct Sim *world, char *argv[]);
bool valid_input(unsigned short code);
