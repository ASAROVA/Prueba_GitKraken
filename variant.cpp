#include <memory>
#include <iostream>
#include <malloc.h>
#include <variant>
#include <cmath>

using namespace std;
#define SL cout<<endl

void* operator new(size_t count){
    cout << "allocating " << count << " bytes" << endl;
    return malloc(count);
}

void operator delete(void* ptr) noexcept
{
    cout << "global op delete called\n";
    free(ptr);
}


struct SampleVisitor
{
    void operator()(int i) const { cout << "int: " << i << "\n"; }
    void operator()(float f) const { cout << "float: " << f << "\n"; }
    void operator()(const string& s) const { cout << "string: " << s << "\n"; }
};

int main() 
{
    SL;SL;
    variant<int, float, string> intFloatString;
    static_assert(variant_size_v<decltype(intFloatString)> == 3);
    
    // default initialized to the first alternative, should be 0
    visit(SampleVisitor{}, intFloatString);

    // SampleVisitor(intFloatString); // Error, debe usarse "visit"
    
    // index will show the currently used 'type'
    cout << "index = " << intFloatString.index() << endl;
    intFloatString = 100.0f;
    cout << "index = " << intFloatString.index() << endl;
    intFloatString = "hello super world";
    cout << "index = " << intFloatString.index() << endl;

    // try with get_if:
    if (const auto intPtr (get_if<int>(&intFloatString)); intPtr) 
        cout << "int!" << *intPtr << "\n";
    else if (const auto floatPtr (get_if<float>(&intFloatString)); floatPtr) 
        cout << "float!" << *floatPtr << "\n";

    if (holds_alternative<int>(intFloatString))
	    cout << "the variant holds an int!\n";
	else if (holds_alternative<float>(intFloatString))
	    cout << "the variant holds a float\n";
	else if (holds_alternative<string>(intFloatString))
	    cout << "the variant holds a string\n";  

    // try/catch and bad_variant_access
    try 
    {
        auto f = get<float>(intFloatString); 
        cout << "float! " << f << "\n";
    }
    catch (bad_variant_access&) 
    {
        cout << "our variant doesn't hold float at this moment...\n";
    }

    // visit:
    visit(SampleVisitor{}, intFloatString);
    intFloatString = 10;
    visit(SampleVisitor{}, intFloatString);
    intFloatString = 10.0f;
    visit(SampleVisitor{}, intFloatString);

    SL;SL;
}