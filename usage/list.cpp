#include "../library/list.h"

int main(int argc, char const *argv[])
{
    List<string> *li = new List<string>();
    li->push("hello");
    li->pop();
    li->push("hello word");
    li->remove("hello world");
    li->push("Hi");
    li->push("How");
    li->push("Are");
    cout << std::boolalpha << li->is_empty() << std::endl;
    cout << "Index of Hi is : " << li->index_of("Hi") << std::endl;
    cout << "size of list is :" << li->size() << std::endl;
    li->print_values();
    return 0;
}
