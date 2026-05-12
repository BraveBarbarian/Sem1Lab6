package ai_bandit.lab1;

import java.util.Random;

public class Bandit {
		private static Random random = new Random();
		private String name;
		private double pricePerRound;
		private double averageWin; //mü
		private double stdDevWin; //sigma
		private double overallProfit; //gesamtes bisherigen Gewinn aus Sicht des Automaten.
		private int roundsPlayed;
		
		//Constructor
		
		public Bandit(String name, double pricePerRound, double averageWin, double stdDevWin) {
			this.name = name;
			this.pricePerRound = pricePerRound;
			this.averageWin = averageWin;
			this.stdDevWin = stdDevWin;
			this.overallProfit = 0.0;
			this.roundsPlayed = 0;
			
		}
		
		public Bandit(double pricePerRound, double averageWin, double stdDevWin) {
			this.name = "Unnamed Bandit";
			this.pricePerRound = pricePerRound;
			this.averageWin = averageWin;
			this.stdDevWin = stdDevWin;
		}

		//Getters
		
		public double getPricePerRound() {
			return pricePerRound;
		}

		public double getOverallProfit() {
			return overallProfit;
		}

		public int getRoundsPlayed() {
			return roundsPlayed;
		}

		public String getName() {
			return name;
		}
		
		public double getMeanProfitPerRound() {
			if(roundsPlayed == 0) {
				return 0.0	;
			}else {
				return overallProfit / roundsPlayed;
			}
		}
		
		public double play() {
			double win = determineWin();
			
			this.overallProfit = this.overallProfit + this.pricePerRound - win;
			
			this.roundsPlayed++;
		
			return win;
		}
		
		private double determineWin() {
			double rawWin = averageWin + stdDevWin * random.nextGaussian();
			
			//No negative Wins
			if(rawWin < 0) {
				rawWin = 0;
			}
			
			//round auf Vielfache von 10cent
			return Math.round(rawWin * 10.0)/10.0;
			
			
		}

}
