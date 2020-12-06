#include "Buffer.h"

void Buffer::writeData(const char* data, const unsigned& len)
{
	if (!data)
		return;

	if (len <= 0 || len > this->buffersize)
		return;


	for (int i = 0; i < len; i++) {
		this->buffer[i] = data[i];
	}
}

void Buffer::fillOnes()
{
	for (int i = 0; i < this->buffersize; i++) {
		if (i % 2 == 0)
			this->buffer[i] = '0';
		else
			this->buffer[i] = '1';
	}
}


