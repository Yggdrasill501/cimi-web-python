//
// Created by Filip Žitný on 03/02/2024.
//
#include <pybind11>

namespace py = pybind11;

PYBIND11_MODULE(cimi) {
cimi.doc() = "Example module"; // Optional module docstring
cimi.def("add", &add, "A function that adds two numbers");
}
