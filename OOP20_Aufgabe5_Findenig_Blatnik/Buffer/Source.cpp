#include <iostream>
#include "Buffer.h"

void useBuffer(Buffer v) {
	return;
}

Buffer createBuffer() {
	Buffer lokalBuffer(rand(), rand());
	lokalBuffer.fillOnes();
	return lokalBuffer;
}

int main()
{
	Buffer myBuffer(10, 20);
	char name[10] = "Stefan";
	Buffer myBuffer2(12, name, 10);


	char name2[10] = "Blatnik";
	myBuffer.writeData(name2, 10);


	useBuffer(myBuffer);
	Buffer myBuffer3 = createBuffer();

	std::cout << myBuffer3.readData() <<std::endl;

	std::cin.get();

}

	