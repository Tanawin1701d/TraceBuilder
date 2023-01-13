

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

