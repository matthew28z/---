#include "pzhelp"

void simplify(int a, int b) {
    int intPart = 0;
    //Krataei se apolyto gia na leitourgei h aplopoihsh
    int numerator = abs(a);
    int denumerator = abs(b);
    int i;
    
    //Epilegei to mikrotero
    if (numerator > denumerator) {
        i = denumerator;
    } else {
        i = numerator;
    }
    
    //Stamataei prin to 1
    for (int x = i; x > 1; x--) {
        if (numerator % x == 0 && denumerator % x == 0) {
            numerator = numerator / x;
            denumerator = denumerator / x;
        }
    }
    
    //Blepei poses monades xwrane sto klasma afou auto exei aplopoihthei
    while (numerator / denumerator >= 1) {
        intPart++;
        /*An yparxei monada allazoume ton arithmith afairontas apo auton 
          ton paronomasth*/
        numerator = numerator - denumerator;
    }
    
    //Symfwna me thn askhsh
    if (numerator == 0) { // einai mhden
        denumerator = 1;
        WRITELN(0, 0, 1);
    /*Bazei a / b giati auta exoun akoma to proshmo
      To (REAL) krataei to dekadiko meros*/
    } else if ((REAL)a / b < 0) { // einai arnhtiko
        //To WRITE() den allazei grammh
        WRITE("-");
        WRITELN(intPart, numerator, denumerator);
    } else { // einai thetiko
        WRITELN(intPart, numerator, denumerator);
    }
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
        
        if (b == 0 || d == 0) {
            WRITELN("error");
        } else {
            int num;
            int denum = b * d;
            
            if (operation == '+') {
                num = a * d + c * b;
            } else if (operation == '-') {
                num = a * d - c * b;
            } else if (operation == '*') {
                num = a * c;
            } else if (operation == '/') {
                if (c == 0) {
                    WRITELN("error");
                } else {
                    num = a * d;
                    denum = b * c;                    
                }
            }
        
            simplify(num, denum);
        }
        
    }
}
