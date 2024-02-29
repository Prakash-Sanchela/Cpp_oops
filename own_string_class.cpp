#include <iostream>
#include <cstring>
using namespace std;

// implement string class
class s_string
{
private:
    char *ptr;
    unsigned int len;
public:
    s_string()
    {
        ptr = nullptr;
        len = 0;
    }
    /*s_string() : ptr(nullptr), len(0)
    {
    }*/
    // parameterized constructor
    s_string(const char* p)
    {
        len = strlen(p);
        ptr = new char[len+1];
        strcpy(ptr, p);
    }
    // copy constructor
    s_string(const s_string& obj)
    {
        len = obj.len;
        ptr = new char[len+1];
        strcpy(ptr, obj.ptr);
    }
    // move constructor
    s_string(const s_string&& obj)
    {   
        ptr = obj.ptr;
        len = obj.len;
        obj = nullptr;
        obj.len = 0;
    }
    // copy assignment operator
    s_string& operator=(const s_string& obj)
    {
        if (this != &obj)
        {
            // here we already have some resource allocated for this object
            // so to avoid any confusion we delete the already allocated 
            // memory first
            delete []ptr;
            len = obj.len;
            ptr = new char[len+1];
            strcpy(ptr, obj.ptr);
        }
        return *this;
    }
    // copy assignment operator with CAS : copy and swap
    // signature argument we are taking obj as value, so it will call copy constructor
    // as obj is local and once we do a swap obj will goes out of scope and
    // data will get swaped. 
    s_string& operator=(s_string obj)
    {
        std::swap(this->ptr, obj.ptr);
        std::swap(this->len, obj.len);
        return *this;
    }
    unsigned int length()
    {
        return len;
    }
    friend ostream& operator<<(ostream& out,const s_string& obj);
    friend istream& operator>>(istream& in, s_string& obj);
    ~s_string()
    {
        if (ptr)
        {
            delete []ptr;
            ptr = nullptr;
            len = 0;
        }
    }
};
ostream& operator<<(ostream& out,const s_string& obj)
{
    out<<obj.ptr;
    return out;
}
istream& operator>>(istream& in, s_string& obj)
{
    in>>obj.ptr;
    return in;
}
int main()
{
    cout<<"Hello World";
		// string class functionality
    s_string s1; // default constructor
    s_string s2 = "prakash"; // parameterized constructor
    s_string s3 = s1; // copy constructor
    s3 = s2; // copy assignment operator
        
    int len = s3.length();
    cout << s2; //overload <<
    cin >> s1;  //overload >>
    
    return 0;
}
