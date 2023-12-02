import java.util.*;
import java.io.*;

public class Part2 {
    public static void main(String[] args) {
        try {
            int count = 0;
            Scanner input = new Scanner(new File("test.txt"));
            while (input.hasNextLine()) {
                int RED = 0;
                int GREEN = 0;
                int BLUE = 0;
                String line = input.nextLine();
                ArrayList<String> draws = new ArrayList<String>(Arrays.asList(line.split(":")[1].split(";")));
                for (String draw : draws) {
                    ArrayList<String> items = new ArrayList<String>(Arrays.asList(draw.split(",")));
                    for (String item : items) {
                        String[] splitItems = item.strip().split(" ");
                        int num = Integer.parseInt(splitItems[0].strip());
                        String color = splitItems[1].strip();
                        switch (color) {
                            case "red":
                                if (num > RED) {
                                    RED = num;
                                }
                                break;
                            case "green":
                                if (num > GREEN) {
                                    GREEN = num;
                                }

                                break;
                            case "blue":
                                if (num > BLUE) {
                                    BLUE = num;
                                }
                                break;
                        }
                    }
                }
                count += RED * BLUE * GREEN;
            }
            System.out.println(count);
            input.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
