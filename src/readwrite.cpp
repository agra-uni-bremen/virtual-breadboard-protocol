/*
 * magic.hpp
 *
 *  Created on: Dec 9, 2022
 *      Author: dwd
 */
#include "readwrite.hpp"

#include <iostream> // FIXME: Just for debugging

template<>
bool writeStruct(int handle, gpio::UART_Bytes* bytes) {
	std::cout << "Writing " << bytes->size() << " bytes" << std::endl;
	return write(handle, bytes->data(), bytes->size()) == bytes->size();
}
template<>
bool readStruct(int handle, gpio::UART_Bytes* bytes) {
	std::cout << "Reading " << bytes->size() << " bytes..." << std::endl;
	const auto nbytes = read(handle, bytes->data(), bytes->size());
	std::cout << "read " << nbytes << " bytes" << std::endl;
	return nbytes == bytes->size();
}
