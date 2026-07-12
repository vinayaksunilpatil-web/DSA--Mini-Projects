// Problem: Develop software to manage products in a store. The application should allow
// adding, updating, deleting, searching and sorting products while also identifying low - stock items.
#include<iostream>
#include<vector>
using namespace std;

struct Product
{
    int id;
    string name;
    float price;
    int quantity;
    string category;
};

void print(const vector<Product> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << "ID : " << arr[i].id << endl;
        cout << "Name : " << arr[i].name << endl;
        cout << "Price : " << arr[i].price << " Rs" << endl;
        cout << "Quantity : " << arr[i].quantity << endl;
        cout << "Category : " << arr[i].category << endl;
        cout << "-------------------------" << endl;
    }
}

void merge(vector<Product> &prod, int start, int end,int mid){
    int i = start, j = mid + 1;
    vector<Product> temp;
    while(i<=mid && j<=end){
        if(prod[i].price>=prod[j].price){
            temp.emplace_back(prod[j]);
            j++;
        }else{
            temp.emplace_back(prod[i]);
            i++;
        }
    }

    while(i<=mid){
        temp.emplace_back(prod[i]);
        i++;
    }

    while(j<=end){
        temp.emplace_back(prod[j]);
        j++;
    }

    for (int idx = 0, x = start; idx < temp.size(); idx++){
        prod[x++] = temp[idx];
    }
}

void MergeSort(vector<Product>& prod, int start, int end){
    if(start>=end){
        return;
    }
    int mid = start + (end - start) / 2;
    MergeSort(prod, start, mid);
    MergeSort(prod, mid + 1, end);
    merge(prod, start, end, mid);
}

class Inventory_Management{
    public:
        int n, id;
        string name, target;
        float price, budget;
        

        void add_product(vector<Product> &prod){
            Product p;
            cout << "Enter no. of items to add";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "Enter Product ID : ";
                cin >> p.id;

                cout << "Enter Product Name : ";
                cin >> p.name;

                cout << "Enter Price : ";
                cin >> p.price;

                cout << "Enter Quantity : ";
                cin >> p.quantity;

                cout << "Enter Category : ";
                cin >> p.category;

                bool found = false;

                for (int i = 0; i < prod.size(); i++)
                {
                    if (prod[i].id == p.id)
                    {
                        found = true;
                        break;
                    }
                }

                if (found)
                {
                    cout << "Product ID already exists! Please enter a unique ID.\n";
                    i--; // Ask for this product again
                    continue;
                }

                prod.push_back(p);
            }
            cout << "Products added succesfully!!!" << endl;
        }

        void update_product(vector<Product> &prod)
        {
            bool found = false;
            cout << "Enter the id of product to update:";
            cin >> id;
            for (int i = 0; i < prod.size(); i++)
            {
                if (prod[i].id == id)
                {
                    found = true;
                    cout << "Enter the update name of item:";
                    cin >> name;
                    prod[i].name = name;
                    cout << "Enter the price of item to update:";
                    cin >> price;
                    prod[i].price = price;
                    cout << "Products updated succesfully!!!" << endl;
                    break;
                }
            }
            if(!found){
                cout << "Product not found.." << endl;
            }
        }

        void delete_product(vector<Product> &prod)
        {
            bool found = false;
            cout << "Enter the id of product to delete:";
            cin >> id;

            for (int i = 0; i < prod.size(); i++)
            {
                if (prod[i].id == id)
                {
                    found = true;
                    prod.erase(prod.begin() + i);
                    cout << "Product deleted successfully!!!" << endl;
                    break;
                }
            }
            if(! found){
                cout << "Product not found.." << endl;
            }
        }

        void search_product(vector<Product> &prod){
            bool found = false;
            cout << "Enter the id of product to serach:";
            cin >> id;
            for (int i = 0; i < prod.size(); i++)
            {
                if (prod[i].id == id)
                {
                    found = true;
                    cout << "The product found...You can buy it.." << endl;
                    cout << "ID       : " << prod[i].id << endl;
                    cout << "Name     : " << prod[i].name << endl;
                    cout << "Price    : " << prod[i].price << endl;
                    cout << "Quantity : " << prod[i].quantity << endl;
                    cout << "Category : " << prod[i].category << endl;
                    break;
                }
            }
            if(!found){
                cout << "Product not found... Please try again later.." << endl;
            }
        }

        void items_budget(vector<Product> & prod )
        {
            bool found = false;
            cout << "Enter your budget prize:";
            cin >> budget;
            vector<Product> bud;
            for (int i = 0; i < prod.size(); i++)
            {
                if (prod[i].price < budget)
                {
                    found = true;
                    bud.push_back(prod[i]);
                    
                }
            }
            if(!found){
                cout << "No product matches with budget..";
            }else{
                cout << "Items in budget are:" << endl;
                print(bud);
            }
            
            cout << endl;
        }
};

int main(){

    vector<Product> products;
    cout << "-----Welcome----" << endl;
    cout << "-------Inventory Management System-----" << endl;
    Inventory_Management inventory;
    while(true){
        cout << endl;
        cout << "1. Add Products" << endl;
        cout << "2. Update Products" << endl;
        cout << "3. Delete the Products" << endl;
        cout << "4. Search Products" << endl;
        cout << "5. Sort the products" << endl;
        cout << "6. Find the items in budget" << endl;
        cout << "7. Show Products" << endl;
        int ch;
        cout << "Enter choice:";
        cin >> ch;
        if(ch==1){
            inventory.add_product(products);
        }else if(ch==2){
            inventory.update_product(products);
        }else if(ch==3){
            inventory.delete_product(products);
        }else if(ch==4){
            inventory.search_product(products);
        }else if(ch==5){
            if(products.empty()){
                cout << "No products found...";
                continue;
            }else{
                MergeSort(products, 0, products.size() - 1);
                print(products);
            }
        }else if(ch==6){
            inventory.items_budget(products);
        }else if(ch==7){
            if(products.empty()){
                cout << "No products found..." << endl;
            }else{
                print(products);
            }
        }else{
            cout << "No operation exits for the request... Please cheeck the choice";
            break;
        }
    }
    
    return 0;
}