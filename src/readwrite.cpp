/*
 * magic.hpp
 *
 *  Created on: Dec 9, 2022
 *      Author: dwd
 */
#include "readwrite.hpp"

template<>
bool writeStruct(int handle, gpio::UART_Bytes* bytes) {
	return write(handle, bytes->data(), bytes->size()) == bytes->size();
}
template<>
bool readStruct(int handle, gpio::UART_Bytes* bytes) {
	return read(handle, bytes->data(), bytes->size()) == bytes->size();
}
