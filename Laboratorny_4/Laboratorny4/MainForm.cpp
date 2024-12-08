#include "MainForm.h"
#include "AddUserForm.h"
#include "DataForm.h"






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
