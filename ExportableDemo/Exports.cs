using System;
using System.Runtime.InteropServices;

namespace ExportableDemo
{
    public static class Exports
    {
        [DllExport(CallingConvention.Cdecl)]
        public static void ExternalProcedure()
        {
            System.Diagnostics.Debug.Print("Hello from .NET Core 3.1 x64");
        }
    }
}
