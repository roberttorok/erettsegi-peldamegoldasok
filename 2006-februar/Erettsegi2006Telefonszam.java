import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.Scanner;

/**
 * 2006. májusi érettségi feladat egy lehetséges megoldása
 *
 * @author progmentor.hu
 */
public class Erettsegi2006Telefonszam {

    public static void main(String[] args) {
        new Erettsegi2006Telefonszam().feladatok();
    }

    private final String BEMENET = "/home/r/HIVASOK.TXT";
    private final String KIMENET = "/home/r/KIMENET.TXT";

    public void feladatok() {
        try {
            feladat1();
            feladat2();
            feladat3();
            feladat4();
            feladat5();
            feladat6();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void feladat1() {
        System.out.println("Adjon meg egy telefonszámot!: ");
        Scanner scanner = new Scanner(System.in);
        String telefonszam = scanner.next();
        if (isMobilszam(telefonszam)) {
            System.out.println("Mobil");
        } else {
            System.out.println("Vezetékes");
        }
    }

    public void feladat2() {
        System.out.println("Adjon meg egy hívás kezdeti és vége időpontot! (kezdóra kezdperc kezdmásodperc végeóra végeperc végemásodperc): ");
        Scanner scanner = new Scanner(System.in);
        Hivas hivas = new Hivas(scanner.nextLine());
        System.out.println("A beszélgetés " + hivas.hivasHossza() + " perces.");
    }

    public void feladat3() throws IOException {
        try (PrintWriter pw = new PrintWriter(KIMENET); BufferedReader br = new BufferedReader(new FileReader(BEMENET))) {
            String sor;
            while ((sor = br.readLine()) != null) {
                Hivas hivas = new Hivas(sor);
                String telefonszam = br.readLine();
                pw.println(hivas.hivasHossza() + " " + telefonszam);
            }
        }
    }

    public void feladat4() throws IOException {
        try (BufferedReader br = new BufferedReader(new FileReader(BEMENET))) {
            int sorSzam = 0;
            int hivasokSzamaCsucsidoben = 0;
            int hivasokSzamaCsucsidonKivul = 0;
            String sor;
            while ((sor = br.readLine()) != null) {
                if (sorSzam % 2 == 0) {
                    Hivas hivas = new Hivas(sor);
                    if (isCsucsodio(hivas.kezdOra)) {
                        hivasokSzamaCsucsidoben++;
                    } else {
                        hivasokSzamaCsucsidonKivul++;
                    }
                }

                sorSzam++;
            }

            System.out.println("Csúcsidőben hívások száma: " + hivasokSzamaCsucsidoben);
            System.out.println("Csúcsidőn kívül hivások száma: " + hivasokSzamaCsucsidonKivul);
        }

    }

    public void feladat5() throws IOException {
        try (BufferedReader br = new BufferedReader(new FileReader(BEMENET))) {
            int beszeltPercekMobil = 0;
            int beszeltPercekVezetekes = 0;
            String sor;
            while ((sor = br.readLine()) != null) {
                Hivas hivas = new Hivas(sor);
                String telefonszam = br.readLine();
                if (isMobilszam(telefonszam)) {
                    beszeltPercekMobil += hivas.hivasHossza();
                } else {
                    beszeltPercekVezetekes += hivas.hivasHossza();
                }
            }
            System.out.println("Beszélt percek mobilon: " + beszeltPercekMobil);
            System.out.println("Beszélt percek vezetékesen: " + beszeltPercekVezetekes);
        }
    }

    public void feladat6() throws IOException {
        try (BufferedReader br = new BufferedReader(new FileReader(BEMENET))) {
            BigDecimal fizetendo = new BigDecimal(0.0);
            String sor;
            while ((sor = br.readLine()) != null) {
                Hivas hivas = new Hivas(sor);
                String telefonszam = br.readLine();
                if (isCsucsodio(hivas.kezdOra)) {
                    fizetendo = fizetendo.add(szamolPercdij(telefonszam, hivas.hivasHossza(), hivas.kezdOra));
                }
            }

            System.out.println("Fizetendő: " + fizetendo.setScale(2, RoundingMode.UP));
        }
    }

    private BigDecimal szamolPercdij(String telefonszam, int perc, int kezdOra) {
        BigDecimal vezetekesCsucsido = new BigDecimal(30.0f);
        BigDecimal vezetekesNormal = new BigDecimal(15.0f);
        BigDecimal mobilCsucsido = new BigDecimal(69.175f);
        BigDecimal mobilNormal = new BigDecimal(46.675f);

        if (isMobilszam(telefonszam)) {
            if (isCsucsodio(kezdOra)) {
                return mobilCsucsido.multiply(new BigDecimal(perc));
            } else {
                return mobilNormal.multiply(new BigDecimal(perc));
            }
        } else {
            if (isCsucsodio(kezdOra)) {
                return vezetekesCsucsido.multiply(new BigDecimal(perc));
            } else {
                return vezetekesNormal.multiply(new BigDecimal(perc));
            }
        }
    }

    private boolean isMobilszam(String telefonszam) {
        return telefonszam.startsWith("39")
                || telefonszam.startsWith("41")
                || telefonszam.startsWith("71");
    }

    private boolean isCsucsodio(int ora) {
        return ora >= 7 && ora < 18;
    }

}

class Hivas {

    public int kezdOra;
    public int kezdPerc;
    public int kezdMasodperc;
    public int vegOra;
    public int vegPerc;
    public int vegMasodperc;

    public Hivas(String sor) {
        String arr[] = sor.split(" ");
        this.kezdOra = Integer.valueOf(arr[0]);
        this.kezdPerc = Integer.valueOf(arr[1]);
        this.kezdMasodperc = Integer.valueOf(arr[2]);
        this.vegOra = Integer.valueOf(arr[3]);
        this.vegPerc = Integer.valueOf(arr[4]);
        this.vegMasodperc = Integer.valueOf(arr[5]);
    }

    public int hivasHossza() {
        int hossz = (vegOra * 60 + vegPerc) - (kezdOra * 60 + kezdPerc);
        if (vegMasodperc > kezdMasodperc) {
            hossz++;
        }
        return hossz;
    }
}
