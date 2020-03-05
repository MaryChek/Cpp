#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string	Search_Name(const map<int, string>& name, const int& year)
{
	string	s;

	for (auto& modificat : name) {
		if (modificat.first <= year){
			s = modificat.second;
		}
		else
			break ;
	}
	return s;
}

string	History(const map<int, string>& name, const int& year) {
		vector<string> st;
		string past;

	for (auto& a : name) {
		if (year >= a.first) {
			if (past != a.second)
				st.push_back(a.second);
			past = a.second;
		}
		else 
			break;
	}
	if (!st.empty()) {
		past = st[st.size() - 1];
		if (st.size() > 1) {
			past += " (";
			for (int i = (st.size() - 2); i >= 0; i--) {
				past += st[i];
				if (i > 0)
					past += ", ";
			}
			past += ")";
		}
	}
	return past;
}

class Person {
	public:
		void ChangeFirstName(int year, const string& first_name) {
			fst_name[year] = first_name;
		}
		void ChangeLastName(int year, const string& last_name) {
			lst_name[year] = last_name;
		}
		string GetFullName(int year) 
		{
			string lst, fst;

			fst = Search_Name(fst_name, year);
			lst = Search_Name(lst_name, year);
			if (fst.empty() && lst.empty())
				return "Incognito";
			if (!fst.empty())
				return (fst + " " + (!lst.empty() ? lst : "with unknown last name"));
			return (lst + " with unknown first name");
		}
		string GetFullNameWithHistory(int year) {
			string lst, fst;

			fst = History(fst_name, year);
			lst = History(lst_name, year);
			if (fst.empty() && lst.empty())
				return "Incognito";
			if (!fst.empty())
				return (fst + " " + (!lst.empty() ? lst : "with unknown last name"));
			return (lst + " with unknown first name");
		}
	private:

		map<int, string>	fst_name;
		map<int, string>	lst_name;

};

int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;
  
  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;
  
  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;
  
  return 0;
}

