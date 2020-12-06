#pragma once
#include <iostream>

class Buffer
{
private:
	unsigned id;
	unsigned buffersize;
	char* buffer;


public:
	//Constructors
	Buffer(unsigned const id, unsigned const buffersize) {
		this->id = id;
		this->buffer = new char[buffersize];
		this->buffersize = buffersize;
		for (unsigned i = 0; i < buffersize; i++) {
			this->buffer[i] = 0;
		}
	}

	Buffer(unsigned const id, char* const data, unsigned const datasize) {
		this->id = id;
		this->buffer = new char[datasize];
		memcpy(this->buffer,data,datasize);
		this->buffersize = datasize;
	}

	Buffer(const Buffer& other) : id{ other.id }, buffersize{ other.buffersize } {
		buffer = new char[buffersize];
		memcpy(buffer, other.buffer, buffersize);
	}

	Buffer(const Buffer&& other) : id{ other.id }, buffersize{ other.buffersize } {
		buffer = new char[buffersize];
		memcpy(buffer, other.buffer, buffersize);
	}

	~Buffer() {
		delete[] buffer;
	}

	//Getter
	unsigned getID() { return id; }
	char* readData() { return this->buffer; }

	//Setter
	void writeData(const char* data, const unsigned &len);
	void fillOnes();
};

