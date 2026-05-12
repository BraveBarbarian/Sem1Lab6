package ai_bandit.lab1;

import java.util.Scanner;

public class BanditApp {
	public static void main(String[] args) {
		//Scanner
		Scanner scanner = new Scanner(System.in);
		double profit = 0.0;
		
		//Objekt erstellen
		Bandit myBandit = new Bandit("Slotty", 1.00, 0.80 , 0.20);
		
		String name = myBandit.getName();
		Double price = myBandit.getPricePerRound();
		
		System.out.println("Gambling:\t One-Armed Bandit");
		System.out.println("Price:\t\t" + price + "EUR");
		
		System.out.println("How many rounds would you like to play? ");
		int rounds = scanner.nextInt();
		
		//table
		System.out.println("Round\t| Win [EUR]\t| Net [EUR]");
		for(int i = 1; i < rounds+1; i++) {
			double win = myBandit.play();
			double net = myBandit.getOverallProfit();
			profit = net;
			System.out.printf("%d\t| %.2f\t\t| %.2f%n", i, win, net);
		}
		
		System.out.println("\n" + name + "'s statistics :");
		System.out.println("Rounds:\t" + rounds);
		System.out.printf("Profit:\t%.2f (%.2f EUR/round)", profit, profit/rounds);
		

	}

}
