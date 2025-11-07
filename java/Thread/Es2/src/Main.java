import java.util.Arrays;
import java.util.Scanner;

public class Main {
    @SuppressWarnings("UseSpecificCatch")
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Quanti elementi vuoi fare: ");
        int BOUND = Integer.parseInt(scanner.nextLine());

        Risorsa risorsa = new Risorsa(BOUND);

        Thread t1 = new Thread(new WriterThread(risorsa, 1));
        Thread t2 = new Thread(new WriterThread(risorsa, 2));
        Thread t3 = new Thread(new WriterThread(risorsa, 3));

        t1.start();
        t2.start();
        t3.start();

        try {
            t1.join();
            t2.join();
            t3.join();
        } catch (Exception e) {
            System.out.println("Errore: " + e);
        }

        System.out.println("Risorsa: " + Arrays.toString(risorsa.getArr()));

    }
}
