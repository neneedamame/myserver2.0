#include "Server.h"
#include "mypb.pb.h"


int main() {
	try {
		Server server("myserver", "maodou", "12345w");
		server.run();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}