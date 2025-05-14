#include <iostream>
#include <string>

using namespace std;

class Invoice {
private:
    string partNumber;
    string partDescription;
    int quantity;
    int pricePerItem;

public:
    Invoice(string pn, string desc, int qty, int price) {
        partNumber = pn;
        partDescription = desc;
        setQuantity(qty);
        setPricePerItem(price);
    }

    void setQuantity(int qty) { quantity = (qty < 0) ? 0 : qty; }
    int getQuantity() { return quantity; }

    void setPricePerItem(int price) { pricePerItem = (price < 0) ? 0 : price; }
    int getPricePerItem() { return pricePerItem; }

    string getPartDescription() { return partDescription; }

    int getInvoiceAmount() { return quantity * pricePerItem; }
};


int main() {
    Invoice item1("1", "手提工具袋", 2, 286);
    Invoice item2("2", "剝線鉗", 4, 182);
    Invoice item3("3", "螺絲起子組", 3, 149);

    cout << "物品:" << item1.getPartDescription() 
         << "總金額:" << item1.getInvoiceAmount() << endl;
    cout << "物品:" << item2.getPartDescription()
         << "總金額:" << item2.getInvoiceAmount() << endl;
    cout << "物品:" << item3.getPartDescription()
         << "總金額:" << item3.getInvoiceAmount() << endl;

    return 0;
}