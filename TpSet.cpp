//#include "TpSet.h"
//template<class T>
//TpSet<T>::TpSet():currentSize(0),maxSize(BUF_LENGTH)
//{
//    try
//    {
//        buf = new T[maxSize];
//    }
//    catch(std::bad_alloc)
//    {
//        std::cout << "Ошибка выделения памяти"<<std::endl;
//        throw;
//    }
//}
//template<class T>
//TpSet<T>::TpSet(const TpSet& other)
//{
//    try
//    {
//        this->maxSize = other.maxSize;
//        this->currentSize = other.currentSize;
//        this->buf = new T[this->maxSize];
//        for (int i = 0; i < this->currentSize; i++)
//            this->buf[i] = other.buf[i];
//    }
//    catch(...)
//    {
//        std::cout << "Ошибка копирования"<<std::endl;
//        throw;
//    }
//
//}
//template<class T>
//TpSet<T>::~TpSet()
//{
//    //for (int i = 0; i < currentSize; i++)
//      //  delete buf[i];
//    delete [] buf;
//}
//
//template<class T>
//bool TpSet<T>::InSet(const T& value) const
//{
//    for (int i = 0; i < currentSize; i++)
//    {
//        if (value == buf[i])
//            return true;
//    }
//    return false;
//}
//template<class T>
//void TpSet<T>::PushBack(const T& value)
//{
//        currentSize++;
//        if (currentSize > maxSize)
//            AddSize();
//
//        this->buf[currentSize-1] = value;
//
//}
//template<class T>
//void TpSet<T>::Pop(const T& value)
//{
//    if (!InSet(value))
//    {
//        //std::cout<<"not in set"<< std::endl; //throw notInSet;
//        return;
//    }
//
//    int offset = 0;
//    bool flag_was_deleted_once = false;
//    for (int i = 0; i < this->currentSize; i++)
//    {
//        if (this->buf[i] == value && !flag_was_deleted_once)
//        {
//            offset++;
//            flag_was_deleted_once = true;
//            continue;
//        }
//        buf[i - offset] = this->buf[i];
//    }
//
//    this->currentSize--;
//
//
//}
//template <class T>
//void TpSet<T>::ShowSet() const
//{
//    if (!currentSize)
//    {
//        std::cout<<"Пустое множество"<< std::endl;
//        return;
//    }
//    for (int i = 0; i < currentSize; i++)
//        std::cout<<buf[i]<< " ";
//    std::cout << std::endl;
//}
//template<class T>
//TpSet<T>& TpSet<T>::operator = (const TpSet<T>& set1)
//{
//    //for (int i = 0; i < this->currentSize; i++)
//      //  delete buf[i];
//    delete [] buf;
//    this->currentSize = set1.currentSize;
//    this->maxSize = set1.maxSize;
//    this->buf = new T[this->maxSize]();
//    for (int i = 0; i < currentSize; i++)
//    {
//        this->buf[i] = set1.buf[i];
//    }
//
//    return *this;
//}
//template<class T>
//void TpSet<T>::AddSize()
//{
//    try
//    {
//        //throw std::bad_alloc();
//        T* temp = new T[this->maxSize+bufLength];
//        for (int i = 0; i < this->maxSize; i++)
//        {
//            temp[i] = this->buf[i];
//            //delete this->buf[i];
//        }
//        delete [] this->buf;
//        this->buf = temp;
//
//
//        this->maxSize+=bufLength;
//    }
//
//    catch (std::bad_alloc)
//    {
//        std::cout << "Ошибка выделения памяти"<<std::endl; //exit(1)
//        throw;
//    }
//    catch (...)
//    {
//        std::cout << "Что-то пошло не так"<<std::endl;
//        throw;
//    }
//    //std::bad_alloc &
//    //TODO catch
//}
//template<class T>
//TpSet<T> TpSet<T>::operator + (const TpSet<T>& set1) const
//{
//    TpSet<T> temp(*this);
//    for (int i = 0; i < set1.currentSize; i++)
//    {
//        if (!InSet(set1.buf[i])) {}
//        temp.PushBack(set1.buf[i]);
//    }
//    return temp;
//}
//template<class T>
//TpSet<T> TpSet<T>::operator * (const TpSet<T> &set1) const
//{
//
//    TpSet<T> temp(*this);
//    for (int i = 0; i < currentSize; i++)
//    {
//        if (count(buf[i]) > set1.count(buf[i]))
//            temp.Pop(buf[i]);
//    }
//    return temp;
//}
//
//template<class T>
//TpSet<T> TpSet<T>::operator - (const TpSet<T>& set1) const
//{
//    TpSet<T> result (*this);
//
//    TpSet<T> a = *this * set1;
//    for (int i = 0; i < a.currentSize; i++)
//        result.Pop (a.buf[i]);
//
//    return result;
//}
//
//template<class T>
//TpSet<T> TpSet<T>::operator ^ (const TpSet<T>& set1) const
//{
//    TpSet<T> result;
//    TpSet<T> a = *this + set1;
//    TpSet<T> b = *this * set1;
//    //result = (a - b);//.ShowSet();
//    //result.ShowSet();
//    return (a-b);
//}
//template<class T>
//int TpSet<T>::count(const T& value) const
//{
//    int count = 0;
//    for (int i = 0; i < currentSize; i++)
//        if (buf[i] == value)
//        count++;
//    return count;
//}
//template<class T>
//const T TpSet<T>::operator[] (int number) const //????? Можно писать так?
//{
//    if (number < currentSize && number > 0)
//        return buf[number];
//    throw (std::out_of_range());
//}
//template<class T>
//T& TpSet<T>::operator[] (int number)
//{
//    if (number < currentSize && number > 0)
//        return buf[number];
//    throw (std::out_of_range());
//}
//
//template<class T>
//std::ostream& operator<< (std::ostream& out,const TpSet<T>& val)
//{
//    try
//    {
//        for (int i = 0; i < val.currentSize; i++)
//        {
//            out<<val.buf[i]<<" ";
//        }
//        out<<std::endl;
//        return out;
//    }
//    catch(...)
//    {
//        std::cout<<"Ошибка вывода на экран"<<std::endl;
//        throw;
//    }
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
