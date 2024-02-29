template <typename T>
class mVector
{
private:
    int m_size;
    int m_capacity;
    T* pVec;
    
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
            T* temp = new T[m_capacity*2];
            
            // copy old to new
            for(int index = 0; index < m_capacity; index++)
            {
                temp[index] = pVec[index];
            }
            delete[] pVec;
            
            m_capacity = m_capacity * 2;
            pVec = temp;
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
