/*********************************************************************************
 Copyright 2017 GlobalPlatform, Inc.

 Licensed under the GlobalPlatform/Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 https://github.com/GlobalPlatform/SE-test-IP-connector/blob/master/Charter%20and%20Rules%20for%20the%20SE%20IP%20connector.docx

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
 implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 *********************************************************************************/

#include "server/server_api.hpp"
using namespace server;

#include <iostream>
#include <stdlib.h>

int __cdecl main(void) {
	ServerAPI* server = new ServerAPI(0);
	server->initServer("./config/init.json");
	server->startServer("127.0.0.1", "62111");
	Sleep(10000);
	server->diagClient(1);
	server->sendCommand(1, "00 A4 04 00 00");
	server->echoClient(1);
	server->coldReset(1);
	server->warmReset(1);
	server->powerOFFField(1);
	server->powerONField(1);
	server->listClients();
	server->restartTarget(1);
	server->sendCommand(1, "00 A4 04 00 00");
	server->stopServer();
	delete server;
	return 0;
}
