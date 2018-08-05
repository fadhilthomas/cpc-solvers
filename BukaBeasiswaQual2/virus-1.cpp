#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Virus
{
private:
	//Atribut virus
    string name;
    int malignancy, age;
    
public:
    Virus(string _name, int _malignancy, int _age) //Constructor
    {
    	name = _name;
    	malignancy = _malignancy;
    	age = _age;
    };

    void Update() //Menampilkan output
    {
        age++;

        if(age%3 == 0) //Tingkat keganasan bertambah satu setiap usia virus kelipatan tiga
        {
            malignancy++;
        }

		//Tingkat keganasan antara 0 sampai 99
        if(malignancy < 0) 
        {
            malignancy = 0;
        }
        else if(malignancy > 99)
        {
            malignancy = 99;
        }

        cout << "Nama: " << name << "; Usia: " << age << "; Tingkat Keganasan: " << malignancy << endl;
    };
};

int main()
{
    int numberOfVirus, numberOfDay, virusAge, virusMalignancy;
    string virusName;
    vector<Virus*> viruses;

	//Input jumlah virus dan hari dari user
    cin >> numberOfVirus;
    cin >> numberOfDay;

    for(int i=0; i<numberOfVirus; i++) //Menginputkan atribut virus
    {
        cin >> virusName;
        cin >> virusAge;
        cin >> virusMalignancy;

        Virus *virus = new Virus(virusName, virusMalignancy, virusAge);
        viruses.push_back(virus);
    }

    for(int day=1; day<=numberOfDay; day++) //Menampilkan ouput laporan harian
    {
        cout << "Hari #" << day << endl;
        for(int i=0; i<(int)viruses.size(); i++)
        {
            viruses[i]->Update();
        }
    }
}
