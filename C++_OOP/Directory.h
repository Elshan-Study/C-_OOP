#pragma once
#include <string>
class Directory
{
protected:
	std::string firmName;
	std::string owner;
	std::string phone;
	std::string address;
	std::string occupation;
public:
	Directory() : firmName("Unknown"), owner("Unknown"), phone("Unknown"), address("Unknown"), occupation("Unknown") {};
	explicit Directory(const std::string& firmName, const std::string& owner, const std::string& phone, const std::string& address,
		const std::string& occupation) : firmName(firmName), owner(owner), phone(phone),
		address(address), occupation(occupation) {};

	~Directory() = default;

	void setFirmName(const std::string& firmName) { this->firmName = firmName; }
	void setOwner(const std::string& owner) { this->owner = owner; }
	void setPhone(const std::string& phone) { this->phone = phone; }
	void setAddress(const std::string& address) { this->address = address; }
	void setOccupation(const std::string& occupation) { this->occupation = occupation; }

	std::string& getFirmName() { return firmName; }
	std::string& getOwner() { return owner; }
	std::string& getPhone() { return phone; }
	std::string& getAddress() { return address; }
	std::string& getOccupation() { return occupation; }
};

