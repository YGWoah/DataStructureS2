#include"queue.h"
#include"student.h"
int main(){
  CircularQueue<Student> q(10);// queue can't exceed 4 items
  try{
  q.display();
  //cout<<q.dequeue()<<endl;
  q.enqueue(Student(1,"Mohammed","Qbadou","m.qbadou@exemple.com"));
  q.enqueue(Student(2,"Sarah","Alaoui","s.alaoui@exemple.com"));
  q.enqueue(Student(3,"Abderrahmane","hamoudi","ab.hmoudi@exemple.com"));
  q.enqueue(Student(1,"Ayoub","Ibrahimi","ay.ibrahimi@exemple.com"));
  q.display();
  }catch(string ex){
    cout<<ex<<endl;
  }
  return 0;
}
    