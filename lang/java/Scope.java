public class Scope {
    boolean b = true; // b1 has scope of entire class
    int x = 88; // x1 has scope of entire class
	
    Scope(){
        double d = 9.0;
        example(d);
    }
	
    void example(double x){ // parameter x2 has scope of this method
        System.out.println("----- example(double x):\n"
                + 	"Initial value of Local Variable `x`: " + x + "\n");
                
        x = 4.4; // reassign value of local variable x2
        
        System.out.println("New value of Local Variable `x`: " + x + "\n");
		
        for(int b = 0; b < 4; b++){ // b2 has scope of this loop
            int i = b + 4; // begin scope of int i
            System.out.println(	"For Loop 1 in example(double x):\n"
                + 	"Local Variable `b` (local to loop): " + b + "\n" 
                +	"Local Variable `i` (local to loop): " + i + "\n" 
                + 	"Local Variable `x` (method parameter): " + x + "\n"); 
        } // end the scope of int b2; end scope of int i
		
        for(int b = 0; b < 4; b++){
            x = b; 
            System.out.println(	"For Loop 2 in example(double x):\n"
                +	"Local Variable `b` (local to loop): " + b + "\n" 
                +	"Local Variable `x` (method parameter): " + x + "\n"); 
        } // end of the scope of this version of int b
		
        System.out.println("Local Variable `x` after Loop 2: " + x + "\n");
		
    } // end scope of double x2

    void classVariable(){
        System.out.println(	"----- classVariable():\n"
                +	"Instance Variable `b`: " + b + "\n"
                + 	"Instance Variable `x`: " + x);
    }
	
    public static void main(String[] args){
        Scope s = new Scope();
	s.classVariable();
    }
} // end of boolean b's scope; end of int x's scope
