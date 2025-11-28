import java.util.*;

public class crc1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter message bits: ");
        String msg = sc.nextLine();
        System.out.print("Enter generator: ");
        String gen = sc.nextLine();

        int m = msg.length(), g = gen.length();
        int[] data = new int[m + g - 1], div = new int[g];
        for (int i = 0; i < m; i++) data[i] = msg.charAt(i) - '0';
        for (int i = 0; i < g; i++) div[i] = gen.charAt(i) - '0';

        for (int i = 0; i < m; i++)
            if (data[i] == 1)
                for (int j = 0; j < g; j++)
                    data[i + j] ^= div[j];

        System.out.print("Checksum code: ");
        for (int i = 0; i < m; i++) System.out.print(msg.charAt(i));
        for (int i = m; i < data.length; i++) System.out.print(data[i]);
        System.out.println();

        System.out.print("Enter received code: ");
        String recv = sc.nextLine();
        int[] recvData = new int[recv.length()];
        for (int i = 0; i < recv.length(); i++) recvData[i] = recv.charAt(i) - '0';

        for (int i = 0; i < recv.length() - g + 1; i++)
            if (recvData[i] == 1)
                for (int j = 0; j < g; j++)
                    recvData[i + j] ^= div[j];

        boolean valid = true;
        for (int bit : recvData) if (bit == 1) valid = false;
        System.out.println(valid ? "Data stream is valid." : "CRC error occurred.");
}
}
