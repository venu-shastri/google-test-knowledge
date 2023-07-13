#include <string>
#include "gtest/gtest.h"
using namespace std;
//Not test friendly
class Asymetric128Algorithm {
public:
	string encrypt(string message) {
		return message + " encrypted";
	}
	string decrypt(string cipher) {
		return cipher + " decrypted";
	}
	
};
//Not test friendly
class IHashGenerator {
public:
	virtual string getDigest(string message) = 0;
};
class SHAlgorithm : IHashGenerator{
public:
	string getDigest(string message) {
		return message + " Digest ";
	}
};
//Not test friendly
class DistributedStoragePersister {

public:
	void save(string signedMessage){}
	string getMessage() { return ""; }
};
class DigitalSignatureManager {
private:
	IHashGenerator* ptrToHashGenerator;
	void persist(string signedMessage){}
public:
	DigitalSignatureManager(IHashGenerator *address):ptrToHashGenerator{address}{}
	void sign(string content) {
		//Hash
		//Interaction/ delegation
		this->ptrToHashGenerator->getDigest(content);
		//encrypt
		//persist
	}
	bool verifySignature(string cotent) {

	}
};

//Fake Hash Dependency
class FakeHashGenerator :public IHashGenerator {
public:
	string getDigest(string message) {
		return "";
	}
};
class SmartFakeHashGenerator :public IHashGenerator {
	int getDigestMethodCallCount = 0;
	string getDigestMethodArgumentValue = "";
public:
	string getDigest(string message) {
		this->getDigestMethodCallCount += 1;
		this->getDigestMethodArgumentValue = message;
		return message + "Encryption";
	}
	int getDigestCallCount() { return this->getDigestMethodCallCount; }
	string  getDigestArgumnetValue() { return this->getDigestMethodArgumentValue; }
};
//Test Env
TEST(DigitalSignatureManagerTestSuite, TestSignMethodInteraction) {
	//Arrange
	FakeHashGenerator fakeDependency;
	DigitalSignatureManager objUnderTest(&fakeDependency);
	//Act
	objUnderTest.sign("Test Message");

	//Assert
}
