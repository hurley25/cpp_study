#include <iostream>

#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>

int main(int argc, char  *argv[])
{
	boost::interprocess::shared_memory_object shdmem(boost::interprocess::open_or_create,
									"Highscore", boost::interprocess::read_write);

	shdmem.truncate(1024);

	std::cout << shdmem.get_name() << std::endl;
	
	boost::interprocess::offset_t size(0);
	if (shdmem.get_size(size)) {
		std::cout << size << std::endl;
	}

	boost::interprocess::mapped_region region(shdmem, boost::interprocess::read_write);
	std::cout << std::hex << "0x" << region.get_address() << std::endl;
	std::cout << std::dec << region.get_size() << std::endl;

	int *a = static_cast<int *>(region.get_address());
	*a = 99;

	boost::interprocess::mapped_region region2(shdmem, boost::interprocess::read_only);

	std::cout << std::hex << "0x" << region2.get_address() << std::endl;
	std::cout << std::dec << region2.get_size() << std::endl;

	std::cout << "Number: " << *static_cast<int *>(region2.get_address()) << std::endl;

	bool removed = shdmem.remove("Highscore");

	std::cout << "removed? " << removed << std::endl;

	return 0;
}
