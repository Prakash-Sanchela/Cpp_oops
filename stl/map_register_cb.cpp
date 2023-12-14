// write a C++ program in which using a map, string as key and callback as value. register the callbacks on init and execute those callbacks based on string input

#include <iostream>
#include <map>

using namespace std;

// define callback

typedef void (*fptr)(int);

class cb_manager
{
private:
    std::map<std::string, fptr> m_cb;    
public:
    void register_cb(std::string key, fptr callback)
    {
        m_cb[key] = callback;
    }
    void execute_cb(std::string key, int arg)
    {
        auto itr = m_cb.find(key);
        if (itr != m_cb.end())
        {
            fptr f_ptr = itr->second;
            f_ptr(10);
        }
        
    }
};

void callback_1(int i)
{
    cout << "I am callback_1 : " << i <<endl;
}
void callback_2(int i)
{
    cout << "I am callback_2 : " << i <<endl;
}
int main()
{
    cout<<"Hello World";
    cb_manager cbm;
    cbm.register_cb("callback1", callback_1);
    cbm.register_cb("callback2", callback_2);
    
    cbm.execute_cb("callback1", 100);
    cbm.execute_cb("callback2", 200);

    return 0;
}
