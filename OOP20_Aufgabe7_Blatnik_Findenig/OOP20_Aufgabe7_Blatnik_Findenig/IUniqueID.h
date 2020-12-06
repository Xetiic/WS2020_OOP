#pragma once
class IUniqueID
{
protected:
	static unsigned uniqueID;
public:
	static unsigned counter() {
		uniqueID++;
		return uniqueID;
	}
	static unsigned printID() {
		return uniqueID;
	}
};

