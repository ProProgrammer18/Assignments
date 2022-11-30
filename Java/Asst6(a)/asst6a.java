import java.io.File;
import java.io.FileWriter;
import java.io.InputStream;
import java.util.Scanner;
import java.io.IOException;

public class asst6a {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        System.out.println("Enter the name of the file: ");

        try {
            String fileName = s.nextLine();

            File file = new File(fileName);

            if (file.createNewFile()) {
                System.out.println("File Created: " + file.getName());
                System.out.println("Do you want to write in it?: (Yes/No)");

                String decision = s.nextLine();

                if (decision.equals("No") || decision.equals("no") ) {
                    return;
                } else {
                    FileWriter writer = new FileWriter(fileName);

                    while (true) {
                        String enteredData = s.nextLine();
                        if (enteredData.equals("exit")) {
                            break;
                        }

                        writer.write(enteredData);
                        writer.write("\n");
                    }

                    writer.close();
                    System.out.println("Written Successfully!");

                }

            } else {
                System.out.println("File already exists with content: ");

                Scanner reader = new Scanner(file);

                while (reader.hasNextLine()) {
                    String data = reader.nextLine();
                    System.out.println(data);
                }

                reader.close();

                System.out.println("Do you want to add anything to this file?: (Yes/No) ");

                String decision = s.nextLine();

                if (decision.equals("No") || decision.equals("no")) {
                    return;
                } else {
                    FileWriter writer = new FileWriter(fileName,true);

                    while (true) {
                        String enteredData = s.nextLine();
                        if (enteredData.equals("exit")) {
                            break;
                        }

                        writer.append(enteredData);
                        writer.write("\n");
                    }

                    writer.close();
                    System.out.println("Written Successfully!");

                }

            }
        } catch (IOException e) {
            System.out.println("An error has occured");
        }

    }
}
