/**
 * test program for our ProductServices
 */

#include <iostream>
#include "products.hpp"
#include "productservice.hpp"

using namespace std;

int main()
{
  // Create the 10Y treasury note
  date maturityDate(2025, Nov, 16);
  string cusip = "912828M56";
  Bond treasuryBond(cusip, CUSIP, "T", 2.25, maturityDate);

  // Create the 2Y treasury note
  date maturityDate2(2017, Nov, 5);
  string cusip2 = "912828TW0";
  Bond treasuryBond2(cusip2, CUSIP, "T", 0.75, maturityDate2);

  // Create a BondProductService
  BondProductService *bondProductService = new BondProductService();

  // Add the 10Y note to the BondProductService and retrieve it from the service
  bondProductService->Add(treasuryBond);
  Bond bond = bondProductService->GetData(cusip);
  cout << "CUSIP: " << bond.GetProductId() << " ==> " << bond << endl;

  // Add the 2Y note to the BondProductService and retrieve it from the service
  bondProductService->Add(treasuryBond2);
  bond = bondProductService->GetData(cusip2);
  cout << "CUSIP: " << bond.GetProductId() << " ==> " << bond << endl;

  // Create the Spot 10Y Outright Swap
  date effectiveDate(2015, Nov, 16);
  date terminationDate(2025, Nov, 16);
  string outright10Y = "Spot-Outright-10Y";
  IRSwap outright10YSwap(outright10Y, THIRTY_THREE_SIXTY, THIRTY_THREE_SIXTY, SEMI_ANNUAL, LIBOR, TENOR_3M, effectiveDate, terminationDate, USD, 10, SPOT, OUTRIGHT);

  // Create the IMM 2Y Outright Swap
  date effectiveDate2(2015, Dec, 20);
  date terminationDate2(2017, Dec, 20);
  string imm2Y = "IMM-Outright-2Y";
  IRSwap imm2YSwap(imm2Y, THIRTY_THREE_SIXTY, THIRTY_THREE_SIXTY, SEMI_ANNUAL, LIBOR, TENOR_3M, effectiveDate2, terminationDate2, USD, 2, IMM, OUTRIGHT);

  // Create a IRSwapProductService
  IRSwapProductService *swapProductService = new IRSwapProductService();

  // Add the Spot 10Y Outright Swap to the IRSwapProductService and retrieve it from the service
  swapProductService->Add(outright10YSwap);
  IRSwap swap = swapProductService->GetData(outright10Y);
  cout << "Swap: " << swap.GetProductId() << " == > " << swap << endl;

  // Add the IMM 2Y Outright Swap to the IRSwapProductService and retrieve it from the service
  swapProductService->Add(imm2YSwap);
  swap = swapProductService->GetData(imm2Y);
  cout << "Swap: " << swap.GetProductId() << " == > " << swap << endl;


  string bf = "bfcusip13";
  BondFuture bondfuture = BondFuture(bf,cusip,10,100,date(2025,Oct,3));
  cout << "BondFuture: " << bondfuture.GetProductId() << " ==> " << bondfuture << endl;

  string bf2 = "bfcusip26";
  BondFuture bondfuture2 = BondFuture(bf2,cusip2,7.9,100,date(2017,Oct,1));
  cout << "BondFuture: " << bondfuture2.GetProductId() << " ==> " << bondfuture2 << endl;

  string cme = "CMEaldi2";
  EuroDollarFuture edfuture = EuroDollarFuture(cme,13,100,date(2024,Mar,5),date(2026,Mar,5));
  cout << "EuroDollarFuture: " << edfuture.GetProductId() << " ==> " << edfuture << endl;

  FutureProductService *futureProductService = new FutureProductService();

  futureProductService->Add(bondfuture);
  Future future = futureProductService->GetData(bf);
  cout << "Future: " << future.GetProductId() << " == > " << future << endl;
  
  futureProductService->Add(edfuture);
  future = futureProductService->GetData(cme);
  cout << "Future: " << future.GetProductId() << " == > " << future << endl;
  
  string ticker = "T";
  auto r = bondProductService->GetBonds(ticker);
  for(auto i = r.begin();i!=r.end();i++){
    cout<<"Bond: "<<*i<<endl;
  }
    
  auto r2 = swapProductService->GetSwapsLessThan(5);
  for(auto i = r2.begin();i!=r2.end();i++){
    cout<<"Swap: "<<*i<<endl;
  }

  return 0;
  
}
