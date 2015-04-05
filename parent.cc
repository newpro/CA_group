#include "bank.h"
#include "printer.h"
#include "parent.h"
using namespace std;

extern MPRNG rand_gen;

Parent::Parent( Printer &prt, Bank &bank, unsigned int numStudents, unsigned int parentalDelay ) {
    this->print = &prt;
    this->bank = &bank;
    numStudents = numStudents;
    parentalDelay = parentalDelay;
}

void Parent::main() {
    for (;;) {
       _Accept(~Parent){
            return;
        } _Else {
            yield(parentalDelay);
            int amount = rand_gen(1);
            int id = rand_gen(numStudents);
            if ( amount == 0 ) {
                bank->deposit( id, 1);
            } else {
                bank->deposit( id, 3);
            }
        }
    }
}
