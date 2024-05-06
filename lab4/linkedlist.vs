void* allocate_node();
int any(void *head, CriteriaFunction yes, void *helper);
int deleteSome(void *p2head, CriteriaFunction mustGo, void *helper, ActionFunction disposal, int text);
void freeData(void *data);
void freeNode(void *data);
bool insert(void *p2head, void *data, ComparisonFunction goesInFrontOf, int text);
void iterate(void *head, ActionFunction doThis);
void sort(void *hptr, ComparisonFunction cf);
