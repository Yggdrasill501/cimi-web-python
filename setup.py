from setuptools import setup, Extension
from pybind11.setup_helpers import Pybind11Extension, build_ext

setup(
    name="Cimi-Web",
    version="0.1",
    author="Filip Žitný",
    description="The C++ micro framework for building web applications.",
    ext_modules=[
        Extension(
            'cimi',
            ['wrapper.cpp', 'client.cpp', 'server.cpp', 'socket.cpp'],
            include_dirs=[pybind11.get_include()],
            language='c++',
            extra_compile_args=['-std=c++17'],
        ),
    ],
    zip_safe=False,
)