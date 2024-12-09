#include "MainForm.h"
#include "AddUserForm.h"
#include "DataForm.h"
#include <string>


int Count = 0;
std::vector<std::string> names;
std::vector<int> tarifs;
std::vector<int> trafics;



int callback(void* NotUsed, int argc, char** argv, char** azColName) {
	/*String^ name;
	int tarif;
	int trafic;
*/
	/*for (int i = 0; i < argc; i++) {
		std::cout << azColName[i] << ": " << argv[i] << std::endl;
	}*/
	names.push_back(argv[1]);
	tarifs.push_back(atoi(argv[2]));
	trafics.push_back(atoi(argv[3]));
	Count++;
	return 0;
}



System::Void Laboratorny4::MainForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	

	String^ fileName;
	if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK) {
		fileName = openFileDialog1->FileName;
	}
	
	

	String^ informationFromFile;
	try {
		StreamReader^ file = File::OpenText(fileName);


		while ((informationFromFile = file->ReadLine()) != nullptr) {
			array<System::String^>^ StringArray = informationFromFile->Split('\t');

			listCustomer->Add(gcnew Customer(StringArray[0], Convert::ToInt32(Convert::ToString(StringArray[1])), Convert::ToInt32(Convert::ToString(StringArray[2]))));
		}
		file->Close();
		
		int comprasions = 0;
		int permutations = 0;
		int now_permutations = 0;
		int size = listCustomer->Count;
		do {
			now_permutations = 0;
			for (int i = 0; i < size - 1; i++) {

				if (listCustomer[i]->Name[0] > listCustomer[i + 1]->Name[0]) {
					Customer^ first_before = listCustomer[i];
					listCustomer[i] = listCustomer[i + 1];
					listCustomer[i + 1] = first_before;
					now_permutations++;
				}
				comprasions++;
			}
			permutations += now_permutations;

			size--;
		} while (now_permutations != 0);
	
		
		dataGridView1->DataSource = nullptr;
		dataGridView1->DataSource = listCustomer;
		
	}
	catch (Exception^ e) {
		MessageBox::Show("Ошибка", "Не удалось прочитать файл");
		
	}
	
	
}

System::Void Laboratorny4::MainForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	saveFileDialog1->Filter = "Text Files|*.txt|All Files|*.*";
	if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		StreamWriter^ sw = gcnew StreamWriter(saveFileDialog1->FileName);
		for (int i = 0; i < listCustomer->Count; i++) {
			sw->WriteLine(listCustomer[i]->Name + "\t" + Convert::ToInt32(listCustomer[i]->Cost) + "\t" + Convert::ToInt32(listCustomer[i]->Trafic));
		}
		
		sw->Close();
	}

}

System::Void Laboratorny4::MainForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	AddUserForm^ form = gcnew AddUserForm(this, listCustomer, 0);
	
	form->ShowDialog();
	int comprasions = 0;
	int permutations = 0;
	int now_permutations = 0;
	int size = listCustomer->Count;
	do {
		now_permutations = 0;
		for (int i = 0; i < size - 1; i++) {

			if (listCustomer[i]->Name[0] > listCustomer[i + 1]->Name[0]) {
				Customer^ first_before = listCustomer[i];
				listCustomer[i] = listCustomer[i + 1];
				listCustomer[i + 1] = first_before;
				now_permutations++;
			}
			comprasions++;
		}
		permutations += now_permutations;

		size--;
	} while (now_permutations != 0);
	dataGridView1->DataSource = nullptr;
	dataGridView1->DataSource = listCustomer;

}

System::Void Laboratorny4::MainForm::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
	AddUserForm^ form = gcnew AddUserForm(this, listCustomer);
	
	form->ShowDialog();
	int comprasions = 0;
	int permutations = 0;
	int now_permutations = 0;
	int size = listCustomer->Count;
	do {
		now_permutations = 0;
		for (int i = 0; i < size - 1; i++) {

			if (listCustomer[i]->Name[0] > listCustomer[i + 1]->Name[0]) {
				Customer^ first_before = listCustomer[i];
				listCustomer[i] = listCustomer[i + 1];
				listCustomer[i + 1] = first_before;
				now_permutations++;
			}
			comprasions++;
		}
		permutations += now_permutations;

		size--;
	} while (now_permutations != 0);
	dataGridView1->DataSource = nullptr;
	dataGridView1->DataSource = listCustomer;
}





System::Void Laboratorny4::MainForm::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Версия n", "Серьёзно, это кто-то читает?");
}

using namespace System::Runtime::InteropServices;
System::Void Laboratorny4::MainForm::button6_Click(System::Object^ sender, System::EventArgs^ e)
{
	sqlite3* DB;
	int exit = 0;

	/*String^ fileName;
	if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK) {
		fileName = openFileDialog1->FileName;
	}*/
	//std::string unmanaged = msclr::interop::marshal_as<std::string>(fileName);

	//const char*  f = unmanaged.c_str();
	//const char* f = (const char*)(Marshal::StringToHGlobalAnsi(fileName)).ToPointer();
	exit = sqlite3_open("db.db", &DB);

	if (exit) {
		MessageBox::Show("Ошибка", "Проверьте, что: \n- файл лежит в одной дирректории с проектом\n- файл называется 'db.db'");
	}
	std::string data("CALLBACK FUNCTION");

	std::string sql("SELECT * FROM Users;");

	sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);



	for (int i = 0; i < Count; i++) {
		listCustomer->Add(gcnew Customer(gcnew String(names[i].c_str()), tarifs[i], trafics[i]));
		//std::cout << names[i] << tarifs[i] << trafics[i] << std::endl;
	}
	sqlite3_close(DB);
	int comprasions = 0;
	int permutations = 0;
	int now_permutations = 0;
	int size = listCustomer->Count;
	do {
		now_permutations = 0;
		for (int i = 0; i < size - 1; i++) {

			if (listCustomer[i]->Name[0] > listCustomer[i + 1]->Name[0]) {
				Customer^ first_before = listCustomer[i];
				listCustomer[i] = listCustomer[i + 1];
				listCustomer[i + 1] = first_before;
				now_permutations++;
			}
			comprasions++;
		}
		permutations += now_permutations;

		size--;
	} while (now_permutations != 0);


	dataGridView1->DataSource = nullptr;
	dataGridView1->DataSource = listCustomer;

	Count = 0;
	names.clear();
	tarifs.clear();
	trafics.clear();
}


using System::Runtime::InteropServices::Marshal;

static std::string toStandardString(System::String^ string)
{
	System::IntPtr pointer = Marshal::StringToHGlobalAnsi(string);
	char* charPointer = reinterpret_cast<char*>(pointer.ToPointer());
	std::string returnString(charPointer, string->Length);
	Marshal::FreeHGlobal(pointer);

	return returnString;
}
System::Void Laboratorny4::MainForm::button7_Click(System::Object^ sender, System::EventArgs^ e)
{
	sqlite3* DB;
	int exit = 0;
	char* err_msg = 0;
	char* messaggeError;
	
	exit = sqlite3_open("db.db", &DB);
	if (exit) {
		MessageBox::Show("Ошибка", "Проверьте, что: \n- файл лежит в одной дирректории с проектом\n- файл называется 'db.db'");
	}
	char* sql = "DELETE FROM Users";
	exit = sqlite3_exec(DB, sql, 0, 0, &err_msg);
	for (int i = 0; i < listCustomer->Count; i++) {
		std::string sql("INSERT INTO Users VALUES(" + std::to_string(i) + ", '" + toStandardString(listCustomer[i]->Name) + "', " + std::to_string(listCustomer[i]->Cost) + ", " + std::to_string(listCustomer[i]->Trafic) + "); ");

		exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
		if (exit != SQLITE_OK) {
			std::cerr << "Error Insert" << std::endl;
			std::cerr << messaggeError << std::endl;
			sqlite3_free(messaggeError);
		}
		else {
			std::cout << "Records created Successfully!" << std::endl;
		}
			
	}
	sqlite3_close(DB);
}
