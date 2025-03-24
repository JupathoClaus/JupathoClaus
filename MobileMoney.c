#include <stdio.h>

int main(){
int Account_Balance = 50000;
int Withdrawal_Amount;
printf("======Enter amount to withdraw.======\n");
scanf("%d", &Withdrawal_Amount);

if (Withdrawal_Amount <= Account_Balance){
    Account_Balance = Account_Balance - Withdrawal_Amount;

    printf("===Withdrawal of %d successful.===\n", Withdrawal_Amount);
    printf("===Remaining Balance: %d ===\n", Account_Balance);

}else {
    printf("===Insufficient funds. Withdrawal failed.===\n");
}

return 0;



}