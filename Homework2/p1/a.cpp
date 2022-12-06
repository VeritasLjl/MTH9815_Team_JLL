#include<iostream>
#include<string>
#include<boost/interprocess/shared_memory_object.hpp>
#include<boost/interprocess/mapped_region.hpp>

using namespace std;


int main(){
	int toPass = 0;
	cout<<"Please enter a integer."<<endl;
	cin>>toPass;
	cout<<"Received."<<endl;
	
	using namespace boost::interprocess;
	shared_memory_object shm_obj(create_only,"shared_memory",read_write);
	shm_obj.truncate(16);
	mapped_region region(shm_obj,read_write);
	memset(region.get_address(),0,region.get_size());
	int* ptr = (int*)region.get_address();
	*ptr = toPass;
	return 0;
}
