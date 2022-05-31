#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

class OnlineForm {
public:
	bool CorrectForm, Payment;
	int TotalPrice, NotAllowedID;
	int ChosenIDs[3];
	OnlineForm() {
		NotAllowedID = 2;
		CorrectForm = false;
		Payment = false;
		TotalPrice = 0;
		ChosenIDs[0] = 0;
		ChosenIDs[1] = 0;
		ChosenIDs[2] = 0;
	}
	void ShowChosen();
};

void OnlineForm::ShowChosen() {
	cout << "Chosen items:" << endl;
	for (int i = 0; i < 3; i++) {
		if (ChosenIDs[i] != 0) cout << ChosenIDs[i] << " ";
	}
}

class Client {
	friend class OnlineForm;
public:
	void CreateOF(OnlineForm& form);
};

void Client::CreateOF(OnlineForm & form) {
	int k;
	cout << "Type the id you wanna buy" << endl;
	cin >> k;
	if (k != form.NotAllowedID && form.ChosenIDs[0] == 0) form.ChosenIDs[0] = k;
	else if (k != form.NotAllowedID && form.ChosenIDs[1] == 0) form.ChosenIDs[1] = k;
	else if (k != form.NotAllowedID && form.ChosenIDs[2] == 0) form.ChosenIDs[2] = k;
}

class Catalog {
public:
	int id[3],price[3];
	string type[3];
	void showCatalog();
	Catalog() {
		id[0] = 1;
		id[1] = 2;
		id[2] = 3;
		price[0] = 500;
		price[1] = 300;
		price[2] = 700;
		type[0] = "CPU";
		type[1] = "GPU";
		type[2] = "Motherboard";
	}
};

void Catalog::showCatalog() {

	cout << "~~id~~|~~price~~|~~~~type~~~~" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "  " << id[i] << "       " << price[i] << "    " << type[i] << endl;
	}
}

class Salesman {

};



int main() {
	Client cust;
	Catalog cata;
	Salesman sale;
	OnlineForm form;

	while (true) {
		system("cls");
		cout << "Choose the role:" << endl;
		cout << "1. Client" << endl;
		cout << "2. Salesman" << endl;
		cout << "3. Exit" << endl;
		int chosenRole; cin >> chosenRole;
		
		//Client
		if (chosenRole == 1) {

			system("cls");

			while (true) {
				system("cls");
				cout << "1. Check catalog" << endl;
				cout << "2. Filter catalog" << endl;
				cout << "3. Create online form" << endl;
				cout << "4. Make payment" << endl;
				cout << "5. Exit" << endl;
				int ClientChose;
				cin >> ClientChose;
				
				//CheckCatalog
				if (ClientChose == 1) {
					system("cls");
					cata.showCatalog();
					system("pause");
					continue;
				}
				//FilterCatalog
				if (ClientChose == 2) {
					system("cls");
					cout << "Choose the filter" << endl;
					cout << "1. CPU" << endl;
					cout << "2. GPU" << endl;
					cout << "3. Motherboard" << endl;
					int ChosenFilter; cin >> ChosenFilter;
					
					if (ChosenFilter == 1) {
						system("cls");
						cout << "~~id~~|~~price~~|~~~~type~~~~" << endl;
						for (int i = 0; i < 3; i++) {
							if (cata.type[i] == "CPU") cout << "  " << cata.id[i] << "       " << cata.price[i] << "    " << cata.type[i] << endl;
						}
						system("pause");
					}
					if (ChosenFilter == 2) {
						system("cls");
						cout << "~~id~~|~~price~~|~~~~type~~~~" << endl;
						for (int i = 0; i < 3; i++) {
							if (cata.type[i] == "GPU") cout << "  " << cata.id[i] << "       " << cata.price[i] << "    " << cata.type[i] << endl;
						}
						system("pause");
					}
					if (ChosenFilter == 3) {
						system("cls");
						cout << "~~id~~|~~price~~|~~~~type~~~~" << endl;
						for (int i = 0; i < 3; i++) {
							if (cata.type[i] == "Motherboard") cout << "  " << cata.id[i] << "       " << cata.price[i] << "    " << cata.type[i] << endl;
						}
						system("pause");
					}
					continue;

				}
				//CreateOnlineForm
				if (ClientChose == 3) {
					system("cls");
					
					continue;
				}
				//MakePayment
				if (ClientChose == 4) {
					system("cls");
					continue;
				}
				//Exit
				if (ClientChose == 5) break;

			}
		}

		if (chosenRole == 2) {
			system("cls");
			while (true) {
				system("cls");
				cout << "1. Check form" << endl;
				cout<<"2. Check"
			}
		}

		if (chosenRole == 3) break;

	}


	return 0;
}