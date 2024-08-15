#include <iostream>
#include <cmath>
#include <string.h>
#include <string>
using namespace std;
int main()
{
    cout <<"Selamat datang di Program Formulasi Pengolahan Sampah"<< endl;
    cout << "Silahkan ketik jenis kota (kecil/sedang atau besar/metropolitan): ";
    string jenisKota;
    cin >> jenisKota;

    for (int i = 0; i < jenisKota.length();i++)
        jenisKota[i] = tolower(jenisKota[i]);
      while (jenisKota != "kecil" && jenisKota != "besar" && jenisKota != "metropolitan" && jenisKota != "sedang")
    {
        cout << "\nJenis kota tidak terdeteksi, silahkan input ulang: ";
        cin >> jenisKota;
    }
    cout << "\nSilahkan masukkan jumlah penduduk (dalam ribuan): ";
    float jumlahPenduduk;
    cin >> jumlahPenduduk;
    while (jumlahPenduduk <= 0)
    {
        cout << "input yang anda masukkan berjumlah 0 atau negatif, apakah ingin melanjutkannya? (y/n)" << endl;
        char decision;
        cin >> decision;
        decision = tolower(decision);
        while (decision != 'y' && decision != 'n')
        {
            cout << "Input tidak dikenal, silahkan coba lagi" << endl;
            cin >> decision;
            tolower(decision);
        }
        if (decision == 'y')
            break;
        else
        {
            cout << "Silahkan masukkan jumlah penduduk lagi: ";
            cin >> jumlahPenduduk;
        }
    }
    cout << "Silahkan masukkan berapa tahun lagi hasil formula ini akan digunakan : ";
    int jarakTahun;
    cin >> jarakTahun;
    while (jarakTahun <= 0)
    {
        cout << "input yang anda masukkan berjumlah 0 atau negatif, apakah ingin melanjutkannya? (y/n)" << endl;
        char decision1;
        cin >> decision1;
        decision1 = tolower(decision1);
        while (decision1 != 'y' && decision1 != 'n')
        {
            cout << "Input tidak dikenal, silahkan coba lagi" << endl;
            cin >> decision1;
            tolower(decision1);
        }
        if (decision1 == 'y')
            break;
        else
        {
            cout << "Silahkan masukkan jarak tahun lagi: ";
            cin >> jarakTahun;
        }
    }
    cout << "Silahkan masukkan laju pertumbuhan penduduk kota tersebut (dalam persen): ";
    float lajuTumbuh;
    cin >> lajuTumbuh;
        while (lajuTumbuh <= 0)
        {
            cout << "input yang anda masukkan berjumlah 0 atau negatif, apakah ingin melanjutkannya? (y/n)" << endl;
            char decision2;
            cin >> decision2;
            decision2 = tolower(decision2);
            while (decision2 != 'y' && decision2 != 'n')
            {
                cout << "Input tidak dikenal, silahkan coba lagi" << endl;
                cin >> decision2;
                tolower(decision2);
            }
            if (decision2 == 'y')
                break;
            else
            {
                cout << "Silahkan masukkan laju pertumbuhan lagi: ";
                cin >> lajuTumbuh;
            }
        }
    jumlahPenduduk = jumlahPenduduk  * 1000 * pow((1 + lajuTumbuh/100), jarakTahun);
    jumlahPenduduk = ceil(double(jumlahPenduduk));
    string jumlahPendudukSTR = to_string(jumlahPenduduk);
    cout << "Jumlah penduduk dalam jarak waktu " << jarakTahun << " tahun adalah " << jumlahPendudukSTR<< " jiwa" << endl;
    
    if (jenisKota == "kecil" or jenisKota == "sedang")
    {
        float print[12];
        float multiplier[12] = {5.0,1.083,5.0,1.132,2.5,5.415,2.75,1.132,2.071,1.966,7.116,8.537};
        int power[12] = {-4,-4,-4,-5,-6,-5,-4,-4,-5,-5,-5,-6};
        string whatosay[12] =
        {   "Gerobak sampah",
            "Truk sampah",
            "Tempat Pembuangan Sampah 3R",
            "Luas Tempat Pembuangan Akhir",
            "Biaya investasi Gerobak sampah",
            "Biaya investasi Truk sampah",
            "Biaya investasi Tempat Pembuangan Sampah 3R",
            "Biaya investasi Tempat Pembuangan Akhir",
            "Biaya rawat Gerobak sampah",
            "Biaya rawat Truk sampah",
            "Biaya rawat Tempat Pembuangan Sampah 3R",
            "Biaya rawat Tempat Pembuangan Akhir"
        };
        string satuan[12] =
        {
            "unit   ",
            "unit   ",
            "unit   ",
            "hektare",
            "milyar",
            "milyar",
            "milyar",
            "milyar",
            "milyar",
            "milyar",
            "milyar",
            "milyar",
        };
        int j = 0;
        while (j < 12 )
        { 
            if (j < 4 )
            {
                print[j] = jumlahPenduduk * multiplier[j] * pow(10, power[j]);
                print[j] = ceil(double(print[j]));
                cout << whatosay[j] << " yang diperlukan sebanyak " << print[j] << " " << satuan[j] << endl;
                j++;
            }
            else if (j == 7)
            {
                print[j] = jumlahPenduduk * multiplier[j] * pow(10, power[j]) + 5;
                cout << whatosay[j] << " yang diperlukan sebanyak " << print[j] << " " << satuan[j] << endl;
                j++;
            }
            else
            {
                print[j] = jumlahPenduduk * multiplier[j] * pow(10, power[j]);
                cout << whatosay[j] << " yang diperlukan sebanyak " << print[j] << " " << satuan[j] << endl;
                j++;
            }
        }
        cout << "\nTABEL FORMULASI"<< endl;
        cout << endl;
        cout << "Infrastruktur \t\t\t\t\t | Satuan \t | Hasil Hitung"<<endl;
        int k = 0;
        while (k < 12)
        {
            if (whatosay[k].length()<= 15)
            {
                cout << whatosay[k] << "\t\t\t\t\t | " << satuan[k] << "\t | " << print[k] << endl;
            }
            else if (whatosay[k].length()  > 15 && whatosay[k].length() <26)
            {
                cout << whatosay[k] << "\t\t\t\t | " << satuan[k] << "\t | " << print[k] << endl;
            }
            else if (whatosay[k].length() >= 26 && whatosay[k].length() <= 33)
            {
                cout << whatosay[k] << "\t\t\t | " << satuan[k] << "\t | " << print[k] << endl;
            }
            else if (whatosay[k].length() > 33 && whatosay[k].length() < 42)
            {
                cout << whatosay[k] << "\t\t | " << satuan[k] << "\t | " << print[k] << endl;
            }
            else if (whatosay[k].length() > 42)
            {
                cout << whatosay[k] << "\t | " << satuan[k] << "\t | " << print[k] << endl;
            }
            k++;
        }
    }else
    {
        float print[15];
        float multiplier[15] = { 5.0,1.083,2.5,1.736,1.132,2.5,5.415,1.375,1.909,1.132,2.071,1.966,3.558,1.245,8.537 };
        int power[15] = { -4,-4,-4,-5,-5,-6,-5,-4,-4,-4,-5,-5,-5,-5,-6 };
        string whatosay[15] =
        {   "Gerobak sampah",
            "Truk sampah",
            "Tempat Pembuangan Sampah 3R",
            "Fasilitas Pengolahan Sampah Akhir",
            "Luas Tempat Pembuangan Akhir",
            "Biaya investasi Gerobak sampah",
            "Biaya investasi Truk sampah",
            "Biaya investasi Tempat Pembuangan Sampah 3R",
            "Biaya investasi Tempat Pembuangan Sampah Terpadu",
            "Biaya investasi Tempat Pembuangan Akhir",
            "Biaya rawat Gerobak sampah",
            "Biaya rawat Truk sampah",
            "Biaya rawat Tempat Pembuangan Sampah 3R",
            "Biaya rawat Tempat Pembuangan Sampah Terpadu",
            "Biaya rawat Tempat Pembuangan Akhir"
        };
        string satuan[15] =
        {
            "unit   ",
            "unit   ",
            "unit   ",
            "unit   ",
            "hektare",
            "milyar",
            "milyar",
            "milyar",
            "milyar",
            "milyar",
            "milyar",
            "milyar",
            "milyar",
            "milyar",
            "milyar",
        };
        int j = 0;
        while (j < 15)
        {
            if (j < 5)
            {
                print[j] = jumlahPenduduk * multiplier[j] * pow(10, power[j]);
                print[j] = ceil(double(print[j]));
                cout << whatosay[j] << " yang diperlukan sebanyak " << print[j] << " " << satuan[j] << endl;
                j++;
            }
            else 
                if (j == 9)
            {
                print[j] = jumlahPenduduk * multiplier[j] * pow(10, power[j]) + 5;
                cout << whatosay[j] << " yang diperlukan sebanyak " << print[j] << " " << satuan[j] << endl;
                j++;
            }
                else
            {
                print[j] = jumlahPenduduk * multiplier[j] * pow(10, power[j]);
                cout << whatosay[j] << " yang diperlukan sebanyak " << print[j] << " " << satuan[j] << endl;
                j++;
            }
        }
        cout << "\nTABEL FORMULASI" << endl;
        cout << endl;
        cout << "Infrastruktur \t\t\t\t\t | Satuan \t | Hasil Hitung" << endl;
        int k = 0;
        while (k < 15)
        {
            if (whatosay[k].length() <= 15)
            {
                cout << whatosay[k] << "\t\t\t\t\t | " << satuan[k] << "\t | " << print[k] << endl;

            }
            else if (whatosay[k].length() > 15 && whatosay[k].length() < 26)
            {
                cout << whatosay[k] << "\t\t\t\t | " << satuan[k] << "\t | " << print[k] << endl;

            }
            else if (whatosay[k].length() >= 26 && whatosay[k].length() <= 32)
            {
                cout << whatosay[k] << "\t\t\t | " << satuan[k] << "\t | " << print[k] << endl;

            }
            else if (whatosay[k].length() > 32 && whatosay[k].length() < 42)
            {
                cout << whatosay[k] << "\t\t | " << satuan[k] << "\t | " << print[k] << endl;

            }
            else if (whatosay[k].length() > 42 && whatosay[k].length() < 48)
            {
                cout << whatosay[k] << "\t | " << satuan[k] << "\t | " << print[k] << endl;

            }
            else if (whatosay[k].length() >= 48)
            {
                cout << whatosay[k] << " | " << satuan[k] << "\t | " << print[k] << endl;
            }
            k++;
        }
    }
    string wk;
    cin >> wk;
    return 0;
}
