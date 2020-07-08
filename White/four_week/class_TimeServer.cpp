#include <iostream>
#include <exception>
#include <string>

using namespace std;

class TimeServer {
public:
  string GetCurrentTime() {
	try {
		last_fetched_time = AskTimeServer();
	} catch (system_error&) {
	}
	return last_fetched_time;
  }
private:
  string last_fetched_time = "00:00:00";
};
