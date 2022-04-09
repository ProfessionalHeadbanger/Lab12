//Дан пофамильный список учителей школы, которые преподают математику, информатику,
//физику, химию и биологию, с указанием их недельной нагрузки по каждому из предметов.
//Вывести учителей, имеющих минимальную нагрузку среди преподающих один предмет, затем
//среди преподающих два предмета и т.д.до пяти.

#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

struct teacher
{
    string surname;
    vector <string> subject;
    vector <int> weekly_load;
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector <teacher> teachers;
    int number_teachers;
    cout << "Введите количество учителей в школе: "; cin >> number_teachers;
    teachers.resize(number_teachers);

    cout << endl << "Заполнение списка учителей " << endl;
    for (int i = 0; i < number_teachers; i++)
    {
        cout << "Учитель " << i + 1 << endl;
        cout << "Введите фамилию: "; cin >> teachers[i].surname;
        int number_subjects;
        cout << "Введите количество предметов (максимально - 5): "; cin >> number_subjects;
        teachers[i].subject.resize(number_subjects);
        teachers[i].weekly_load.resize(number_subjects);
        for (int j = 0; j < number_subjects; j++)
        {
            cout << "Введите " << j + 1 << " предмет и недельную нагрузку: ";
            cin >> teachers[i].subject[j] >> teachers[i].weekly_load[j];
        }
        cout << endl;
    }

    vector<vector<int>> sum_weekly_load;
    sum_weekly_load.resize(5);
    for (int i = 0; i < number_teachers; i++)
    {
        int number_subjects = teachers[i].weekly_load.size();
        sum_weekly_load[number_subjects - 1].push_back(accumulate(teachers[i].weekly_load.begin(), teachers[i].weekly_load.end(), 0));
    }

    /*for (int i = 0; i < sum_weekly_load.size(); i++)
    {
        for (int j = 0; j < sum_weekly_load[i].size(); j++)
        {
            cout << sum_weekly_load[i][j] << " ";
        }
        cout << endl;
    }*/

    for (int i = 0; i < 5; i++)
    {
        vector<int>::iterator minimum_el;
        minimum_el = min_element(sum_weekly_load[i].begin(), sum_weekly_load[i].end());
        int minimum = static_cast<int>(*minimum_el);
        for (int j = 0; j < number_teachers; j++)
        {
            if (teachers[j].subject.size() == (i + 1))
            {
                if (accumulate(teachers[j].weekly_load.begin(), teachers[i].weekly_load.end(), 0) == minimum)
                {
                    cout << i + 1 << "предмет: " << teachers[j].surname << endl;
                }
            }
        }
    }
}
