#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

template<class T> class ArrayList{
 private:
  T* array;
  int size;
  int capacity;

 public:
  ArrayList(){//constructor
    array = new T[10];
    size = 0;
    capacity = 10;
  }

  virtual ~ArrayList(){//destructor
    delete[] array;
  }

  void add(T element){
    if(size == capacity){
      capacity*=2;
      T* temp = new T[capacity*2];
      for(int i=0;i<size;i++)
	temp[i] = array[i];

      delete[] array;//frees dynamically allocated memory in the array
      array=temp;
    }

    array[size] = element;
    size++;
  }

  int get(int index){
    return array[index];
  }

  T remove(int index){
    T temp = array[index];
    for(int i=index;i<size-1;i++)
      array[i] = array[i+1];
    size--;
    return temp;
  }

  int getSize(){
    return size;
  }
  
};
#endif
