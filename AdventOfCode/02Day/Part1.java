import java.util.*;
import java.io.*;

public class Part1 {
    public static void main(String[] args) {
        try {
            final int RED = 12;
            final int GREEN = 13;
            final int BLUE = 14;
            int count = 0;
            Scanner input = new Scanner(new File("test.txt"));
            while (input.hasNextLine()) {
                String line = input.nextLine();
                Boolean check = true;
                int id = Integer.parseInt(line.split(":")[0].split(" ")[1].strip());
                System.out.println(id);
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
                                    check = false;
                                }
                                break;
                            case "green":
                                if (num > GREEN) {
                                    check = false;
                                }

                                break;
                            case "blue":
                                if (num > BLUE) {
                                    check = false;
                                }
                                break;
                        }

                    }

                }
                if (!check) {
                    System.out.println("False");
                    System.out.println(count);
                } else {
                    count += id;

                    System.out.println("True");
                }
                System.out.println(count);

            }
            input.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
