#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>

int gcd(int a, int b) //Berechnung des ggT
{
	int x,y,z;
	if(a+b==0){	//O Abfangen
		return 0;
	}else if(a<b) //Tauschen wen a < b
		{
		x = b;
		y = a;
		}else{
		x = a;
		y = b;
		}

	z = x % y; 
	x = y;
	
	if(z > 0) //Rekursiv bis z=0
	{
		y = z;
		gcd(x,y);
	}else{
		return x;	
	}
}


TEST_CASE("describe_gcd", "[gcd]")
{
	REQUIRE(gcd(2,4) == 2);
	REQUIRE(gcd(6,9) == 3);
	REQUIRE(gcd(3,7) == 1);
}

int qs(int a) //Quersumme
{	
	int result = 0;
	int safe = 0;
	while(a > 0)
	{
	safe = a % 10;	//Wert der letzten Stelle ermitteln
	result = result + safe;
	a = a - safe;
	a = a / 10; //letzte Stelle "verschieben"
	}
	return result;
}


TEST_CASE("describe_qs", "[qs]")
{
	REQUIRE(qs(12) == 3);
	REQUIRE(qs(123) == 6);
	REQUIRE(qs(555)	== 15);
	REQUIRE(qs(115763) == 23);
}

long sumMultiples(int a)
{
	int result = 0;
	for(int i = 0; i <= a; i++){ //schleife für alle i bis eingabe a
		if(i % 3 == 0 || i % 5 == 0){ //modulo test für 3 und 5
			result = result + i;
		}
	}
	return result;
}

TEST_CASE("describe_sumMultiples", "[sumMultiples]")
{
	REQUIRE(sumMultiples(1000) == 234168);	
}

double fract(double a) //nachkommastrellen ausgeben
{
	double safe = floor(a); //runden auf vorkomma von a
	double result = a - safe; //vorkomma abziehen
	return result;
}

TEST_CASE("describe_fract", "[fract]")
{
	REQUIRE(fract(14.24) == Approx(0.24));
	REQUIRE(fract(2.3) == Approx(0.3));
}

double cylinderVolume(double h, double r)
{	
	int v=0;
	v=h*r*r*M_PI; //formel für zylinder
	return v;
}

TEST_CASE("describe_cylinderVolume", "[cylinderVolume]")
{
	REQUIRE(cylinderVolume(2, 2) == Approx(25.0));
	REQUIRE(cylinderVolume(5, 3) == Approx(141.0));
}

double cylinderSurface(double h, double r)
{	
	int surface=0; 
	surface=2*M_PI*r*r+2*M_PI*r*h; //formel für flächeninhalt
	return surface;
}

TEST_CASE("describe_cylinderSurface", "[cylinderSurface]")
{
	REQUIRE(cylinderSurface(2, 2) == Approx(50.0));
	REQUIRE(cylinderSurface(5, 3) == Approx(150.0));
}

double mileToKilometer(double a)
{
	int Kilometer=0;
	Kilometer=a/0.62137;
	return Kilometer;
}

TEST_CASE("describe_mileToKilometer", "[mileToKilometer]")
{
	REQUIRE(mileToKilometer(10.0) == Approx(16.0));
}


int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}


