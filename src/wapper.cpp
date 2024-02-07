//
// Created by Filip Žitný on 03/02/2024.
//
#include <pybind11>
#include <server/server.h>
#include <client/client.h>
#include <socket/socket.h>
#include <handler/html_handler.h>
#include <app.h>

namespace py = pybind11;

PYBIND11_MODULE(cimi,m) {

    m.doc() = "The C++ micro framework for building web applications.";
    m.def("add", &add, "A function that adds two numbers");

    py::class_<Client>(m, "Client")
            .def(py::init<>())
            .def("connect_server", &Client::connectToServer)
            .def("send_message", &Client::sendMessage)
            .def("parse_address", &Clinet::parseAddress);

    py::class_<Server>(m, "Server")
            .def(py::init<>())
            .def("run_server", &Server::runServer);

    py::class_<Socket>(m,"Socket")
            .def(py::init<>())
            .def("get_sock_fd", &Socket::getSockfd)
            .def("create", &Socket::create)
            .def("bind_socket", &Socket::bindSocket)
            .def("listen_socket", &Socket::listenSocket)
            .def("accept_connection", &Socket::acceptConnection)
            .def("connect_server", &Socket::connectToServer)
            .def("parse_address", &Socket::parseAddress);

    py::class_<HtmlLHandler>(m,"HtmlLHandler")
            .def("read_html", &HtmlLHandler::readHtmlFile);

    py::class_<App>(m,"Cimi")
            .def("run_server",&App::runServer)
            .def("run_client", &App::runClient)
            .def("run", &App::run);
}

