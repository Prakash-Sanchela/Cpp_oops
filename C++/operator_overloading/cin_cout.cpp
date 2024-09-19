class cout_cin{
private:
  int i;
public:
  friend ostream& operator<<(ostream& obj, cout_cin &obj);
  friend ostream& operator<<(ostream& obj, cout_cin &obj);
};
ostream& operator<<(ostream& obj, cout_cin &obj){
  out<<obj.i;
  return out;
}
istream& operator<<(istream& obj, cout_cin &obj){
  out>>obj.i;
  return out;
}
int main()
{
  cout_cin obj;
  cout<<obj;
}
