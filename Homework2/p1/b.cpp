#include<iostream>
#include<string>
#include<boost/interprocess/shared_memory_object.hpp>
#include<boost/interprocess/mapped_region.hpp>

using namespace std;


int main(){
	using namespace boost::interprocess;
	shared_memory_object shm_obj(open_or_create,"shared_memory",read_only);
	mapped_region region(shm_obj,read_only);
	int* ptr = (int*)region.get_address();
    cout<<"Print: "<<*ptr<<endl;
	shared_memory_object::remove("shared_memory");
	return 0;
}
