#pragma once

template <class T>
class TStack
{
protected:
  T* pMem;
  size_t size;
  size_t start;
public:
  TStack(size_t sz);
  TStack(const TStack<T>& st);
  TStack(TStack<T>&& st);
  ~TStack();

  size_t GetSize();
  size_t GetStart();
  bool IsFull();
  bool IsEmpty();

  void Push(T elem);
  T Pop();
  TStack<T> operator=(const TStack<T>& st);
  TStack<T> operator=(TStack<T>&& st);
};

template<class T>
inline TStack<T>::TStack(size_t sz = 1)
{
  if (sz == 0)
    throw "size is lower or equals 0";
  size = sz;
  start = 0;
  pMem = new T[size];
  for (size_t i = 0; i < size; i++)
    pMem[i] = {};
}

template<class T>
inline TStack<T>::TStack(const TStack<T>& st)
{
  if (st.pMem == nullptr)
    throw "st is empty";
  size = st.size;
  start = st.start;
  pMem = new T[size];
  for (size_t i = 0; i < size; i++)
    pMem[i] = st.pMem[i];
}

template<class T>
inline TStack<T>::TStack(TStack<T>&& st)
{
  size = st.size;
  start = st.start;
  pMem = st.pMem;

  st.size = 0;
  st.start = 0;
  st.pMem = nullptr;
}

template<class T>
inline TStack<T>::~TStack()
{
  if (pMem != nullptr)
  {
    delete[] pMem;
    pMem = nullptr;
  }
}

template<class T>
inline size_t TStack<T>::GetSize()
{
  return size;
}

template<class T>
inline size_t TStack<T>::GetStart()
{
  return start;
}

template<class T>
inline bool TStack<T>::IsFull()
{
  if (size == start)
    return true;
  else
    return false;
}

template<class T>
inline bool TStack<T>::IsEmpty()
{
  if (size == start)
    return false;
  else
    return true;
}

template<class T>
inline void TStack<T>::Push(T elem)
{
  if (!IsFull())
  {
    pMem[start] = elem;
    start++;
  }
  else
  {
    TStack<T> newStack(size * 2);
    for (size_t i = 0; i < start; i++)
      newStack.pMem[i] = pMem[i];
    newStack.pMem[start] = elem;
    newStack.start = start + 1;
    *this = newStack;
  }
}

template<class T>
inline T TStack<T>::Pop()
{
  if (IsEmpty() == 0)
  {
    T res = pMem[start - 1];
    pMem[start - 1] = {};
    res--;
    return res;
  }
  else
    throw "Stack is empty";
}



template<class T>
inline TStack<T> TStack<T>::operator=(const TStack<T>& st)
{
  if (st.pMem == nullptr)
    throw "st is empty";
  size = st.size;
  start = st.start;
  delete[] pMem;
  pMem = new T[size];
  for (size_t i = 0; i < size; i++)
    pMem[i] = st.pMem[i];

  return *this;
}

template<class T>
inline TStack<T> TStack<T>::operator=(TStack<T>&& st)
{
  size = st.size;
  start = st.start;
  pMem = st.pMem;

  st.size = 0;
  st.start = 0;
  st.pMem = nullptr;

  return *this;
}