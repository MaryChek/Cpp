#include <string>

using namespace std;

struct Week {
	explicit Week(const string& str) {
		week = str;
	}
	string week; 
};

struct Course {
	explicit Course(const string& str) {
		course = str;
	}
	string course; 
};

struct Specialization {
	explicit Specialization(const string& str) {
		specialization = str;
	}
	string specialization; 
};

struct LectureTitle {
	LectureTitle(Specialization s1, Course s2, Week s3) {
		specialization = s1.specialization;
		course = s2.course;
		week = s3.week;
	}
  string specialization;
  string course;
  string week;
};
