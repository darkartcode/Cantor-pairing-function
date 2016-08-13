/*
	-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~--~-~-~-~--~-
	Cantor pairing function
	C++ Code implementation by Darkart
	-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~--~-~-~-~--~-
	All information was taken just from Wikipedia : 
	https://en.wikipedia.org/wiki/Pairing_function
	-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~--~-~-~-~--~-
	Encoding formula : 
	z = ((k1+k2)*(k1+k2+1)/2)+k2 or
	z = 0.5(k1+k2)(k1+k2+1)+k2
	-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~--~-~-~-~--~-
	Decoding formula :
	w = floor(((sqrt((z*8)+1))-1)/2)
	t = (w*(w+1))/2
	k2 = z - t
	k1 = w - k2
	-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~--~-~-~-~--~-
*/

#include <iostream>
#include <cmath>

using namespace std;

struct ints{
	int k1, k2;
};

int cantor_enc(int k1, int k2){
	int z;
	if(k1 >0 && k2 >0){
		z = ((k1+k2)*(k1+k2+1)/2) + k2;
	}else{
		cout << "Cantor pairing function operates only with natural numbers!" << endl;
	}
	return z;
}

ints cantor_dec(int z){
	
	int w, t;
	
	ints k;
	
	w = floor(((sqrt((z*8)+1))-1)/2);
	t = (w*(w+1))/2;
	k.k2 = z - t;
	k.k1 = w - k.k2;
	
	return k;
}

int main(){
	
	int k1 = 29;
	int k2 = 13;
	int z = cantor_enc(k1, k2);
	cout << "Cantor encoded : z = " << z << endl;
	ints k = cantor_dec(z);
	cout << "Cantor decoded : k1 = " << k.k1 << "; k2 = " << k.k2 << endl;
	
	return 0;
}




