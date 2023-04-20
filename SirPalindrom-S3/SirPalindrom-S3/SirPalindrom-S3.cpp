#include <iostream>
using namespace std;

int main() {
	char sir[31], aux[31];

	cin.getline(sir,30);
	strcpy_s(aux,sir);
	_strrev(sir);


	if (strcmp(aux, sir) == 0)
		cout << sir << " este palindrom.";
	else cout << sir << " nu este palindrom.";
	return 0;

}
