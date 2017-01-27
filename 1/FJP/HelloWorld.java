import java.util.Scanner;

public class HelloWorld {
    public static void main(String[] args) {
        System.out.print("Enter your name: ");
        Scanner input = new Scanner(System.in);
        String name = input.nextLine();
        System.out.print("Your name is: " + name);
    }
}
