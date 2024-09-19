// for post increment we are using dummy argument just to make difference between pre and post increament
// in post increment first object was returned then it will get increased, so here we saved the current object then it will 
// incremented. 
class ctx{
private:
    int counter;
public:
    int get_count(){return counter;}
    // pre increament
    ctx& operator++(){
        ++counter;
        return *this;
    }
    ctx operator++(int)
    {
        ctx temp = *this;
        ++counter;
        return temp;
    }
};
int main() {
    ctx obj;
    obj++;
    ++obj;
    cout <<"counter : "<< obj.get_count()<<endl;
}
