package ai_bandit.lab1;

import java.util.Random;

public class MultiBandit {
	//Array of bandits
	private Bandit[] bandits;
	private static Random random = new Random();
	
	public MultiBandit(int numberBandits) {
		this.bandits = new Bandit[numberBandits];
		
		int luckyIndex = random.nextInt(numberBandits);
		
		for(int i = 0; i < numberBandits; i++) {
			double mu = 0.0;
			
			if(i == luckyIndex) { //mu 1.1 to 1.3
				mu = 1.1 + (0.2 * random.nextDouble());
			}else { //mu 0.5 to 0.8
				mu = 0.5 + (0.3 * random.nextDouble());
			}
			
			this.bandits[i] = new Bandit("Bandit " + i, 1.0, mu, 1.0);
		}
	}
	
	//Getter
	public int getNumberBandits() {
		return bandits.length;
	}
	
	public double getPricePerRound() {//the same for every bandit
		return bandits[0].getPricePerRound();
	}
	
	public double getOverallProfit() {
		double totalProfit = 0.0;
		
		for(int i = 0; i < bandits.length; i++) {
			Bandit currentBandit = bandits[i];
			totalProfit = totalProfit + currentBandit.getOverallProfit();
		}
		
		return totalProfit;
	}
	
	public int getRoundsPlayed() {
		int totalRounds = 0;
		
		for(int i = 0; i < bandits.length; i++) {
			Bandit currentBandit = bandits[i];
			totalRounds = totalRounds + currentBandit.getRoundsPlayed();
		}
		
		return totalRounds;
	}
	
	public double getMeanProfitPerRound() {
		int rounds = getRoundsPlayed();
		if(rounds == 0) {
			return 0.0;
		}else {
			return getOverallProfit() / rounds;
		}
	}
	
	public double play(int banditIndex) {
		Bandit chosenBandit = bandits[banditIndex];
		
		double win = chosenBandit.play();
		
		return win;
	}
}
