#include"pch.h"
#include"iostream"
#include"Rectangulo.h"
using namespace System;
using namespace std;

int main(){
	Rectangulo<int> rec(10, 10);
	cout << "El area de rectangulo es: " << rec.area();
}