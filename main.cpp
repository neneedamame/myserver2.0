#include "Server.h"
#include "mypb.pb.h"


using namespace std;
using namespace mypb;

int main() {
	try {

		dataHeader header;
		cout << sizeof(header) << endl;

		header.set_request(REQUEST_TYPE_LOGIN);
		header.set_bodysize(25564);
		cout << sizeof(header) << endl;
		
		string s;
		header.SerializeToString(&s);
		cout << s.size() << endl;

	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	cout<<"hello"<<endl;
}