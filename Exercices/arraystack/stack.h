#include <stdint.h>

typedef int datatype;
class Arraystack
{

public:
    Arraystack(int _capacity = 100); // cahnge type later
    Arraystack(const Arraystack &);
    ~Arraystack();
    datatype pop();
    datatype peek();
    bool isEmpty();
    bool isFull();
    uint32_t getcapacity() const
    {
        return capacity;
    };

private:
    const uint32_t capacity;
    int top;
    datatype *values;
};
