#include"queue.h"
Queue::Queue(uint16_t _capacity):
capacity(_capacity)
{
  arr = new datatype[capacity];
  front = rear = 0;
  size = 0;
}
Queue::~Queue() {
  delete[] arr;
}
void Queue::enqueue(datatype element) {
    if (isFull()) {
        throw "Error Enqueue: Queue is full. Cannot enqueue element.";
    }
    arr[rear] = element;
    rear = (rear + 1) % capacity;
    size=(capacity-front+rear)%capacity;
}
datatype Queue::peek() {
    if (isEmpty()) {
        throw "Error dequeue: Queue is empty. Cannot dequeue element." ;
    }
    return arr[front];
}

datatype Queue::dequeue() {
    if (isEmpty()) {
        throw "Error dequeue: Queue is empty. Cannot dequeue element." ;
    }
    int element = arr[front];
    front = (front + 1) % capacity;
    size=(capacity-front+rear)%capacity;
    return element;
}
bool Queue::isEmpty() {
    return front==rear;
}
bool Queue::isFull() {
    return front==(rear+1)%capacity;
}
uint16_t Queue::getSize() {
    return size;
}
