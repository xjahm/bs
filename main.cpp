#include <iostream>
#include <vector>
#include <filesystem>
#include <charconv>

using namespace std;

string dir = filesystem::current_path();

void clear() {
	system("clear");
}

string rs (string text, bool a) {
        int pos = 0;
        int count = 0;
        for (char i : text) {
        	if (i == '/' && count != size(text)- 1 && a == false) {
                        pos = count;
                } else if (i == '/') {
                        pos = count;
                }
                count ++;
	}
	if (a) {
        	return text.substr(pos + 1, text.length());
	}
	else {
		return text.substr(0, pos + 1);
	}
}

vector<string> pf (string path) {
	vector<string> r = {rs(dir.substr(0, dir.length() - 1), false)};
	for (const auto & file : filesystem::directory_iterator(path))
		r.push_back(file.path());
	return r;
}

void pl (vector<string> list) {
	int count = 0;
	cout << "--- " << dir << " ---" << endl << endl;
	for (string x : list) {
		cout << count << " - " << x << endl;
		count ++;
	}
}

int main() {
	if (dir.substr(dir.length() - 1) != "/") {
        	dir = dir + "/";
        }
	while (true) {
		clear();
		pl(pf(dir));
		string ans;
		cin >> ans;
		if (ans == "e"){
			return 0;
		}else if (ans == "o"){
			string ton = "open "+dir;
			system(ton.c_str());
		}else {
			int ans_int;	
			from_chars(ans.c_str(), ans.c_str() + ans.length(), ans_int);
			if (dir == "/" && pf(dir)[ans_int] == "") {
				;
			}else if (filesystem::is_directory(pf(dir)[ans_int]) && ans_int != 0) {
				dir = dir + rs(pf(dir)[ans_int], true);
			}else if (ans_int == 0) {
				dir = rs(pf(dir)[ans_int], false);
			} else {
				string exc = "open /" + pf(dir)[ans_int];
				system(exc.c_str());
			}
			if (dir.substr(dir.length() - 1) != "/") {
				dir = dir + "/";
			}
		}
	}
	return 0;
}
