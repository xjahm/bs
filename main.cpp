#include <iostream>
#include <vector>

using namespace std;

void err(string err) {
	cout << "Ha habido un error: " << err << endl;
}

int main(int argc, char** argv) {
	if (argc != 1) {
		err("Se han proporcionado argumentos cuando no se debería");
	}
}