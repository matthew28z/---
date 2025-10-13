#include "pzhelp"

void simplify(int a, int b) {
    int numerator = a;
    int denumerator = b;
    int i;
    
    //Epilegei to mikrotero
    if (a > b) {
        i = b;
    } else {
        i = a;
    }
    
    //Stamataei prin to 1
    for (int x = i; x > 1; x--) {
        if (numerator % x == 0 && denumerator % x == 0) {
            numerator = numerator / x;
            denumerator = denumerator / x;
        }
    }
    
    //Symfwna me thn askhsh
    if (numerator == 0) {
        denumerator = 1;
    }
    
    WRITELN(numerator, denumerator);
}

PROGRAM {
    int N = READ_INT();
    SKIP_LINE();
    
    for (int i = 0; i < N; i++) {
        char operation = getchar();
        //First
        int a = READ_INT();
        int b = READ_INT();
        
        //Second
        int c = READ_INT();
        int d = READ_INT();        
        
        SKIP_LINE();
        
        int num;
        int denum = b * d;
        
        if (operation == '+') {
            num = a * d + c * b;
        } else if (operation == '-') {
            num = a * d - c * b;
        } else if (operation == '*') {
            num = a * c;
        } else if (operation == '/') {
            num = a * d;
            denum = b * c;
        }
        
        simplify(num, denum);
        
    }
}
