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
    int malignancy, age, min, max;
    bool alive = true;
    
public:
    Virus(string _name, int _malignancy, int _age) //Constructor
    {
    	name = _name;
    	malignancy = _malignancy;
    	age = _age;
    	if(name == "DARGOMBES") //Tingkat keganasan virus DARGOMBES [0,9999]
		{
			min = 0;
			max = 9999;
		}
		else if(name == "DEWARUCI") //Tingkat keganasan virus DEWARUCI [-9999,0]
		{
			min = -9999;
			max = 0;
		}
		else if(name == "DOBBYTHEHOUSEELF" || name == "DOBBY") //Tingkat keganasan virus DOBBYTHEHOUSEELF [-666,666]
		{
			min = -666;
			max = 666;
		}
		else //Tingkat keganasan virus selain diatas [0,99]
		{
			min = 0;
			max = 99;
		}
    };

    void Update() //Menampilkan output
    {
        age++;
        
        if(alive)
        {
        	//Virus mati di usia 365 kecuali dengan nama yang diawali huruf D dan bukan virus DOBBY/DOBBYTHEHOUSEELF, virus mati tidak ditampilkan
        	if((name == "DOBBY" || name == "DOBBYTHEHOUSEELF") && age > 364)
			{
        		alive = false;
			}
        	else if(name.substr(0,1) != "D" && age > 364 )
			{
				alive = false;
			}
		}
        
        if(alive) //Virus mati di usia 365 kecuali dengan nama yang diawali huruf D, virus mati tidak ditampilkan
		{
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
			else if(name.find("ABA81L") != string::npos)
			{
				if(name == "ABA81LV2") //Tingkat keganasan ABA81LV2 bertambah satu setiap hari
				{
					malignancy++;
				}
				if(age < 100) //Usia dibawah 100 dan kelipatan 4, tingkat keganasan ABA81L dan ABA81LV2 bertambah tujuh
				{
					if(age%4 == 0) malignancy += 7;
				}
				else if(age > 100) //Usia diatas 100 dan kelipatan 10, tingkat keganasan ABA81L dan ABA81LV2 berkurang setengah
				{
					if(age%10 == 0) malignancy /= 2;
				}
			}
			else if(name == "DARGOMBES") //Tingkat keganasan DARGOMBES bertambah tiga setiap hari
			{
				malignancy += 3;
			}
			else if(name == "DEWARUCI") //Tingkat keganasan DEWARUCI berkurang lima setiap usia kelipatan dua
			{
				if(age%2 == 0) malignancy -= 5;
			}
			else if(name == "DOBBYTHEHOUSEELF" || name == "DOBBY")
			{
				if (age >= 300 && malignancy > 0) malignancy /= 2;
				else if (age >= 200 && malignancy > 300) malignancy -= 15;
				else if (age >= 110 && malignancy < -600) malignancy /= 2;
				else if (age >= 100 && malignancy < -600) malignancy += 15;
				else if (age >= 100 && malignancy < 0) malignancy += 7;
				else if (malignancy <= 0) malignancy += 2;
				else if (malignancy > 0) malignancy -= 3;
			}
			else
			{
				if(name != "M4G3R" && name != "ABA81L" && name != "ABA81LV2"&& name != "DARGOMBES" && name != "DEWARUCI" && name != "DOBBYTHEHOUSEELF" && name != "DOBBY") //M4G3R, ABA81L, DARGOMBES, DEWARUCI, DOBBYTHEHOUSEELF, DOBBY tidak terkena LebayEffect
				{
					if(age >= 200) //LebayEffect terjadi apabila usia 200 atau lebih dan kelipatan lima, tingkat keganasan bertambah dua
					{
						if(age%5 == 0) malignancy += 2;
					}
					else if(age%3 == 0) //Selain virus M4G3R, ABA81L, DARGOMBES, DEWARUCI, DOBBYTHEHOUSEELF, DOBBY, dan usia dibawah 200, tingkat keganasan bertambah satu setiap usia kelipatan tiga.
			        {
			            malignancy++;
			        }
				}
			}
			
			//Tingkat keganasan tidak boleh melebihi batas
			if(malignancy < min)
			{
				malignancy = min;
			}
			else if(malignancy > max)
			{
				malignancy = max;
			}
	
	        cout << "Nama: " << name << "; Usia: " << age << "; Tingkat Keganasan: " << malignancy << endl;
		}
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
