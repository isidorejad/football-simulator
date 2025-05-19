package FootballGame;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;


class Team implements Comparable<Team> {
    private String name;
    private int points = 0;
    private int goals = 0;
    private int penaltyWins = 0;

    public Team(String name, int points, int goals, int penaltyWins){
        this.name = name;
        this.points = points;
        this.goals = goals;
        this.penaltyWins = penaltyWins;
    }

    public String getName(){
        return name;
    }

    public int getGoals(){
        return goals;
    }

    public void addGoals(int score){
        goals += score;
    }

    public int getPoints(){
        return points;
    }

    public void addWin() {
        points += 3;
    }
    
    public int getPenaltyWins(){
        return penaltyWins;
    }

    public void addPenaltyWins(int penaltyScore){
        penaltyWins += penaltyScore;
    }

    @Override
    public int compareTo(Team other) {
        if (points != other.points) {
            return other.points - points; // sort by points in descending order
        } else {
            return other.goals - goals; // sort by goals scored in descending order
        }
    }
}

class MyFileReader {
    public static Team[] readTeams(String filename) {
        try (Scanner scanner = new Scanner(new File(filename))) {
            scanner.useDelimiter("#");
            final Team[] teams = new Team[16];
            for (int i = 0; i < 16; i++) {
                String name = scanner.nextLine();
                int points = Integer.parseInt(scanner.nextLine());
                int goals = Integer.parseInt(scanner.nextLine());
                int penaltyWins = Integer.parseInt(scanner.nextLine());
                scanner.nextLine(); // consume the remaining newline character
                teams[i] = new Team(name, points, goals, penaltyWins);
            }
            return teams;
        } catch (FileNotFoundException e) {
            System.err.println("Error: file not found: " + filename);
            return null;
        }
    }
}

class Tournament{

    public void playMatch(Team team1, Team team2) {
        // Simulate the match
        int score1 = (int) (Math.random() * 4);
        int score2 = (int) (Math.random() * 6);

        team1.addGoals(score1);
        team2.addGoals(score2);
        if (score1 > score2) {
            team1.addWin();
        } else if (score2 > score1) {
            team2.addWin();
        }

        // Print the match result
        String matchResult = String.format("%s %d - %d %s", team1.getName(), score1, score2, team2.getName());
        System.out.println(matchResult);
    }
}

class MatchManager {

    private Team[] teams;

    public MatchManager(Team[] teams) {
        this.teams = teams;
    }
    
    // Create a queue to manage the matches
    Queue<Team> matchQueue = new LinkedList<Team>();

    public void playMatches() {
        // Add teams to the queue
        for (int i = 0; i < 16; i++) {
            matchQueue.add(teams[i]);
        }

        int round = 1;
        // Round of 16 matches
        while (matchQueue.size() > 1) {
            
            // Get two teams for the match
           
            //check how many games to be played
            int games = matchQueue.size()/2;
            int played = 0;            
          
            System.out.println("=================================");
            System.out.println("Round "+ round);
            System.out.println("=================================");
            //check how many games to be played
            while( played <= games){
                
            // Play the match and add the winner back to the queue
            Team team1 = matchQueue.remove();
            Team team2 = matchQueue.remove();
            Team winner = playMatch(team1, team2);
            
            matchQueue.add(winner);

            System.out.println("\n=================================\nWinner: " + winner.getName()+"\n=================================");

            played++;
            }
            System.out.println("=================================");
            round++;
        }

    }
    public Team playMatch(Team team1, Team team2) {
        // Simulate the match
        int score1 = (int) (Math.random() * 4);
        int score2 = (int) (Math.random() * 4);
    
        team1.addGoals(score1);
        team2.addGoals(score2);

        // Print the match result
        System.out.println("\n" +team1.getName() + "        -       " + team2.getName()+ "\n" + score1 + "              -         " + score2 );

        if (score1 > score2) {
            team1.addWin();
            return team1;
        } else {
            team2.addWin();
            return team2;
        }
    
}
    
    private static Team[] readTeams(String filename) {
        try (Scanner scanner = new Scanner(new File(filename))) {
            scanner.useDelimiter("#");
            final Team[] teams = new Team[16];
            for (int i = 0; i < 16; i++) {
                String team = scanner.nextLine();

                String info[] = team.split("#");
                String name = info[0];
                int points = Integer.parseInt(info[1]);
                int goals = Integer.parseInt(info[2]);
                int penaltyWins = Integer.parseInt(info[3]);
                teams[i] = new Team(name, points,goals, penaltyWins);
            }
            return teams;
        } catch (FileNotFoundException e) {
            System.err.println("Error: file not found: " + filename);
            return null;
        }
    }

public static void main(String[] args) {

    Scanner uScanner = new Scanner(System.in);
    int user_in;

    do {
        System.out.println("=========================");
        System.out.println("2023 World Cup Competition");
        System.out.println("=========================");
        System.out.println("|1| Manage");
        System.out.println("|2|     About");
        System.out.println("|3|         Exit");
        System.out.println("_________________________");

        user_in = uScanner.nextInt();
        System.out.println();

        switch (user_in) {
            case 1:
                System.out.println("-------------------------------------------------");
                System.out.println("Thank you for participating in our tournament");
                System.out.println("this year. You will find a list of all our compet-");
                System.out.println("itors below.");
                System.out.println("*************************************************\n");

                // Read teams from file
                Team[] teams = readTeams("C:/Users/isido/OneDrive/Desktop/Computer Science II Project/tournament.txt");
                System.out.print(readTeams("C:/Users/isido/OneDrive/Desktop/Computer Science II Project/tournament.txt"));
                System.out.println("-------------------------------------------------");

                // Create a match manager and play matches
                MatchManager matchManager = new MatchManager(teams);
                matchManager.playMatches();

                // Print final standings
                ArrayList<Team> sortedTeams = new ArrayList<>(Arrays.asList(teams));
                Collections.sort(sortedTeams);
                System.out.println("Final Standings:");
                for (int i = 0; i < sortedTeams.size(); i++) {
                    System.out.println((i+1) + ". " + sortedTeams.get(i).getName() + " - Points: " + sortedTeams.get(i).getPoints() + ", Goals: " + sortedTeams.get(i).getGoals());
                }

                break;

            case 2:
                System.out.println(" =================================================================");
                System.out.println("| This program manages an international football tournament for   |");
                System.out.println("| sixteen (16) teams. This competition has 4 Rounds, 16 countries |");
                System.out.println("| participating in this FIFA World Cup. Only 2 teams will make it |");
                System.out.println("| to the finals. Each game must have a winner, thus each team can |");
                System.out.println("| either win or lose, via direct win or loss or penalty. The best |");
                System.out.println("| 8 teams go on to the 2nd round and the best 4 to the semi-finals|");
                System.out.println("| and the best two to the finals.                                 |");
                System.out.println("|_________________________________________________________________|");
                break;

            case 3:
                System.exit(0);
                break;

            default:
                System.out.println("INCORRECT input.........please choose one of the following numbers\nbetween 1-3!!!");
                break;
        }
    } while (user_in != 3);
}}