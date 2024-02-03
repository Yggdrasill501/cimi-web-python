from setuptools import setup, Extension
from pybind11.setup_helpers import Pybind11Extension, build_ext

ext_modules = [
    Pybind11Extension("cimi", ["app.h"]),
]

setup(
    name="Cimi-Web",
    version="0.1",
    author="Filip Žitný",
    description="The C++ micro framework for building web applications.",
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
)