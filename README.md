# Chip8 Disassembler 
```
      ___           ___                       ___           ___      
     /\  \         /\__\          ___        /\  \         /\  \     
    /::\  \       /:/  /         /\  \      /::\  \       /::\  \  
   /:/\:\  \     /:/__/          \:\  \    /:/\:\  \     /:/\:\  \   
  /:/  \:\  \   /::\  \ ___      /::\__\  /::\~\:\  \   /::\~\:\  \  
 /:/__/ \:\__\ /:/\:\  /\__\  __/:/\/__/ /:/\:\ \:\__\ /:/\:\ \:\__\
 \:\  \  \/__/ \/__\:\/:/  / /\/:/  /    \/__\:\/:/  / \:\ \:\/:/  /
  \:\  \            \::/  /  \::/__/          \::/  /   \:\ \::/  / 
   \:\  \           /:/  /    \:\__\           \/__/     \:\/:/  /   
    \:\__\         /:/  /      \/__/                      \::/  /    
     \/__/         \/__/                                   \/__/     
```
Chip8 is a fictional computer architecture created in the 70s by Jospeh Weisbecker to allow video games to be more easily programmed for a diverse range of computer hardware.
Chip8 is realized in the form of a virtual machine on which ROMs either compiled, assembled or handwritten (byte by byte!) are run.
This repository contains the source code for a disassembler for Chip8 ROMS that allow them to be converted into Frédéric Devernay's version of Chip8 assembly (http://devernay.free.fr/hacks/chip8/C8TECH10.HTM).

I've also created my own implementation of the Chip8 virtual machine along with an assembler of Frédéric's Chip8 assembly. 
They can be found here https://github.com/xchg-rax-rax/Chip8-Emulator and here https://github.com/xchg-rax-rax/chip8asm respectively.

## Why a Chip8 Disassembler?
Having as disassembler is very useful when working with Chip8 for an number of reasons.
Firstly and most prominently it helps you with debugging your own implementation of the Chip8 VM if you're in the process of writing one.
And given that debugging will likely take up the majority of your time when implementing Chip8 having any kind of aid in the process is a massive time saver.
Secondly to help your learn about programming in Chip8 by reversing other peoples ROMs.
Chip8 is a bit of an unusual platform and the documentation for how to program for it is sparse.
A surprising amount can be gain however from taking other peoples programs disassembling them and doing a little reverse engineering to discover how they approached programming for the architecture.
Finally if you're writing an assembler for Frédéric's version of Chip8 assembly, or even a different one, being able to perform the inverse operation and compare the disassemblers output with the input assembly is invaluable in debugging and testing such a piece of software.

## Compilation

For the moment to compile the program use the following commands (I'll add a make file later...):
```{bash}
$ git clone https://github.com/xchg-rax-rax/chip8dasm
$ cd chip8dasm
$ gcc ./src/chip8dasm.c -o ./bin/chip8dasm
```
