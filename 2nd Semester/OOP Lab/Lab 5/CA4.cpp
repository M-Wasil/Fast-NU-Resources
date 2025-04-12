#include <iostream>
using namespace std;

class Printer{
	string model;
	static string printMode;
	public:
		Printer(string m):model(m){}
		void getPrinterInfo() const{
//			printMode="Black & White";
			cout << "Printer Model: " << model<<", Mode: "<< printMode<<endl;
		}
		static void setPrintMode(string mode){
			printMode=mode;
		}
};
string Printer::printMode="Color ";

int main(){
	Printer p1("HP LaserJet");
	Printer p2("Canon Pixma");
	
	p1.getPrinterInfo();
	Printer::setPrintMode("Potrait");
	p2.getPrinterInfo();
	return 0;
}