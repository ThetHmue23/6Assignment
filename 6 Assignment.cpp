#include <iostream>
using namespace std;

class Wave {
public:
	int user_id = 0;
	int current_user_amount = 0;
	int allocate = 0;
	string user_name[100];
	long long uphone_no[100];
	int upin_no[100];
	int uamount[100];

	
	int wave_service();
	int creat_account();
	int account_login();
	int money_exchange();
	int quit();
	int allinfo();
	int acc_to_acc();
	int to_withdraw();
	int to_update();
	int transfer_section(int user_id,int receiver_id, int transfer_amount);
	int check_rusername(string ruser_name);
};

int Wave::wave_service() {
	int number = 0;
	while (true) {
		cout << "Welcome to WAVE Program!" << endl;
		cout << "Creating Account press1:" << endl;
		cout << "Account login press2:" << endl;
		cout << "Quit the program press3:" << endl;
		cin >> number;
		if (number == 1) {
			creat_account();
		}
		else if (number == 2) {
			account_login();
		}
		else {
			quit();
		}
	}

	return 0;
}

int Wave::creat_account() {
	string name;
	int  pin_no, amount = 0;
	long long phone_no;

	cout << "This is account creating section:" << endl;
	cout << "Enter username:";
	cin >> name;
	cout << "Enter phone number:";
	cin >> phone_no;
	cout << "Enter pin number:";
	cin >> pin_no;
	cout << "Enter amount you want to put in your accont:";
	cin >> amount;

	user_name[allocate] = name;
	uphone_no[allocate] = phone_no;
	upin_no[allocate] = pin_no;
	uamount[allocate] = amount;

	cout << "Account Creating is finished!" << endl;
	allinfo();
	allocate++;

	return 0;
}

int Wave::account_login() {
	string luser_name;
	int lpin_no;
	cout << "Enter username:" << endl;
	cin >> luser_name;
	cout << "Enter pin number:" << endl;
	cin >> lpin_no;

	for (int i = 0; i <= allocate; i++) {
		if (luser_name == user_name[i] && lpin_no == upin_no[i]) {
			user_id = i;
			current_user_amount = uamount[i];
			cout << "Login Success!" << endl;
			money_exchange();
		}
	}

	return 0;
}


int Wave::money_exchange() {
	int option = 0;
	cout << "To transfer account to account prees 1:" << endl;
	cout << "To withdaw money press 2:" << endl;
	cout << "To update money press 3:" << endl;
	cout << "To quit press 4:" << endl;
	cin >> option;
	if (option == 1) {
		acc_to_acc();
	}
	else if (option == 2) {
		to_withdraw();
	}
	else if (option == 3) {
		to_update();
	}
	else if (option == 4) {
		wave_service();
	}
	else {
		cout << "Invalid option!" << endl;
		money_exchange();
	}

	return 0;
}
int Wave::acc_to_acc() {
	string ruser_name;
	int transfer_amount = 0;
	cout << "Enter receiver's username:";
	cin >> ruser_name;
	int receiver_id=check_rusername(ruser_name);
	if (receiver_id) {
		while (receiver_id) {
			cout << "Enter transfer amount:";
			cin >> transfer_amount;
			if (transfer_amount >= current_user_amount) {
				cout << "Your current is not enough money to transfer!" << endl;
				continue;
			}
			else {
				transfer_section(user_id,receiver_id,transfer_amount);
				allinfo();
				wave_service();
			}

		}
	}

	return 0;
}

int Wave::transfer_section(int user_id, int receiver_id, int transfer_amount) {
	uamount[user_id]=uamount[user_id] - transfer_amount;
	uamount[receiver_id] = uamount[receiver_id] + transfer_amount;

	cout << "Money transfered to " << user_name[receiver_id] << endl;
	cout << "Amount :" << transfer_amount << endl;

	return 0;
}


int Wave::check_rusername(string ruser_name) {

	for (int i = 0; i <= allocate; i++) {
		if (ruser_name == user_name[i]) {
			return i;
		}
	}
}

int Wave::to_withdraw() {
	int withdraw_amount;
	cout << "Enter amount to withdraw:";
	cin >> withdraw_amount;
	if (uamount[user_id] - 500 > withdraw_amount) {
		uamount[user_id] = uamount[user_id] - withdraw_amount;
		cout << "Username:" << user_name[user_id] << " Amount:" << uamount[user_id] << endl;
		money_exchange();
	}
	else {
		cout << "Invalid amount to withdraw!" << endl;
		money_exchange();
	}

	return 0;
}

int Wave::to_update() {
	int update_amount = 0;
	cout << "Enter amount to update for " << user_name[user_id];
	cin >> update_amount;
	uamount[user_id] = uamount[user_id] + update_amount;

	cout << "Username :" << user_name[user_id] << " Amount :" << update_amount << " is updated: " << endl;
	allinfo();
	money_exchange();
	return 0;
}

int Wave ::quit() {
	cout << "Thank You, Bye Bye!" << endl;
	exit(1);

	return 0;
}

int Wave::allinfo() {

	cout << "Username:" << endl;
	for (int i = 0; i <= allocate; i++) {
		cout << " :" << user_name[i] << "\n" << endl;
	}
	
	cout << "Phone number:" << endl;
	for (int i = 0; i <= allocate; i++) {
		cout << " :" << uphone_no[i] << "\n" << endl;
	}
	
	cout << "Amount:" << endl;
	for (int i = 0; i <= allocate; i++) {
		cout << " :" << uamount[i] << "\n" << endl;
	}
	return 0;
}


int main() {
	Wave wsystem;
	wsystem.wave_service();


	return 0;
}
