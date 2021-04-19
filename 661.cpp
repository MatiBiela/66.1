#include <fstream>
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

class file
{
        ifstream input;
        ofstream output;
        int suma;
        int a, liczba1, liczba2, liczba3; 
       
        public:
                file();
                ~file();
                void loop(); 
              //  void trojka();
};


file::file()
{
        input.open("trojki.txt"); 
        output.open("wyniki_trojki.txt");
        if (!input.good())
        {
                cerr << "Blad - pliku nie da sie otworzyc!\n";
                exit(1);
        }
}
int sum(int a) {
	int suma = 0;
	while (a > 0) {
		suma = suma + a%10;
		a=a/10; 
		
	}
	return(suma);
}

file::~file()
{
        input.close();
        output.close();
}


void file::loop()
{
        string data; 
        for(int i=0; i<=1000; i++)
        {
        	input >> liczba1 >> liczba2 >> liczba3;
            //scanf("%i %i %i\n" , &liczba1, &liczba2, &liczba3);
            if((sum(liczba1) + sum(liczba2)) == liczba3) {
            	printf("%i %i %i\n",  liczba1, liczba2, liczba3);
            	output << dec << input;
			}
        }
}






int main()
{
        file f;
        f.loop();

        return 0;
}
