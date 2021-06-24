
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdio.h>
using namespace std;

int main()
{
	string user_password = "";
	string real_password = "";
	fstream password;
	int choice = 0;
	password.open("password.txt", ios::in);
	password >> real_password;
	password.close();
	cout << "Enter the Password :- ";
	cin >> user_password;
	if (user_password == real_password)
	{

		while (choice != 7)
		{
			system("cls");
			cout << "*********Hospital Managment System********\n";
			cout << "* 1  For Available Doctor Info           *\n";
			cout << "* 2  For Doctor Appointment              *\n";
			cout << "* 3  Saving Staff Info                   *\n";
			cout << "* 4  Patient Appointment Menu            *\n";
			cout << "* 5  Checking Staff Info                 *\n";
			cout << "* 6  Change Password                     *\n";
			cout << "* 7  For Logout                          *\n";
			cout << "******************************************\n";
			cout << "Enter Your Choice :- ";
			cin >> choice;
			if (choice == 1)
			{
				system("cls");
				fstream doc_info;
				doc_info.open("doctor_info.txt", ios::in);

				char doc_infos;
				while (doc_info.get(doc_infos))
				{
					//cout << "1";
					cout << doc_infos;
				}
				doc_info.close();
				cout << "\n";
				cout << "Enter 1  to return homepage :- ";
				int k = 0;
				cin >> k;
				if (k == 1)
				{
					continue;
				}
			}
			else if (choice == 2)
			{
				system("cls");
				cout << "Press 1 For Dr Waqar\n";
				cout << "Press 2 For Dr. Baisla\n";
				cout << "Enter Your Choice :- ";
				int k = 0;
				cin >> k;
				struct appointment
				{
					string p_name = "";
					string ap_time = "";
					string p_age = "";
					string ap_no = "";
				};
				if (k == 1 || k == 2) {
					system("cls");
					struct appointment p1;
					cout << "Enter the Patient Name :-";
					cin >> p1.p_name;
					cout << "Enter the Appointment Time :-";
					cin >> p1.ap_time;
					cout << "Enter the Patient Age :-";
					cin >> p1.p_age;
					cout << "Enter the Appointment Number :-";
					cin >> p1.ap_no;
					fstream appointment;
					if (k == 1) {
						appointment.open("waqar_appointment.txt", ios::app | ios::ate);
					}
					else if (k == 2) {
						appointment.open("baisla_appointment.txt", ios::app | ios::ate);
					}
					appointment << "\n";
					appointment << "Name :- " << p1.p_name << "\n";
					appointment << "Time :- " << p1.ap_time << "\n";
					appointment << "Age :- " << p1.p_age << "\n";
					appointment << "Appointment No. :- " << p1.ap_no << "\n";
					cout << "Appointment Details Saved\n";
					cout << "Press 1 to return homepage :- ";
					cin >> k;
					if (k) {
						appointment.close();
						continue;
					}



				}
				else {
					cout << "Enter Valid option";
				}

			}

			else if (choice == 3)
			{
				system("cls");
				int k = 0;
				struct staff_details
				{
					string s_name = "";
					string s_age = "";
					string s_salary = "";
					string s_working = "";
				};
				struct staff_details p1;
				cout << "Enter  Name :-";
				cin >> p1.s_name;
				cout << "Enter  Age :-";
				cin >> p1.s_age;
				cout << "Enter Sallary :-";
				cin >> p1.s_salary;
				cout << "Enter Working Position :-";
				cin >> p1.s_working;
				fstream staff_info;
				staff_info.open("staff_info.txt", ios::app | ios::ate);
				staff_info << "\n";
				staff_info << "Name :- " << p1.s_name << "\n";
				staff_info << "Age :- " << p1.s_age << "\n";
				staff_info << "Sallary :- " << p1.s_salary << "\n";
				staff_info << "Working Postion :- " << p1.s_working << "\n";
				cout << "Your Info has been saved\n";
				cout << "Press 1 to return homepage :- ";
				cin >> k;
				if (k) {
					staff_info.close();
					continue;
				}





			}

			else if (choice == 4)
			{
				system("cls");
				int k = 0;
				cout << " 1-> For Doctor Waqar\n";
				cout << "2-> For Doctor Baisla\n";
				cout << "Enter Your Choice :- ";
				cin >> k;
				if (k == 1 || k == 2) {
					char apt_info;
					system("cls");
					fstream appoint_info;
					if (k == 1) {
						appoint_info.open("waqar_appointment.txt", ios::in);
					}
					if (k == 2) {
						appoint_info.open("baisla_appointment.txt", ios::in);
					}
					while (appoint_info.get(apt_info)) {
						cout << apt_info;

					}
					cout << "Press 1 to return homepage :- ";
					cin >> k;
					if (k) {
						appoint_info.close();
						continue;
					}

				}



			}
			else if (choice == 5)
			{
				system("cls");
				int k = 0;
				char st_info;
				fstream staff_info;
				staff_info.open("staff_info.txt", ios::in);
				while (staff_info.get(st_info)) {
					cout << st_info;

				}
				cout << "Press 1 to return homepage :- ";
				cin >> k;
				if (k) {
					staff_info.close();
					continue;
				}

			}
			else if (choice == 6)
			{
				system("cls");
				int k = 0;
				string pass;
				fstream password;
				password.open("password.txt", ios::out);
				cout << "Enter Your New Password :- ";
				cin >> pass;
				password << pass;
				cout << "Press 1 to return homepage :- ";
				cin >> k;
				if (k) {
					password.close();
					continue;
				}

			}
			else {
			cout << "Please Enter Valid Choice\n";

}


		}


	}
	else
	{
		cout << "Wrong Password";
	}

}

