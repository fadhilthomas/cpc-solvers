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

        if(name == "LBHB41K") //Setiap usia kelipatan 5, tingkat keganasan virus LBHB41K berkurang satu
		{
			if(age%5 == 0)
			{
				malignancy--;
			}
		}
		else if(name == "4L4Y") //Tingkat keganasan virus 4L4Y bertambah dua, setiap hari
		{
			malignancy += 2;
		}
		else if(name == "B41K") // Setiap usia kelipatan 100, tingkat keganasan virus B41K bertambah satu
		{
			if(age%100 == 0)
			{
				malignancy++;
			}
		}
		else if(name == "ABA81L")
		{
			if(age < 100) //Usia dibawah 100 dan kelipatan 4, tingkat keganasan ABA81L bertambah tujuh
			{
				if(age%4 == 0) malignancy += 7;
			}
			else if(age > 100) //Usia diatas 100 dan kelipatan 10, tingkat keganasan ABA81L berkurang setengah
			{
				if(age%10 == 0) malignancy /= 2;
			}
		}
		else
		{
			if(name != "M4G3R" && name != "ABA81L") //M4G3R dan ABA81L tidak terkena LebayEffect
			{
				if(age >= 200) //LebayEffect terjadi apabila usia 200 atau lebih dan kelipatan lima, tingkat keganasan bertambah dua
				{
					if(age%5 == 0) malignancy += 2;
				}
				else if(age%3 == 0) //Selain virus 4L4Y, B41K, M4G3R, LBHB41K, ABA81L, dan usia dibawah 200, tingkat keganasan bertambah satu setiap usia kelipatan tiga.
		        {
		            malignancy++;
		        }
			}
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
    int numberOfVirus, numberOfDay;

    string virusName;
    int virusAge, virusMalignancy;

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
