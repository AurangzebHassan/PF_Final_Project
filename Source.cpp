#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>
using namespace std;



struct Item
{
    char Name[15];

    char Item_ID[8];

    char Category[15];

    int Item_Count;

    char Allocated_to[100];
};

struct App
{
    Item i[10];

}app;




void Read_from_Text_File(fstream &);

void Read_from_Binary_File(fstream &);

void Write_to_Binary_File(fstream &);

void View_all_Inventory_Items();

int Search_Inventory_Item();

void Edit_Inventory_Item(fstream &);

void Add_Inventory_Item(fstream &);

void Delete_Inventory_Item(fstream &f);

void Assign_Inventory_Item(fstream &f);

void Retrieve_Inventory_Item(fstream &f);

void View_Specific_Borrowers();




int main()
{
    char try_again, menu_choice;

    fstream f;

    do
    {
        // Read_from_Text_File(f);
        // Write_to_Binary_File(f);

        Read_from_Binary_File(f);
    a:
        cout << endl << endl << endl << "Select your task!" << endl << endl << endl;

        cout << "\t\t\t" << "1. Add inventory item" << endl << endl;
        cout << "\t\t\t" << "2. View all inventory items" << endl << endl;
        cout << "\t\t\t" << "3. Search inventory item" << endl << endl;
        cout << "\t\t\t" << "4. Edit inventory item" << endl << endl;
        cout << "\t\t\t" << "5. Delete inventory item" << endl << endl;
        cout << "\t\t\t" << "6. Assign inventory item" << endl << endl;
        cout << "\t\t\t" << "7. Retrieve inventory item" << endl << endl;
        cout << "\t\t\t" << "8. View the list of faculty members who have borrowed a specfic item" << endl << endl;


        cout << endl << endl << "Enter your choice : ";
        menu_choice = getche();


        switch (menu_choice)
        {
        case '1':
            Add_Inventory_Item(f);
            break;


        case '2':
            View_all_Inventory_Items();
            break;


        case '3':
            Search_Inventory_Item();
            break;


        case '4':
            Edit_Inventory_Item(f);
            break;


        case '5':
            Delete_Inventory_Item(f);
            break;


        case '6':
            Assign_Inventory_Item(f);
            break;


        case '7':
            Retrieve_Inventory_Item(f);
            break;


        case '8':
            View_Specific_Borrowers();
            break;

        default:
            cout << endl << endl << "\t\t\t" << "Invalid option! Try again!";
            goto a;
            break;
        }

        // Read_from_Binary_File(f);

        // View_all_Inventory_Items();

        cout << endl << endl << "Do you want to try again? (Y/N) : ";
        try_again = getche();

    } while (try_again == 'Y' || try_again == 'y');
    
    return 0;
}




void Read_from_Text_File(fstream &f)
{
    f.open("Inventory_Item_Data.txt", ios::in);

        if (f.is_open())
        {
            f >> app.i[0].Name >> app.i[0].Item_ID >> app.i[0].Category >> app.i[0].Item_Count >> app.i[0].Allocated_to;
            f >> app.i[1].Name >> app.i[1].Item_ID >> app.i[1].Category >> app.i[1].Item_Count >> app.i[1].Allocated_to;
            f >> app.i[2].Name >> app.i[2].Item_ID >> app.i[2].Category >> app.i[2].Item_Count >> app.i[2].Allocated_to;
            f >> app.i[3].Name >> app.i[3].Item_ID >> app.i[3].Category >> app.i[3].Item_Count >> app.i[3].Allocated_to;
            f >> app.i[4].Name >> app.i[4].Item_ID >> app.i[4].Category >> app.i[4].Item_Count >> app.i[4].Allocated_to;
        }

        else
        {
            cout << endl << "ERROR!" << endl;
        }

    f.close();
}



void Read_from_Binary_File(fstream &f)
{
    f.open("Binary.dat", ios::in | ios::binary);

    if (f.is_open())
    {
        f.read(reinterpret_cast<char *>(&app), (10 * sizeof(Item)));
    }

    else
    {
        cout << endl << "ERROR!" << endl;
    }

    f.close();
}



void Write_to_Binary_File(fstream &f)
{
    f.open("Binary.dat", ios::out | ios::binary);

    if (f.is_open())
    {
        f.write(reinterpret_cast<char *>(&app), (10 * sizeof(Item)));
    }

    else
    {
        cout << endl << "ERROR!" << endl;
    }

    f.close();
}



void View_all_Inventory_Items()
{
    cout << endl << endl << endl << endl;

    cout << "\t\t\t" << "ID" << "\t\t" << "NAME" << "\t\t\t" << "CATEGORY" << "\t\t" << "ITEM COUNT" << "\t\t" << "ALLOCATED TO" << endl;
    cout << "\t\t\t" << "--" << "\t\t" << "----" << "\t\t\t" << "--------" << "\t\t" << "----------" << "\t\t" << "------------" << endl << endl;

    int count = 0, i = 0;

    while(!(app.i[count].Item_Count == 0))
    {
        if (!(count == 2 || count == 3))
        {
            cout << setw(12) << "\t\t" << app.i[count].Item_ID << "\t\t" << app.i[count].Name << setw(10) << "\t\t" << app.i[count].Category << "\t\t" << setw(5) << app.i[count].Item_Count << "\t\t" << setw(20) << app.i[count].Allocated_to << endl << endl;
        }

        else
        {
            cout << setw(12) << "\t\t" << app.i[count].Item_ID << "\t\t" << app.i[count].Name << "\t\t" << app.i[count].Category << "\t\t" << setw(5) << app.i[count].Item_Count << "\t\t" << setw(21) << app.i[count].Allocated_to << endl << endl;
        }

        count++;
    }

    cout << endl << endl << endl;
}



int Search_Inventory_Item()
{
    char search_item[15];
    bool name_check = false;
    int item_index;

a:
    View_all_Inventory_Items();

    cout << endl << endl << "\t\t\t" << "Enter the item's name : ";
    cin >> search_item;

    for (int i = 0; i < 10; i++)
    {
        int j = 0;

        while (!(app.i[i].Name[j] == '\0') || !(j <= 15))
        {
            if (search_item[j] == app.i[i].Name[j])
            {
                name_check = true;
            }

            else
            {
                name_check = false;
                break;
            }

            j++;
        }

        if (name_check == true)
        {
            cout << endl << endl << "\t\t\t\t\t\t\t\t" << "ITEM FOUND!";

            item_index = i;
            break;
        } 
    }

    if (name_check == false)
    {
        cout << endl << endl << "\t\t\t\t\t\t\t" << "ITEM NOT FOUND! Invalid entry! Try again!";

        goto a;
    }

    cout << endl << endl << endl << endl << "\t\t\t" << "ID" << "\t\t" << "NAME" << "\t\t" << "CATEGORY" << "\t\t" << "ITEM COUNT" << "\t\t" << "ALLOCATED TO" << endl;

    cout << "\t\t\t" << "--" << "\t\t" << "----" << "\t\t" << "--------" << "\t\t" << "----------" << "\t\t" << "------------" << endl << endl;

    cout << "\t\t\t" << app.i[item_index].Item_ID << "\t\t" << app.i[item_index].Name << "\t\t" << app.i[item_index].Category << "\t\t" << setw(6) << app.i[item_index].Item_Count << "\t\t\t" << app.i[item_index].Allocated_to << endl << endl;


    return (item_index);
}

    

void Edit_Inventory_Item(fstream &f)
{
    int item_index, new_count;

    char again, new_name[15], new_category[15], edit_choice;


    item_index = Search_Inventory_Item();

    do
    {      
b:
        cout << endl << endl << "What do you want to edit?" << endl << endl;

        cout << "\t\t\t\t" << "1. Name" << endl << endl;
        cout << "\t\t\t\t" << "2. Category" << endl << endl;
        cout << "\t\t\t\t" << "3. Count" << endl;

        cout << endl << "Enter your option : ";
        edit_choice = getche();

        int i = 0;

        switch (edit_choice)
        {
        case '1':
            cout << endl << endl << "\t\t\t" << "Enter the new / edited name (no spaces) : ";
            cin >> new_name;

            i = 0;

            while (!(new_name[i] == '\0'))
            {
                app.i[item_index].Name[i] = new_name[i];

                i++;
            }

            for (; i < 15; i++)
            {
                app.i[item_index].Name[i] = '\0';
            }

            Write_to_Binary_File(f);


            cout << endl << endl << endl << "\t\t\t" << "ID" << "\t\t" << "NAME" << "\t\t" << "CATEGORY" << "\t\t" << "ITEM COUNT" << "\t\t" << "ALLOCATED TO" << endl;

            cout << "\t\t\t" << "--" << "\t\t" << "----" << "\t\t" << "--------" << "\t\t" << "----------" << "\t\t" << "------------" << endl << endl;

            cout << "\t\t\t" << app.i[item_index].Item_ID << "\t\t" << app.i[item_index].Name << "\t\t" << app.i[item_index].Category << "\t\t" << setw(6) << app.i[item_index].Item_Count << "\t\t\t" << app.i[item_index].Allocated_to << endl << endl;
            break;


        case '2':
            cout << endl << endl << "\t\t\t" << "Enter the new / edited category (no spaces) : ";
            cin >> new_category;

            i = 0;

            while (!(new_category[i] == '\0'))
            {
                app.i[item_index].Category[i] = new_category[i];

                i++;
            }

            for (; i < 15; i++)
            {
                app.i[item_index].Category[i] = '\0';
            }

            Write_to_Binary_File(f);


            cout << endl << endl << endl << "\t\t\t" << "ID" << "\t\t" << "NAME" << "\t\t" << "CATEGORY" << "\t\t" << "ITEM COUNT" << "\t\t" << "ALLOCATED TO" << endl;

            cout << "\t\t\t" << "--" << "\t\t" << "----" << "\t\t" << "--------" << "\t\t" << "----------" << "\t\t" << "------------" << endl << endl;

            cout << "\t\t\t" << app.i[item_index].Item_ID << "\t\t" << app.i[item_index].Name << "\t\t" << app.i[item_index].Category << "\t\t" << setw(6) << app.i[item_index].Item_Count << "\t\t\t" << app.i[item_index].Allocated_to << endl << endl;
            break;


        case '3':
            cout << endl << endl << "\t\t\t" << "Enter the new / edited item count (whole numbers) : ";
            cin >> new_count;

            app.i[item_index].Item_Count = new_count;

            Write_to_Binary_File(f);


            cout << endl << endl << endl << "\t\t\t" << "ID" << "\t\t" << "NAME" << "\t\t" << "CATEGORY" << "\t\t" << "ITEM COUNT" << "\t\t" << "ALLOCATED TO" << endl;

            cout << "\t\t\t" << "--" << "\t\t" << "----" << "\t\t" << "--------" << "\t\t" << "----------" << "\t\t" << "------------" << endl << endl;

            cout << "\t\t\t" << app.i[item_index].Item_ID << "\t\t" << app.i[item_index].Name << "\t\t" << app.i[item_index].Category << "\t\t" << setw(6) << app.i[item_index].Item_Count << "\t\t\t" << app.i[item_index].Allocated_to << endl << endl;
            break;


        default:
            cout << endl << endl << "\t\t" << "Invaild entry! Try again!";

            goto b;
            break;
        }

        cout << endl << endl << "\t\t\t" << "Would you like to edit this item's info again? (Y/N) : ";
        again = getche();

    } while (again == 'y' || again == 'Y');



    cout << endl << endl << endl << "Inventory has been edited!" << endl << endl;

    cout << "\t\t\t" << "ID" << "\t\t" << "NAME" << "\t\t\t" << "CATEGORY" << "\t\t" << "ITEM COUNT" << "\t\t" << "ALLOCATED TO" << endl;
    cout << "\t\t\t" << "--" << "\t\t" << "----" << "\t\t\t" << "--------" << "\t\t" << "----------" << "\t\t" << "------------" << endl << endl;

    int count = 0, i = 0;

    while(!(app.i[count].Item_Count == 0))
    {
        if (!(count == 2 || count == 3))
        {
            cout << "\t\t" << setw(12) << app.i[count].Item_ID << "\t\t" << app.i[count].Name << setw(10) << "\t\t" << app.i[count].Category << "\t\t" << setw(5) << app.i[count].Item_Count << "\t\t" << setw(20) << app.i[count].Allocated_to << endl << endl;
        }

        else
        {
            cout << "\t\t" << setw(12) << app.i[count].Item_ID << "\t\t" << app.i[count].Name << "\t\t" << app.i[count].Category << "\t\t" << setw(5) << app.i[count].Item_Count << "\t\t" << setw(21) << app.i[count].Allocated_to << endl << endl;
        }
        
        count++;
    }
}



void Add_Inventory_Item(fstream &f)
{
        int i = 0, add_item_index;

        char new_item_ID[8] = "FCIT0", again;


        View_all_Inventory_Items();

        while (!(app.i[i].Item_Count == 0))
        {
            i++;
        }

        add_item_index = i;


        int count = 0;

        while (!(new_item_ID[count] == '\0'))
        {
            app.i[add_item_index].Item_ID[count] = new_item_ID[count];

            count++;
        }

        char id_num, id_num1, id_num2;

        switch (add_item_index)
        {
        case 0:
            id_num = '1';

            app.i[add_item_index].Item_ID[count] = (id_num);
            break;


        case 1:
            id_num = '2';

            app.i[add_item_index].Item_ID[count] = (id_num);
            break;


        case 2:
            id_num = '3';

            app.i[add_item_index].Item_ID[count] = (id_num);
            break;


        case 3:
            id_num = '4';

            app.i[add_item_index].Item_ID[count] = (id_num);
            break;


        case 4:
            id_num = '5';

            app.i[add_item_index].Item_ID[count] = (id_num);
            break;


        case 5:
            id_num = '6';

            app.i[add_item_index].Item_ID[count] = (id_num);
            break;


        case 6:
            id_num = '7';

            app.i[add_item_index].Item_ID[count] = (id_num);
            break;


        case 7:
            id_num = '8';

            app.i[add_item_index].Item_ID[count] = (id_num);
            break;


        case 8:
            id_num = '9';

            app.i[add_item_index].Item_ID[count] = (id_num);
            break;


        case 9:
            id_num1 = '1', id_num2 = '0';

            app.i[add_item_index].Item_ID[count] = (id_num1);
            app.i[add_item_index].Item_ID[(count + 1)] = (id_num2);
            break;
        
        default:
            break;
        }



        cout << endl << "\t\t\t" << "Enter the new item's name (no spaces) : ";
        cin >> app.i[add_item_index].Name;

        cout << endl << "\t\t\t" << "Enter the new item's category (no spaces) : ";
        cin >> app.i[add_item_index].Category;

        cout << endl << "\t\t\t" << "Enter the new item's count (whole number) : ";
        cin >> app.i[add_item_index].Item_Count;

        cout << endl << "\t\t\t" << "Enter the new item's allocated to borrower names (name1,name2,name3....) : ";
        cin >> app.i[add_item_index].Allocated_to;


        Write_to_Binary_File(f);

        cout << endl << endl << endl << "New item has been added!" << endl;

        cout << endl << endl << "\t\t\t" << "ID" << "\t\t" << "NAME" << "\t\t" << "CATEGORY" << "\t\t" << "ITEM COUNT" << "\t\t" << "ALLOCATED TO" << endl;

        cout << "\t\t\t" << "--" << "\t\t" << "----" << "\t\t" << "--------" << "\t\t" << "----------" << "\t\t" << "------------" << endl << endl;

        cout << "\t\t\t" << app.i[add_item_index].Item_ID << "\t\t" << app.i[add_item_index].Name << "\t\t" << app.i[add_item_index].Category << "\t\t" << setw(6) << app.i[add_item_index].Item_Count << "\t\t\t" << app.i[add_item_index].Allocated_to << endl << endl;
}



void Delete_Inventory_Item(fstream &f)
{
    int delete_item_index;

     char search_item[15];
    bool name_check = false;
    int item_index;

a:
    View_all_Inventory_Items();

    cout << endl << endl << "\t\t\t" << "Enter the item's name : ";
    cin >> search_item;

    for (int i = 0; i < 10; i++)
    {
        int j = 0;

        while (!(app.i[i].Name[j] == '\0') || !(j <= 15))
        {
            if (search_item[j] == app.i[i].Name[j])
            {
                name_check = true;
            }

            else
            {
                name_check = false;
                break;
            }

            j++;
        }

        if (name_check == true)
        {
            cout << endl << endl << "\t\t\t\t\t\t\t\t" << "ITEM FOUND!";

            item_index = i;
            break;
        } 
    }

    if (name_check == false)
    {
        cout << endl << endl << "\t\t\t\t\t\t\t" << "ITEM NOT FOUND! Invalid entry! Try again!";

        goto a;
    }

    delete_item_index = item_index;


    int j = 0;

    for (int i = delete_item_index; i < 9; i++)
    {
        j = 0;
        
        while (!(app.i[(i + 1)].Name[j] == '\0'))
        {
        app.i[i].Name[j] = app.i[(i + 1)].Name[j];

        j++;
        }

        for (; j < 15; j++)
        {
            app.i[i].Name[j] = '\0';
        }



        j = 0;

        while (!(app.i[(i + 1)].Category[j] == '\0'))
        {
            app.i[i].Category[j] = app.i[(i + 1)].Category[j];

            j++;
        }

        for (; j < 15; j++)
        {
            app.i[i].Category[j] = '\0';
        }



        j = 0;

        while (!(app.i[(i + 1)].Allocated_to[j] == '\0'))
        {
            app.i[i].Allocated_to[j] = app.i[(i + 1)].Allocated_to[j];

            j++;
        }

        for (; j < 100; j++)
        {
            app.i[i].Allocated_to[j] = '\0';
        }



        app.i[i].Item_Count = app.i[(i + 1)].Item_Count;
    }

    Write_to_Binary_File(f);

    
    cout << endl << endl << "Item has been deleted from the inventory!" << endl << endl << endl;

    cout << "\t\t\t" << "ID" << "\t\t" << "NAME" << "\t\t\t" << "CATEGORY" << "\t\t" << "ITEM COUNT" << "\t\t" << "ALLOCATED TO" << endl;
    cout << "\t\t\t" << "--" << "\t\t" << "----" << "\t\t\t" << "--------" << "\t\t" << "----------" << "\t\t" << "------------" << endl << endl;

    int count = 0, i = 0;

    while(!(app.i[count].Item_Count == 0))
    {
        if (!(count == 2 || count == 3))
        {
            cout << "\t\t" << setw(12) << app.i[count].Item_ID << "\t\t" << app.i[count].Name << setw(10) << "\t\t" << app.i[count].Category << "\t\t" << setw(5) << app.i[count].Item_Count << "\t\t" << setw(20) << app.i[count].Allocated_to << endl << endl;
        }

        else
        {
            cout << "\t\t" << setw(12) << app.i[count].Item_ID << "\t\t" << app.i[count].Name << "\t\t" << app.i[count].Category << "\t\t" << setw(5) << app.i[count].Item_Count << "\t\t" << setw(21) << app.i[count].Allocated_to << endl << endl;
        }
        
        count++;
    }
}



void Assign_Inventory_Item(fstream &f)
{
        int item_index = Search_Inventory_Item();

        char borrower_name[15], try_again;

    do
    {
        cout << endl << endl << endl << "\t\t\t" << "Enter the name of the borrower (individual name) : ";
        cin >> borrower_name;


        int starting_point, count = 0;

        while (!(app.i[item_index].Allocated_to[count] == '\0'))
        {
            count++;
        }


        starting_point = count;

        count = 0;

        app.i[item_index].Allocated_to[starting_point] = ',';

        while (!(borrower_name[count] == '\0'))
        {
            app.i[item_index].Allocated_to[(starting_point + 1)] = borrower_name[count];

            starting_point++;
            count++;
        }

        app.i[item_index].Item_Count -= 1;



        Write_to_Binary_File(f);


        cout << endl << endl << endl;

        cout << "\t\t\t" << "ID" << "\t\t" << "NAME" << "\t\t\t" << "CATEGORY" << "\t\t" << "ITEM COUNT" << "\t\t" << "ALLOCATED TO" << endl;
        cout << "\t\t\t" << "--" << "\t\t" << "----" << "\t\t\t" << "--------" << "\t\t" << "----------" << "\t\t" << "------------" << endl << endl;

        count = 0;
        int i = 0;

        while(!(app.i[count].Item_Count == 0))
        {
            if (!(count == 2 || count == 3))
            {
                cout << "\t\t" << setw(12) << app.i[count].Item_ID << "\t\t" << app.i[count].Name << setw(10) << "\t\t" << app.i[count].Category << "\t\t" << setw(5) << app.i[count].Item_Count << "\t\t" << setw(20) << app.i[count].Allocated_to << endl << endl;
            }

            else
            {
                cout << "\t\t" << setw(12) << app.i[count].Item_ID << "\t\t" << app.i[count].Name << "\t\t" << app.i[count].Category << "\t\t" << setw(5) << app.i[count].Item_Count << "\t\t" << setw(21) << app.i[count].Allocated_to << endl << endl;
            }
            
            count++;
        }

        cout << endl << endl << "\t\t\t" << "Would you like to assign the item to another person? (Y/N) : ";
        try_again = getche();

    } while (try_again == 'Y' || try_again == 'y');  
}



void Retrieve_Inventory_Item(fstream &f)
{
    int item_index = Search_Inventory_Item(), starting_index, ending_index;

    char retriever_name[15], try_again;

    bool name_check = false;

    do
    {
        cout << endl << endl << endl << "\t\t\t\t" << "Enter the name of the retriever (individual name) : ";
        cin >> retriever_name;

        int count = 0;

        while (count < 100)
        {
            int i = 0;

            while (!(app.i[item_index].Allocated_to[count] == ','))
            {
                if (retriever_name[i] == app.i[item_index].Allocated_to[count])
                {
                    name_check = true;

                    if (retriever_name[0] == app.i[item_index].Allocated_to[count])
                    {
                        starting_index = count;
                    }
                }

                else
                {
                    name_check = false;

                    break;
                }

                i++;
            }
            count++;   


            if (name_check == true)
            {
                ending_index = (count - 1);

                break;
            }  
        }

        int iteration = 0;

        while (iteration < 100 || !(app.i[item_index].Allocated_to[iteration] == '\0'))
        {
            app.i[item_index].Allocated_to[starting_index] = app.i[item_index].Allocated_to[(ending_index + 1)];

            starting_index++;
            ending_index++;
            iteration++;
        }
        


        // count = 0;

        // app.i[item_index].Allocated_to[starting_point] = ',';

        // while (!(retriever_name[count] == '\0'))
        // {
        //     app.i[item_index].Allocated_to[(starting_point + 1)] = retriever_name[count];

        //     starting_point++;
        //     count++;
        // }

        app.i[item_index].Item_Count += 1;



        Write_to_Binary_File(f);


        cout << endl << endl << endl;

        cout << "\t\t\t\t" << "ID" << "\t\t" << "NAME" << "\t\t\t" << "CATEGORY" << "\t\t" << "ITEM COUNT" << "\t\t" << "ALLOCATED TO" << endl;
        cout << "\t\t\t\t" << "--" << "\t\t" << "----" << "\t\t\t" << "--------" << "\t\t" << "----------" << "\t\t" << "------------" << endl << endl;

        count = 0;
        int i = 0;

        while(!(app.i[count].Item_Count == 0))
        {
            if (!(count == 2 || count == 3))
            {
                cout << "\t\t\t" << setw(12) << app.i[count].Item_ID << "\t\t" << app.i[count].Name << setw(10) << "\t\t" << app.i[count].Category << "\t\t" << setw(5) << app.i[count].Item_Count << "\t\t" << setw(20) << app.i[count].Allocated_to << endl << endl;
            }

            else
            {
                cout << "\t\t\t" << setw(12) << app.i[count].Item_ID << "\t\t" << app.i[count].Name << "\t\t" << app.i[count].Category << "\t\t" << setw(5) << app.i[count].Item_Count << "\t\t" << setw(21) << app.i[count].Allocated_to << endl << endl;
            }
            
            count++;
        }

        cout << endl << endl << "Would you like to retrieve the item from another person? (Y/N) : ";
        try_again = getche();

    } while (try_again == 'Y' || try_again == 'y');  
}



void View_Specific_Borrowers()
{
    int item_index = Search_Inventory_Item();

    cout << endl << endl << endl << "\t\t\t" << "List of borrowers of this item : " << app.i[item_index].Allocated_to;

    cout << endl << endl << endl;
}