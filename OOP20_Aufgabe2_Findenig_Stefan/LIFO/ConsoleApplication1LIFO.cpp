#include <iostream>
#include <array>
#include <stack>

struct Material {
	unsigned id;
	unsigned articleNumber;
	std::string description;
};

typedef std::stack<std::unique_ptr<Material>> DRAWER;	//Using stack for LIFO - Using Unique pointer because every input should be unique
std::array<DRAWER, 10> STORAGE;							//Fix storage capacities

//Lesson learned: dont try to copy unique pointers in for loops .... ;)

void put_into_storage(const Material mats) {
	auto mat = std::make_unique<Material>();
	mat->articleNumber = mats.articleNumber;
	mat->id = mats.id;
	mat->description = mats.description;

	for (auto& i : STORAGE) {
		if (i.size() > 0 && i.top()->articleNumber == mats.articleNumber) {
			i.push(std::move(mat));
			return;
		}
	}
	for (auto& i : STORAGE) {
		if (i.empty()) {
			i.push(std::move(mat));
			return;
		}
	}
}

void take_from_stroage(const Material mats) {
	auto place = mats.articleNumber;

	for (auto& i : STORAGE) {
		if (i.size() > 0){
			if (i.top()->articleNumber == place) {
				i.pop();
					return;
			}
		}
	}
	std::cout << "Article is not in Storage" << std::endl;
}


int main()
{
	
	unsigned cnt = 0;

	Material mat1;
	mat1.articleNumber = 1;
	mat1.id = cnt++;
	mat1.description = "Television";
	Material mat2;
	mat2.articleNumber = 2;
	mat2.id = cnt++;
	mat2.description = "Notebook";
	Material mat3;
	mat3.articleNumber = 3;
	mat3.id = cnt++;
	mat3.description = "PC";
	Material mat4;
	mat3.articleNumber = 4;
	mat3.id = cnt++;
	mat3.description = "Phone";

	
	put_into_storage(mat1);
	put_into_storage(mat1);
	put_into_storage(mat2);
	put_into_storage(mat3);
	take_from_stroage(mat1);
	take_from_stroage(mat2);
	take_from_stroage(mat4);

	for (auto& i : STORAGE) {
		if (i.size() > 0) {
			std::cout << "Storage: " << i.top()->articleNumber << "has " << i.size() << i.top()->description << std::endl;
		}
	}
}
