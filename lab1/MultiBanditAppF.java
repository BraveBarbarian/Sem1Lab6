/*package ai_bandit.lab1;

import java.util.Random;
import java.util.Scanner;

public class MultiBanditApp {

	public static void main(String[] args) {
		//Scanner
		Scanner scanner = new Scanner(System.in);
		Random random = new Random();
		double net = 0.0;
		double profit = 0.0;
		
		//initialize
		int numberBandits = 7;
		double price = 1.0;
		MultiBandit multiBandit = new MultiBandit(numberBandits);
		
		System.out.println("Gambling:\tMulti-Armed Bandit");
		System.out.println("Price:\t\t" + price + "EUR");
		
		System.out.println("How many rounds would you like to play? ");
		int rounds = scanner.nextInt();
		
		System.out.println("Round\t| Bandit\t| Win [EUR]\t| Net [EUR]");
		for(int i = 1; i < rounds+1; i++) {
			//choosing random bandit
			int banditIndex = random.nextInt(numberBandits);
			
			double win = multiBandit.play(banditIndex);
			
			net = multiBandit.getOverallProfit();
			profit = net;
			
			System.out.printf("%d\t| %d\t| %.2f\t\t| %.2f%n", i, banditIndex, win, net);
			
		}
		
		System.out.println("Multi-armed Bandit's statistics :");
		System.out.println("Rounds:\t" + rounds);
		System.out.printf("Profit:\t%.2f (%.2f EUR/round)", net , net/rounds);

	}

}*/
