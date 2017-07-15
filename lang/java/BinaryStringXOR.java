class BinaryStringXOR {
    BinaryStringXOR(String string, Integer integer){
        String binaryInteger = Integer.toBinaryString(integer);
        for( byte b : string.getBytes() ){
            // Perform a bitwise operation using byte and integer operands, save result as tmp:
            int tmp = b ^ integer; 
            System.out.println( Integer.toBinaryString(b) + " XOR " + Integer.toBinaryString(integer) 
                + " = " + Integer.toBinaryString(tmp) + " = " + tmp );
        }
    }
    
    public static void main(String[] args) {
        new BinaryStringXOR("HackerRank", 8675309);
    }
}

