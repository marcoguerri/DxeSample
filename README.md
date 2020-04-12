Work in progress

## How to use
Once compiled, run with

```
qemu-system-x86_64  -pflash <EDKII_ROOT>/Build/OvmfX64/DEBUG_GCC5/FV/OVMF_CODE.fd  -net none -debugcon file:debug.log -global isa-debugcon.iobase=0x402 -cdrom <ISO_FILE> -m 4096
