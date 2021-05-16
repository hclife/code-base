/** Superclass **/
abstract class Canine{
    // instance variables
    String name;
    String color;
    String gender;
    int age;
    
    /** Parameterized Constructor 
    *   @param name Dog's name
    *   @param color Dog's color
    *   @param age Dog's age
    *   @param mF Dog's gender ('M' for male, 'F' for female)
    **/
    Canine(String name, String color, int age, char mF){ 
        this.name = name;
        this.color = color;
        this.age = age;
        this.gender = (mF == 'M') ? "Male " : "Female ";
    }
    
    /** Abstract method declaration
    *   @return Implementations should return a string describing the breed **/
    abstract String getBreed(); 
    
    /** Defined method **/
    void printInfo(){ 
    	// print information about the dog:
        System.out.println(name + " is " + ((age%10 == 8)? "an " : "a ") + age + " year old " 
           + gender + getBreed() + " with a " + color + " coat.");
        // note: the '(age%10 == 8)' conditional ensures grammatical correctness if dog is 8 or 18; dogs do not live longer than this.
    }
}

//** Subclass of Canine **/
class KleeKai extends Canine{
	/** Parameterized Constuctor **/
    KleeKai(String name, String color, int age, char mF){ 
        super(name, color, age, mF); 
    }
    
    /** Abstract method implementation
    *   @return "Klee Kai" **/
    String getBreed(){ // abstract method implementation
        return "Klee Kai";
    }
}

/** Subclass of Canine **/
class SiberianHusky extends Canine{ 
	/** Parameterized Constuctor **/
    SiberianHusky(String name, String color, int age, char mF){ // Constructor
        super(name, color, age, mF); 
    }
    
    /** Abstract method implementation
    *   @return "Siberian Husky" **/
    String getBreed(){ // abstract method implementation
        return "Siberian Husky";
    }
}

class TestCanine {
	public static void main(String[] args)
	{
		Canine c = new KleeKai("Lilah","Grey/White",5,'F');
		Canine d = new SiberianHusky("Alaska","Grey/Black/White",16,'F');
		c.printInfo();
		d.printInfo();
	}
}
