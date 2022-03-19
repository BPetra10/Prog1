/*
    g++ drill19.cpp -o drill19  
*/

#include <iostream>
#include <string>
#include <vector>
#include <exception>

using namespace std; 

template<typename T> 
struct S 
{
    //2. constructor
    S():val(T()){};
    S(T s):val(s){};

    //5.
    T& get();
    //11.
    const T& get() const;

    //9.
    void set(const T& new_T);
    //void set(T n);

    //10.
    T& operator=(const T&);

    //12.
    void read_val(T& v);
    
    //7.
    private:
        T val;
};

//6.
template<typename T> T& S<T>::get() {return val;};
//11.
template<typename T> const T& S<T>::get() const {return val;};

//9.
template<typename T> void S<T>::set(const T& new_T) {val=new_T;};
//template<typename T> void S<T>::set(T n) {val=n;};

//10.
template<typename T> T& S<T>::operator=(const T& s)
{
    val = s; // set new elements
    return val;
}

//12.
template<typename T> void read_val(T& r)
{
    cin>>r;
}

template<typename T> void write(T& v, string name)
{
  cout<<name<<" example: "<<v.get()<<"\n";
}

//14.
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v)
{
    os << "{ ";
    for (int i = 0; i<v.size(); ++i) {
        os << v[i];
        if (i<v.size()-1) os << ',';
        os << ' ';
    }
    os << "}";
    return os;
}

template<typename T> istream& operator>>(std::istream& is, vector<T>& v)
{
    char ch = 0;
    is >> ch;
    if (ch != '{') {
        is.unget(); //maybe my caller can use that character
        /*Moves the get pointer one character backwards, 
        making the last character gotten by an input operation 
        available once again for the next input operation.*/
        return is;
    }

    for (T val; is >> val; ) {
        v.push_back(val);
        is >> ch;
        if (ch != ',') break;
    }

    return is;
}

int main()
try {
 //3.
  S<int> int_example {11};
  S<char> char_example {'c'};
  S<double> double_example {16.5};
  S<string> string_example {"this is a string"};
  vector<int> v {1,2,5,6};
  S<vector<int>> vector_example {v};

  //4.
  /*We set T private, so this print does not work:
  cout<<"int example: "<<int_example.val<<"\n";
  cout<<"char example: "<<char_example.val<<"\n";
  cout<<"double example: "<<double_example.val<<"\n";
  cout<<"string example: "<<string_example.val<<"\n";
  cout<<"Vector example:\n";
    for(int i=0;i<vector_example.val.size();++i)
        cout<<vector_example.val[i]<<"\n";
  */

  //8.
  cout<<"task 8:\n";
  write(int_example,"int");
  write(char_example,"char");
  write(double_example,"double");
  write(string_example,"string");
  cout<<"Vector example:\n";
    for(int i=0;i<vector_example.get().size();++i)
        cout<<vector_example.get()[i]<<"\n";

  //9. test set() modifying datas:
  int_example.set(16);
  char_example.set('a');
  double_example.set(32.34);
  string_example.set("Modified srting");
  v[0] = 98;
  vector_example.set(v);

  cout<<"\nData modifying with set():\n";
  write(int_example,"int");
  write(char_example,"char");
  write(double_example,"double");
  write(string_example,"string");
  cout<<"Vector example:\n";
    for(int i=0;i<vector_example.get().size();++i)
        cout<<vector_example.get()[i]<<"\n";

  //10. test = 
  int_example = 66;
  char_example = 'X';
  double_example = 987.5;
  string_example = "Last string";
  v[0] = 45;
  vector_example = v;

  cout<<"\nData modifying with =\n";
  write(int_example,"int");
  write(char_example,"char");
  write(double_example,"double");
  write(string_example,"string");
  cout<<"Vector example:\n";
    for(int i=0;i<vector_example.get().size();++i)
        cout<<vector_example.get()[i]<<"\n";

  //13. Using read_val() 
    cout<<"\nGive an int: "<<"\n";
    int given_int;
    read_val(given_int);
    S<int> s_int {given_int};
    

    cout<<"Give a char: "<<"\n";
    char given_char;
    read_val(given_char);
    S<char> s_char {given_char};
   

    cout<<"Give a double: "<<"\n";
    double given_double;
    read_val(given_double);
    S<double> s_double {given_double};
    

    cout<<"Give a string: "<<"\n";
    string given_string;
    read_val(given_string);
    S<string> s_string {given_string};

    cout<<"\nCin read: \n";
    cout<<"int: "<<s_int.get()<<"\n";
    cout<<"char: "<<s_char.get()<<"\n";
    cout<<"double: "<<s_double.get()<<"\n";
    cout<<"string: "<<s_string.get()<<"\n";

    //14.
    cout << "Vector<int>: (format: { val1, val2, val3 }) ";
    vector<int> given_vector;
    read_val(given_vector);
    S<vector<int>> s_vector {given_vector};
    cout << "S<vector<int>> cin read: " << s_vector.get() << '\n';
}
catch (exception& e) {
    cerr << "Exception: " << e.what() << "\n";
}
catch (...) {
    cerr << "Exception\n";
}
