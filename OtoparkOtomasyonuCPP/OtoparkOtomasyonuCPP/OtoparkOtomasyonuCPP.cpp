#include <iostream>
#include <string>
#include <cstdlib>
#include<windows.h>   
using namespace std;

int menuIndex;

bool loginAccepted = false;

string username;

struct User
{
    string username;
    string password;
};

bool Login(User user)
{
    cout << "Kullanici adiniz: ";
    cin >> user.username;
    cout << "Sifreniz: ";
    cin >> user.password;

    if ((user.username == "Admin") && (user.password == "Admin"))
    {
        loginAccepted = true;
        username = user.username;
    }
    else
    {
        loginAccepted = false;
    }

    return loginAccepted;
}

void WelcomeScreen(string username)
{
    cout << "Hos geldiniz, " << username;
}

void MenuScreen()
{
    cout << "1. Park Halindeki Araclarin Listesi" << endl;
    cout << "2. Park Halindeki Arac Cikisi" << endl;
    cout << "3. Yeni Arac Girisi" << endl;
    cout << "4. Cikis";
    cout << endl;
}

void ShowParkedCars(string matrix[][10], int rows, int cols)
{
    cout << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << i << ". Kat " << j << ". Numarali Park Yerinde " << matrix[i][j] << endl;
        }
        cout << endl;
    }
}

void AddCarToMatrix(string matrix[][10], int row, int col)
{
    string carPlate;
    string enterDate;
    int parkRow;
    int parkCol;
    bool rowFilled = true;

    cout << endl;
    cout << "Kacinci kat? " << endl;
    cin >> parkRow;

    for (int i = 0; i < col; i++)
    {
        if (matrix[parkRow][i]._Equal("..."))
        {
            cout << matrix[parkRow][i] << " ";
            rowFilled = false;
            break;
        }
        else
        {
            cout << matrix[parkRow][i] << " ";
            rowFilled = true;
        }
    }

    if (rowFilled == false)
    {
        cout << "Hangi numara? ";
        cin >> parkCol;

        if (matrix[parkRow][parkCol]._Equal("..."))
        {
            cout << "Plakayi girin: ";
            getline(cin >> ws, carPlate);
            cout << "Giris Tarihi ve Saati (gg.aa.yyyy, ss:dd): ";
            getline(cin, enterDate);


            matrix[parkRow][parkCol] = carPlate + " Park Halinde. Giris: " + enterDate;

            cout << endl;
        }
        else
        {
            cout << "Bu numarada bos yer yok! " << endl << endl;
        }
    }
    else
    {
        cout << "Bu katta bos yer yok! " << endl << endl;
    }
}

void RemoveCarToMatrix(string matrix[][10], int row, int col)
{
    cout << endl;
    cout << "Kacinci kat? ";
    cin >> row;
    cout << "Hangi numara? ";
    cin >> col;

    matrix[row][col] = "...";
}

int main()
{
    string carMatrix[5][10] = { {"59 EG 878 Park Halinde. Giris: 04.11.2023, 11:19", "a", "b", "c", "d","e", "f", "g", "h", "i"}, {"1", "...", "...", "...", "...", "...", "...", "...", "..." , "..."}, {"2", "...", "...", "...", "...", "...", "...", "...", "..." , "..."}, {"3", "...", "...", "...", "...", "...", "...", "...", "..." , "..."}, {"4", "...", "...", "...", "...", "...", "...", "...", "..." , "..."} };

    User user;

    int falseCount = 3;

    while (falseCount > 0)
    {
        cout << falseCount << " hakkiniz kaldi." << endl;
        Login(user);
        cout << endl;
        if (loginAccepted)
        {
            while (true)
            {
                WelcomeScreen(username);
                cout << endl;
                MenuScreen();
                cout << endl;
                cout << "Hangi islemi gerceklestirmek istiyorsunuz? ";
                cin >> menuIndex;

                switch (menuIndex)
                {
                case 1: ShowParkedCars(carMatrix, 4, 10);
                    break;
                case 2: RemoveCarToMatrix(carMatrix, 4, 10);
                    break;
                case 3: AddCarToMatrix(carMatrix, 4, 10);
                    break;
                case 4: system("CLS");
                    return 0;
                }
            }
        }
        else
        {
            cout << "Yanlis sifre girdiniz" << endl << endl;
            falseCount--;
        }
    }
    cout << "3 denemede de yanlis sifre girdiginiz icin sistem kendini kapatiyor.";
    Sleep(3000);
    system("CLS");
    return 0;
}