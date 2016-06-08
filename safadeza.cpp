#include <iostream>

using namespace std;
int somatorio(int a)
{
	return a==1 ? a : somatorio(a-1)+a;
}
int main () {
	float dia,ano;
	int mes;
	cout << "Digite seu dia de nascimento: " << endl;
	cin >> dia;
	cout << "Digite seu mes de nascimento: " << endl;
	cin >> mes;
	cout << "Agora digite o ano: " << endl;
	cin >> ano;
	float safadeza = (float)somatorio(mes)+(ano/100)*(50-dia);
	float anjo = 100 - safadeza;
	if (anjo<0)
	{
		safadeza=100+anjo;
		anjo*=-1;
	}
	cout << "Sua % de safadeza é " << safadeza << " e sua % de anjo é " << anjo << endl;
	return 0;
}