//
// Created by tanawin on 8/6/2566.
//
//
//#include "pyCore.h"
//
//namespace traceBuilder::core{
//
//    void PYCORE::myVirtual(){
//        std::cout << "pycore";
//    }
//
//    void PYCORE::setTraceFrontEnd(const std::string& staticFilePath, const std::string& dynamicFilePath) {
//            std::cout << staticFilePath << std::endl;
//            std::cout << dynamicFilePath << std::endl;
//    }
//
//    void PYCORE::setResultFrontEnd(std::string instrFile, std::string dynFile, std::string statFile) {
//            std::cout << instrFile << std::endl;
//            std::cout << dynFile   << std::endl;
//            std::cout << statFile  << std::endl;
//    }
//
//    void PYCORE::sum(){
//        std::cout << 5555;
//    }
//
//
//    int add(int i, int j){
//        return i + j;
//    }
//
//
//
//    namespace py = pybind11;
//    PYBIND11_MODULE(traceBuilder, m){
//       py::class_<CORE>(m, "CORE")
//               .def(py::init<CORE*>())
//               .def("vir", &CORE::myVirtual);
//
//       py::class_<PYCORE, CORE>(m, "PYCORE")
//               .def(py::init<PYCORE*>())
//               .def("setFe", &PYCORE::setResultFrontEnd)
//               .def("vir", &PYCORE::myVirtual);
//
//    }
//
//}