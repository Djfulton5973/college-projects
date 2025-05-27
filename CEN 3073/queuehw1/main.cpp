#include <iostream>
#include "ClassMaterial/DynamicQueue.cpp"

int main()
{
    // test DynamicQueue
    DynamicQueue queue = DynamicQueue(4);

    std::cout << "Test Case 1:" << std::endl;

    std::cout << "Read key " << 'a' << ".";
    std::cout << " Inserting ";
    queue.dynamicInsert('a');

    std::cout << "Read key " << 'b' << ".";
    std::cout << " Inserting ";
    queue.dynamicInsert('b');

    std::cout << "Read key " << 'w' << ".";
    std::cout << " Inserting ";
    queue.dynamicInsert('w');

    std::cout << "Read key " << 'b' << ".";
    std::cout << " Key already in queue, moving ";
    queue.dynamicInsert('b');

    std::cout << "Read key " << 'z' << ".";
    std::cout << " Inserting ";
    queue.dynamicInsert('z');

    std::cout << "Read key " << 'e' << ".";
    std::cout << " Queue is full, removing front. Inserting ";
    queue.dynamicInsert('e');

    queue.remove();
    queue.remove();
    queue.remove();
    queue.remove();

    std::cout << "\nTest Case 2:" << std::endl;

    std::cout << "Read key " << 'b' << ".";
    std::cout << " Inserting ";
    queue.dynamicInsert('b');

    std::cout << "Read key " << 'c' << ".";
    std::cout << " Inserting ";
    queue.dynamicInsert('c');

    std::cout << "Read key " << 't' << ".";
    std::cout << " Inserting ";
    queue.dynamicInsert('t');

    std::cout << "Read key " << 's' << ".";
    std::cout << " Inserting ";
    queue.dynamicInsert('s');

    std::cout << "Read key " << 'a' << ".";
    std::cout << " Queue is full, removing front. Inserting ";
    queue.dynamicInsert('a');

    std::cout << "Read key " << 'c' << ".";
    std::cout << " Key already in queue, moving ";
    queue.dynamicInsert('c');

    std::cout << "Read key " << 'c' << ".";
    queue.dynamicInsert('c');

    std::cout << "Read key " << 's' << ".";
    std::cout << " Moving ";
    queue.dynamicInsert('s');
}