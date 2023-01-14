

#include <cassert>
#include "pinIo.h"

PIN_IO::PIN_IO(const string& _fileName):
fileName(_fileName),
inputFile(new ifstream(_fileName))
{
    assert(inputFile);

}

PIN_IO::~PIN_IO() {
    delete inputFile;
}

bool PIN_IO::readInstr(RT_OBJ& result) {
    bool isEof = inputFile->eof();
    if (isEof) return false;
    inputFile->read((char*)(&result), sizeof(RT_OBJ));
    /// else is not defined.
}

std::string to_string(const RT_OBJ& obj) {
    std::ostringstream ss;
    ss << "loadAddr: [";
    for (int i = 0; i < 2; i++) {
        ss << "0x" << std::hex << obj.loadAddr[i] << ", ";
    }
    ss.seekp(-2, ss.cur);
    ss << "], storeAddr: [";
    for (int i = 0; i < 2; i++) {
        ss << "0x" << std::hex << obj.storeAddr[i] << ", ";
    }
    ss.seekp(-2, ss.cur);
    ss << "], fetchId: " << std::dec << obj.fetchId << ", loadMemOpNum: [";
    for (int i = 0; i < 2; i++) {
        ss << (int)obj.loadMemOpNum[i] << ", ";
    }
    ss.seekp(-2, ss.cur);
    ss << "], storeMemOpNum: [";
    for (int i = 0; i < 2; i++) {
        ss << (int)obj.storeMemOpNum[i] << ", ";
    }
    ss.seekp(-2, ss.cur);
    ss << "]";
    return ss.str();
}

