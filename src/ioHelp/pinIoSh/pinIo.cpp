

#include <cassert>
#include "pinIo.h"
#include "../strHelp.h"

//PIN_IO::PIN_IO(const std::string& _fileName):
//fileName(_fileName),
//inputFile(new std::ifstream(_fileName))
//{
//    assert(inputFile);
//
//}
//
//PIN_IO::~PIN_IO() {
//    delete inputFile;
//}
//
//bool PIN_IO::readInstr(RT_OBJ& result) {
//    bool isEof = inputFile->eof();
//    if (isEof) return false;
//    inputFile->read((char*)(&result), sizeof(RT_OBJ));
//    /// else is not defined.
//    return true;
//}

//std::string to_string(const RT_OBJ& obj, std::vector<std::string>& fetchStr) {
//    std::ostringstream ss;
//    ss << "loadAddr: [";
//    for (int i = 0; i < 2; i++) {
//        ss << "0x" << std::hex << obj.loadAddr[i] << ", ";
//    }
//    ss.seekp(-2, ss.cur);
//    ss << "], \nstoreAddr: [";
//    for (int i = 0; i < 2; i++) {
//        ss << "0x" << std::hex << obj.storeAddr[i] << ", ";
//    }
//    ss.seekp(-2, ss.cur);
//    ss << "], \nfetchId: " << std::dec << obj.fetchId << "      :       " << concatVec(fetchStr) << "\nloadMemOpNum: [";
//    for (int i = 0; i < 2; i++) {
//        ss << (int)obj.loadMemOpNum[i] << ", ";
//    }
//    ss.seekp(-2, ss.cur);
//    ss << "], \nstoreMemOpNum: [";
//    for (int i = 0; i < 2; i++) {
//        ss << (int)obj.storeMemOpNum[i] << ", ";
//    }
//    ss.seekp(-2, ss.cur);
//    ss << "]";
//    return ss.str();
//}

