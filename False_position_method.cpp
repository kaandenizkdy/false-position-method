// false position method implementation in C++
#include <iostream>
#include<vector>
#include <cmath>
using namespace std;
double calculating_func(double x, const vector<int>& katsayilar) {
		double sonuc = 0.0;
		int n = katsayilar.size();

		for (int j = 0; j < n; j++) {
			int us = n - 1 - j; 
			sonuc += katsayilar[j] * pow(x, us);
		}
		return sonuc;
	}

double sinir_belirleme( const vector<int>& katsayilar, double hata,double ilk_aralik, double son_aralik, int& iterasyon) {
	double hesaplanan_hata = fabs((son_aralik - ilk_aralik) / son_aralik);
	double ilk_aralik_func = calculating_func(ilk_aralik, katsayilar);
	double son_aralik_func = calculating_func(son_aralik, katsayilar);
	double yeni_kok;
	if ( ilk_aralik_func * son_aralik_func >= 0 && iterasyon == 0) {
		cout << "HATA: Girilen aralikta kok olmayabilir (f(a)*f(b) >= 0)\n";
		return 0;
	}
	else {
	    yeni_kok = ((ilk_aralik * son_aralik_func) - (son_aralik * ilk_aralik_func)) / (son_aralik_func - ilk_aralik_func);
		double yeni_kok_func = calculating_func(yeni_kok, katsayilar);
		if (yeni_kok_func * ilk_aralik_func >= 0) {
			son_aralik = yeni_kok;
			iterasyon++;
		}
		else {
			ilk_aralik = yeni_kok;
			iterasyon++;
		}
	}
	if (hata < hesaplanan_hata) {
		if (iterasyon > 100) {
			cout << "cok fazla iterasyon..." << endl;
			return 0;
		}
		return sinir_belirleme(katsayilar,hata,ilk_aralik,son_aralik,iterasyon);
	}
		cout << "istenen hata degerine ulaşıldı" << endl;
		cout << "bulunan yaklasik kok: "<< yeni_kok;
		return 0;
	
}
int main() {
	cout << "False Position Method\n";
	cout << "fonksiyonun terim sayisini girin: ";
	int terim_sayisi;
	cin >> terim_sayisi;
	cout << "terimlerin katsayilari buyukten kucuge dogru girilecektir(ornegin: x^4+3x^3...):\n";
	int i = terim_sayisi - 1;
	int katsayi;
	vector<int> katsayilar;
	while (i >= 0) {
		cout << "x^" <<  i << " katsayisi: ";
		cin >> katsayi;
		katsayilar.push_back(katsayi);
		i--;
	}
	for (int j = 0; j < katsayilar.size(); j++) {
		cout << katsayilar[j]<< "x^"<<terim_sayisi - 1 - j<< "  ";
	}
	double hata; 
	double ilk_aralik;
	double son_aralik;
	int iterasyon=0;
	cout << "hata toleransini girin: \n";
	cin >> hata;
	cout << "araliklari girin: " << "\n";
	cout << "ilk aralik: \n";
	cin >> ilk_aralik;
	cout << "son aralik: \n";
	cin >> son_aralik;
	sinir_belirleme(katsayilar, hata, ilk_aralik, son_aralik,iterasyon);
	return 0;
}
