public class GenerateBitRotate {
  public static void main(String[] args) {
    generateBitReverse();
  }

  /**
   * Generate a look up table
   * Rotate the 8-bit pattern corresponding to half a board layer 
   * x x x x
   * x x x x
   * 4 5 6 7
   * 0 1 2 3
   * into this pattern
   * 0 4 x x
   * 1 5 x x
   * 2 6 x x
   * 3 7 x x   
   *
   * Start pattern : xxxx xxxx 7654 3210
   * Result pattern: xx40 xx51 xx62 xx73
   */
  static void generateBitRotate90() {
    for (int i = 0; i < 32; i++) {
      for (int j = 0; j < 8; j++) {
        int x = i * 8 + j;
        int t = 
          (x >> 3 & 1) |
          (x >> 7 & 1) << 1 |
          (x >> 2 & 1) << 4 |
          (x >> 6 & 1) << 5 |
          (x >> 1 & 1) << 8 |
          (x >> 5 & 1) << 9 |
          (x >> 0 & 1) << 12 |
          (x >> 4 & 1) << 13;
        System.out.print(String.format("0x%04x", t));
        System.out.print(", ");
      }
      System.out.println();
    }
  }


  /**
   * Generate look up table for the reversal of 8-bit pattern
   */
  static void generateBitReverse() {
    for (int i = 0; i < 32; i++) {
      for (int j = 0; j < 8; j++) {
        int x = i * 8 + j; // the bit pattern to be reversed
        x = (x & 0xF0) >> 4 | (x & 0x0F) << 4; // switch every 2 bytes
        x = (x & 0xCC) >> 2 | (x & 0x33) << 2; // switch every 2 nibbles
        x = (x & 0xAA) >> 1 | (x & 0x55) << 1; // switch every 2 bits
        System.out.print(String.format("0x%02x", x));
        System.out.print(", ");
      }
      System.out.println();
    }
  }
}