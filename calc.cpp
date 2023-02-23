#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//declaring constants
const double SMALL = 35.00, MEDIUM = 50.00, LARGE = 70.00, UNLIMITED = 75.00, OVERAGE = 15.00;

int main() {
  //declaring variables
  char dataPlan;
  double gbUsage = 0.0, planCharge = 0.0, overCharge = 0.0, totalCost = 0.0, upgradeCost = 0.0;

  //welcome message and data plan pricing
  cout << "**** Welcome to Mint Mobile! **** \n\nLet's calculate your monthly bill! \n" << endl;
  cout << "S: 2GB $35/mo* \nM: 4GB $50/mo* \nL: 8GB $70/mo* \nU: Unlimited $75/mo \n\n*Overage charges $15 per GB\n" << endl;

  //set precision 2 decimals
  cout << fixed << setprecision(2);

  //prompt the user to input their data plan
  cout << "Which plan are you on? (S/M/L/U): ";
  cin >> dataPlan;
  dataPlan = (toupper(dataPlan));
  //data validation
  while (dataPlan != 'S' && dataPlan != 'M' && dataPlan != 'L' && dataPlan != 'U')
  {
    cin.clear();
    cin.ignore(100, '\n');
    cout << "\nInvalid plan! \nWhich plan are you on? (S/M/L/U): ";
    cin >> dataPlan;
    dataPlan = (toupper(dataPlan));
  }

  //prompt the use rto enter their data gbUsage
  cout << "\nHow many GB did you use last month?: ";
  cin >> gbUsage;
  //data validation
  while (!cin || gbUsage < 0)
  {
    cin.clear();
    cin.ignore(100, '\n');
    cout << "How many GB did you use last month?: ";
    cin >> gbUsage;
  }

  //ceil function to round number up
  gbUsage = ceil(gbUsage);

  //pricing for S data plan
  if (dataPlan == 'S' && gbUsage <= 2)
  {
    planCharge = SMALL;
    totalCost += planCharge;
  }
  //pricing for over usage for S data plan
  if (dataPlan == 'S' && gbUsage > 2)
  {
    planCharge = SMALL;
    overCharge = (gbUsage - 2.0) * OVERAGE;
    totalCost += (planCharge + overCharge);
    cout << "\nPlan charges: $" << planCharge << endl;
    cout << "Overage charges: $" << overCharge << endl;
    cout << "Total cost: $" << totalCost << endl;
  }
  //pricing for M data plan
  if (dataPlan == 'M' && gbUsage <= 4)
  {
    planCharge = MEDIUM;
    totalCost += planCharge;
  }
  //pricing for over usage for M data plan
  if (dataPlan == 'M' && gbUsage > 4)
  {
    planCharge = MEDIUM;
    overCharge = (gbUsage - 4.0) * OVERAGE;
    totalCost += (planCharge + overCharge);
    cout << "\nPlan charges: $" << planCharge << endl;
    cout << "Overage charges: $" << overCharge << endl;
    cout << "Total cost: $" << totalCost << endl;
  }

  //pricing for L data plan
  if (dataPlan == 'L' && gbUsage <= 8)
  {
    planCharge = LARGE;
    totalCost += planCharge;
  }
  //pricing for over usage for L data plan
  if (dataPlan == 'L' && gbUsage > 8)
  {
    planCharge = LARGE;
    overCharge = (gbUsage - 8.0) * OVERAGE;
    totalCost += (planCharge + overCharge);
    cout << "\nPlan charges: $" << planCharge << endl;
    cout << "Overage charges: $" << overCharge << endl;
    cout << "Total cost: $" << totalCost << endl;
  }

  //pricing for U data plan
  if (dataPlan == 'U')
  {
    planCharge = UNLIMITED;
    totalCost = planCharge;
  }

  //suggest upgrading with monthly savings
  if (totalCost > UNLIMITED)
  {
    upgradeCost = (totalCost - UNLIMITED);
    cout << "\nUpgrade to Unlimited and save $" << upgradeCost << "!!!" << endl;
  }
  //display charges and cost if less than unlimited
  else if (totalCost <= planCharge)
  {
  cout << "\nPlan charges: $" << planCharge << endl;
  cout << "Total cost: $" << totalCost << endl;
  }
  //display exit message
  cout << "\nThank you for choosing Mint Mobile! \nGoodbye!" << endl;

  return 0;

}

