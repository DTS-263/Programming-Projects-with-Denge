import java.util.Random; // For generating random class 
import java.util.Scanner;
class RockPaper
{
	public static void main(String[] args) {
		System.out.println("Let's Play Rock Paper and Scissors!!!");
		System.out.println("Enter the choice-> 1.Rock 2.Paper 3.Scissors");
		int choice;
		Scanner sc = new Scanner(System.in);
		choice = sc.nextInt();
		// If choice=1 then Rock
		// choice=2 then Paper
		// choice=3 then Scissors
		Random rd = new Random(); // New class random and its object named rd
		int computer_choice = rd.nextInt(3) + 1; // Generates random number by the computer from the range [0,3) and adds 1 to it as we want inputs 1,2,3
		if(computer_choice == 1) // Computer chooses Rock
		{
			System.out.println("Rock is the computer's choice.");
			if(choice == 1)
			{
				System.out.println("TIE!!");
			}
			else if(choice == 2)
			{
				System.out.println("YOU WIN!!");
			}
			else if(choice == 3)
			{
				System.out.println("YOU LOSE!! Better Luck Next Time!!");
			}
			else
			{
				System.out.println("[WARNING] Wrong Choice");
			}
		}
		else if(computer_choice == 2) // Computer chooses Paper
		{
			System.out.println("Paper is the computer's choice.");
			if(choice == 2)
			{
				System.out.println("TIE!!");
			}
			else if(choice == 3)
			{
				System.out.println("YOU WIN!!");
			}
			else if(choice == 1)
			{
				System.out.println("YOU LOSE!! Better Luck Next Time!!");
			}
			else
			{
				System.out.println("[WARNING] Wrong Choice");
			}
		}
		else // Computer chooses Scissors
		{
			System.out.println("Scissors is the computer's choice.");
			if(choice == 3)
			{
				System.out.println("TIE!!");
			}
			else if(choice == 1)
			{
				System.out.println("YOU WIN!!");
			}
			else if(choice == 2)
			{
				System.out.println("YOU LOSE!! Better Luck Next Time!!");
			}
			else
			{
				System.out.println("[WARNING] Wrong Choice");
			}
		}
	}
}