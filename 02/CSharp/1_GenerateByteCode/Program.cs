using System.Diagnostics;

namespace GenerateByteCode;

public sealed class Program
{
    private const ushort SIZE = 0x8000;

    public static void Main(string[] args)
    {
        // This is your program
        byte[] program = new byte[]
        {
            0xEA,
            0x4C, 0x00, 0x80
        };

        byte[] binOut = new byte[SIZE];

        Debug.Assert(program.Length < 0x7FFC);

        for (int i = 0; i < program.Length; ++i)
        {
            binOut[i] = program[i];
        }

        binOut[0x7FFC] = 0x00;
        binOut[0x7FFD] = 0x80;

        File.WriteAllBytes("program.bin", binOut.ToArray());
    }
}