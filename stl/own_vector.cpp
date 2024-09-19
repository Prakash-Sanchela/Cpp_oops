template <typename T>
class mVector
{
private:
    int m_size;
    int m_capacity;
    T* pVec;
    void resize()
    {
        m_capacity = m_capacity*2;
        T *temp = new T[m_capacity]
        for(int i = 0; i< m_size;i++)
            {
                temp[i] = pVec[i];
            }
        delete[] pvec;
        pvec = temp;
    }
public :
    mVector()
    {
        m_size = 0;
        m_capacity = 1;
        pVec = new T[1];
    }
    void pushBack(T data)
    {
        if (m_size == m_capacity)
        {
            resize()
        }
        pVec[m_size] = data;
        m_size++;
    }
    void push(T data, int index)
    {
        if(index == m_size)
            pushBack(data);
        else
            pVec[index] = data;
    }
    T& operator[](int index)
    {
        if (index >= size)
            cout <<"index is out of size of vector"<<endl;
        return pVec[index];
    }
    
    int size()
    {
        return m_size;
    }
    int capacity()
    {
        return m_capacity;
    }
    void print()
    {
        for(int index = 0; index< m_size ; index++)
        {
            cout << pVec[index] << " ";
        }
        cout << endl;
    }
};
