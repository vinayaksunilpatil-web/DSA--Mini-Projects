#include<iostream>
#include<vector>
#include<iomanip>
#include<unordered_map>
using namespace std;

struct Expense
{
    int id;
    string title;
    string category;
    string date;
    float amount;
};


void merge(vector<Expense> &expenses, int start, int end,int mid){
    int i = start, j = mid + 1;
    vector<Expense> temp;
    while(i<=mid && j<=end){
        if(expenses[i].amount >=expenses[j].amount){
            temp.push_back(expenses[j]);
            j++;
        }else{
            temp.push_back(expenses[i]);
            i++;
        }
    }
    while(i<=mid){
        temp.push_back(expenses[i]);
        i++;
    }

    while(j<=end){
        temp.push_back(expenses[j]);
        j++;
    }

    for (int idx = 0, x = start; idx < temp.size();idx++){
        expenses[x++] = temp[idx];
    }
}

    void mergeSort(vector<Expense> &expenses, int start, int end)
{
    if(start>=end){
        return;
    }
    int mid = start + (end - start) / 2;
    mergeSort(expenses, start, mid);
    mergeSort(expenses, mid + 1, end);
    merge(expenses, start, end, mid);
}



void print_Expense(const vector<Expense> &expenses){
    cout << fixed << setprecision(2);
    if(expenses.empty()){
        cout << "No expenses exist start by adding a new expense..." << endl;
        return;
    }
    cout << string(72, '-') << endl;
    cout << left
        <<  setw(10)<<"Id"
         << setw(20) << "Title"
         << setw(15) << "Category"
         << setw(12) << "Amount"
         << setw(15) << "Date" << endl;
    cout << string(72, '-') << endl;
    for (int i = 0; i < expenses.size();i++){
        cout << left
             << setw(10) << expenses[i].id
             << setw(20) << expenses[i].title
             << setw(15) << expenses[i].category
             << setw(12) << expenses[i].amount
             << setw(15) << expenses[i].date
             << endl;
    }
    cout << string(72, '-') << endl;
}

class ExpenseTracker
{
public:
    int id = 1;
    string title, category, date;
    float amount;

    void add_expense(vector<Expense> &expenses)
    {
        Expense exp;
        exp.id = id++;
        cout << "Enter an expense name:";
        getline(cin >> ws, exp.title);
        cout << "Enter an category of expense:";
        getline(cin >> ws, exp.category);
        cout << "Enter amount of expense:";
        cin >> exp.amount;
        cout << "Enter date at you expended (dd-mm-yyyy):";
        cin >> exp.date;
        expenses.push_back(exp);
        cout << "Expense added succesfully...." << endl;
    }

    void update_expense(vector<Expense> &expenses)
    {
        if (expenses.empty())
        {
            cout << "No expenses available.\n";
            return;
        }

        vector<int> matchedIndexes;
        string title;

        cout << "Enter expense title to update: ";
        cin >> title;

        // Store indexes of all matching expenses
        for (int i = 0; i < expenses.size(); i++)
        {
            if (expenses[i].title == title)
            {
                matchedIndexes.push_back(i);
            }
        }

        if (matchedIndexes.empty())
        {
            cout << "Expense not found.\n";
            return;
        }

        cout << "\nMatching Expenses:\n";
        cout << string(72, '-') << endl;

        for (int i = 0; i < matchedIndexes.size(); i++)
        {
            int idx = matchedIndexes[i];

            cout << i + 1 << ". "
                 << expenses[idx].title << " | "
                 << expenses[idx].category << " | "
                 << expenses[idx].amount << "  | "
                 << expenses[idx].date << endl;
        }

        int choice;
        cout << "\nEnter which expense to update (1-" << matchedIndexes.size() << "): ";
        cin >> choice;

        if (choice < 1 || choice > matchedIndexes.size())
        {
            cout << "Invalid choice.\n";
            return;
        }

        int idx = matchedIndexes[choice - 1];

        cout << "Enter new title: ";
        getline(cin >> ws, expenses[idx].title);

        cout << "Enter new category: ";
        getline(cin >> ws, expenses[idx].category);

        cout << "Enter new amount: ";
        cin >> expenses[idx].amount;

        cout << "Enter new date: ";
        cin >> expenses[idx].date;

        cout << "Expense updated successfully.\n";
    }

    void delete_expense(vector<Expense> &expenses)
    {
        if (expenses.empty())
        {
            cout << "No expenses available.\n";
            return;
        }

        vector<int> matchedIndexes;
        string title;

        cout << "Enter expense title to delete: ";
        cin >> title;

        // Store indexes
        for (int i = 0; i < expenses.size(); i++)
        {
            if (expenses[i].title == title)
            {
                matchedIndexes.push_back(i);
            }
        }

        if (matchedIndexes.empty())
        {
            cout << "Expense not found.\n";
            return;
        }

        cout << "\nMatching Expenses:\n";
        cout << string(72, '-') << endl;

        for (int i = 0; i < matchedIndexes.size(); i++)
        {
            int idx = matchedIndexes[i];

            cout << i + 1 << ". "
                 << expenses[idx].title << " | "
                 << expenses[idx].category << " | "
                 << expenses[idx].amount << "  | "
                 << expenses[idx].date << endl;
        }

        int choice;
        cout << "\nEnter which expense to delete (1-" << matchedIndexes.size() << "): ";
        cin >> choice;

        if (choice < 1 || choice > matchedIndexes.size())
        {
            cout << "Invalid choice.\n";
            return;
        }

        expenses.erase(expenses.begin() + matchedIndexes[choice - 1]);

        cout << "Expense deleted successfully.\n";
    }

    void expense_analysis(const vector<Expense>& expenses){
        if(expenses.empty()){
            cout << "Add a expenseses to anyalis...." << endl;
            return;
        }
        int lowest=0, highest=0;
        float total_amm=expenses[0].amount, small_amm= expenses[0].amount, highest_amm=expenses[0].amount;
        print_Expense(expenses);
        
        cout << "---Anylasis of Expenses----" << endl;
        for (int i = 1; i < expenses.size();i++){
            if(small_amm >expenses[i].amount){
                small_amm = expenses[i].amount;
                lowest = i;
            }
            if(highest_amm <expenses[i].amount){
                highest_amm = expenses[i].amount;
                highest = i;
            }
            total_amm += expenses[i].amount;
        }
        cout << "Total expenses:" << total_amm << "Rs" << endl;
        cout << "Lowest Expended Amount:" << small_amm << "Rs" << "------" << expenses[lowest].title << endl;
        cout << "Highest Expended Amount:" << highest_amm << "Rs." << "------"<<expenses[highest].title << endl;
    }

    void category_expense(const vector<Expense>& expenses){
        if (expenses.empty())
        {
            cout << "Add a expenseses to anyalis...." << endl;
            return;
        }
        unordered_map<string, float> category_expense;
        for (int i = 0; i < expenses.size();i++){
            category_expense[expenses[i].category] += expenses[i].amount;
        }
        cout << "----Category wise Anylisis----" << endl;
        cout << left
             << setw(20) << "Category"
             << setw(15) << "Total Amount (Rs.)" << endl;

        cout << string(35, '-') << endl;
        for (auto it = category_expense.begin(); it != category_expense.end(); it++)
        {
            cout << left
                 << setw(20) << it->first
                 << setw(15) << it->second
                 << endl;
        }
    }

    void budget_expense(const vector<Expense> &expenses){
        float budget;
        bool is_found = false;
        cout << "Enter a budget :" << endl;
        cin >> budget;
        cout << left
             << setw(10) << "Id"
             << setw(20) << "Title"
             << setw(15) << "Category"
             << setw(12) << "Amount (Rs.)"
             << setw(15) << "Date" << endl;
        cout << string(72, '-') << endl;

        for (int i = 0; i < expenses.size();i++){
            if(budget>= expenses[i].amount){
                is_found = true;
                cout << left
                     << setw(10) << expenses[i].id
                     << setw(20) << expenses[i].title
                     << setw(15) << expenses[i].category
                     << setw(12) << expenses[i].amount
                     << setw(15) << expenses[i].date
                     << endl;
            }
        }
        if(! is_found){
            cout << "No expenseses exists for the specified budget..." << endl;
        }
    }


};

int main(){
    vector<Expense> expenses;
    cout << "----Welcome to Expense Tracker----" << endl;
    cout << "----Expense tracker tracks and gives amazing insights----" << endl;
    int ch;
    ExpenseTracker e;
    while(true){
        
        cout << "---Menu---" << endl;
        cout << "1. Add a new Expense" << endl;
        cout << "2. Update Expense by title/date" << endl;
        cout << "3. Delete Expense" << endl;
        cout << "4. Display all Expenses" << endl;
        cout << "5. Expense Analysis" << endl;
        cout << "6. Display expense by category" << endl;
        cout << "7. Sort expense by amount" << endl;
        cout << "8. Display expenses within specified budget" << endl;
        cout << "9. Exit" << endl;
        cout << endl;
        cout << "Enter a choice:";
        cin >> ch;
        if(ch==1){
            e.add_expense(expenses);
        }else if(ch==2){
            e.update_expense(expenses);
        }else if(ch==3){
            e.delete_expense(expenses);
        }else if(ch==4){
            print_Expense(expenses);
        }else if(ch==5){
            e.expense_analysis(expenses);
        }else if(ch==6){
            e.category_expense(expenses);
        }else if(ch==7){
            if(expenses.empty()){
                cout << "No expense exists.. Try adding expense" << endl;
            }else{
                mergeSort(expenses, 0, expenses.size() - 1);
                print_Expense(expenses);
            }
        }else if(ch==8){
            e.budget_expense(expenses);
        }else{
            break;
        }
    }
    return 0;
}