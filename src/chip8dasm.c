#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>


#define MEM_SIZE 4096

// CPU instructions
// each function has an name that describes it's action followed by it's associated opcode
// Assembly syntax is taken from http://devernay.free.fr/hacks/chip8/C8TECH10.HTM

void execute_machine_language_subroutine_0NNN(unsigned short opcode) {
    unsigned short NNN = opcode & 0xFFF;
    // This instruction is only used to run machine specific binary for old hardware and
    // need not be implemented in modern emulators .
    printf("SYS %03X\n",NNN);
}

void clear_screen_00E0(unsigned short opcode) {
    printf("CLS\n");
}

void return_00EE(unsigned short opcode) {
    printf("RTS\n");
}

void jump_to_1NNN(unsigned short opcode) {
    unsigned short NNN = opcode & 0xFFF;
    printf("JP %03x\n",NNN);
}

void execute_subroutine_2NNN(unsigned short opcode) {
    unsigned short NNN = opcode & 0xFFF;
    printf("CALL %03x\n",NNN);
}

void skip_if_VX_equals_NN_3XNN(unsigned short opcode) {
    unsigned short X = (opcode & 0xF00) >> 8;
    unsigned char NN = opcode & 0xFF;
    printf("SE V%X, %02X\n",X,NN);
}

void skip_if_not_VX_equal_NN_4XNN(unsigned short opcode) {
    unsigned short X = (opcode & 0xF00) >> 8;
    unsigned char NN = opcode & 0xFF;
    printf("SNE V%X, %02X\n",X,NN);
}

void skip_if_VX_equal_VY_5XY0(unsigned short opcode) {
    unsigned short X = (opcode & 0xF00) >> 8;
    unsigned short Y = (opcode & 0xF0) >> 4;
    printf("SE V%X, V%X\n",X,Y);
}

void load_NN_into_VX_6XNN(unsigned short opcode) {
    unsigned short X = (opcode & 0xF00) >> 8;
    unsigned char NN = opcode & 0xFF;
    printf("LD V%X, %02X\n",X,NN);
}

void add_NN_to_VX_7XNN(unsigned short opcode) {
    unsigned short X = (opcode & 0xF00) >> 8;
    unsigned char NN = opcode & 0xFF;
    printf("ADD V%X, %02X\n", X, NN);
}

void mov_VX_to_VY_8XY0(unsigned short opcode) {
    unsigned short X = (opcode & 0xF00) >> 8;
    unsigned short Y = (opcode & 0xF0) >> 4;
    printf("LD V%X,, V%X\n", X, Y);
}

void set_VX_to_VX_OR_VY_8XY1(unsigned short opcode) {
    unsigned short X = (opcode & 0xF00) >> 8;
    unsigned short Y = (opcode & 0xF0) >> 4;
    printf("OR V%X, V%X\n", X, Y);
}

void set_VX_to_VX_AND_VY_8XY2(unsigned short opcode) {
    unsigned short X = (opcode & 0xF00) >> 8;
    unsigned short Y = (opcode & 0xF0) >> 4;
    printf("AND V%X, V%X\n", X, Y);
}

void set_VX_to_VX_XOR_VY_8XY3(unsigned short opcode) {
    unsigned short X = (opcode & 0xF00) >> 8;
    unsigned short Y = (opcode & 0xF0) >> 4;
    printf("XOR V%X, V%X\n", X, Y);
}

void add_VY_to_VX_8XY4(unsigned short opcode) {
    unsigned short X = (opcode & 0xF00) >> 8;
    unsigned short Y = (opcode & 0xF0) >> 4;
    printf("ADD V%X, V%X\n", X, Y);
}

void sub_VY_from_VX_8XY5(unsigned short opcode) {
    unsigned short X = (opcode & 0xF00) >> 8;
    unsigned short Y = (opcode & 0xF0) >> 4;
    printf("SUB V%X, V%X\n", X, Y);
}

void right_shift_VY_store_in_VX_8XY6(unsigned short opcode) {
    // This opcode was originally undocumented and has had two separate implementations
    // in one VX is right shifted and stored in itself in the other VY is right shifted
    // and stored in VX. Just gotta hope you picked the right one or that it doesn't
    // get used by anyone!!
    unsigned short X = (opcode & 0xF00) >> 8;
    unsigned short Y = (opcode & 0xF0) >> 4;
    printf("SHR V%X, V%X\n", X, Y);
}

void set_VX_to_VY_minus_VX_8XY7(unsigned short opcode) {
    unsigned short X = (opcode & 0xF00) >> 8;
    unsigned short Y = (opcode & 0xF0) >> 4;
    printf("SUBN V%X, V%X\n", X, Y);
}

void left_shift_VY_store_in_VX_8XYE(unsigned short opcode) {
    // This opcode was originally undocumented and has had two separate implementations
    // in one VX is left shifted and stored in itself in the other VY is left shifted
    // and stored in VX. Just gotta hope you picked the left one or that it doesn't
    // get used by anyone!!
    unsigned short X = (opcode & 0xF00) >> 8;
    unsigned short Y = (opcode & 0xF0) >> 4;
    printf("SHL V%X, V%X\n", X, Y);
}

void skip_if_VX_not_equal_VY_9XY0(unsigned short opcode) {
    unsigned short X = (opcode & 0xF00) >> 8;
    unsigned short Y = (opcode & 0xF0) >> 4;
    printf("SNE V%X, V%X\n",X,Y);
}

void store_NNN_in_I_ANNN(unsigned short opcode) {
    unsigned short NNN = opcode & 0xFFF;
    printf("SKIP.NE I, V%03X\n",NNN);
}

void jump_to_NNN_plus_V0_BNNN(unsigned short opcode) {
    unsigned short NNN = opcode & 0xFFF;
    printf("JP %03X\n", NNN);
}

void set_VX_to_random_with_mask_NN_CXNN(unsigned short opcode) {
    unsigned short X = (opcode & 0xF00) >> 8;
    unsigned short NN = opcode & 0xFF;
    printf("RND V%X, %02X\n", X, NN);
}

void draw_N_sprite_at_VX_VY_DXYN(unsigned short opcode) {
    unsigned short X = (opcode & 0xF00) >> 8;
    unsigned short Y = (opcode & 0xF0) >> 4;
    unsigned short N = (opcode & 0xF);
    printf("DRW V%X, V%X %X\n", X, Y, N);
}

void skip_if_VX_key_pressed_EX9E(unsigned short opcode) {
    unsigned short X = (opcode & 0xF00) >> 8;
    printf("SKP V%X\n", X);
}

void skip_if_VX_not_pressed_EXA1(unsigned short opcode) {
    unsigned short X = (opcode & 0xF00) >> 8;
    printf("SKNP V%X\n", X);
}

void store_delay_timer_in_VX_FX07(unsigned short opcode) {
    unsigned short X = (opcode & 0xF00) >> 8;
    printf("LD V%X, DT\n", X);
}

void store_keypress_in_VX_FX0A(unsigned short opcode) {
    unsigned short X = (opcode & 0xF00) >> 8;
    printf("LD V%X, K\n", X);
}

void set_delay_timer_to_VX_FX15(unsigned short opcode) {
    unsigned short X = (opcode & 0xF00) >> 8;
    printf("LD DT, V%X\n", X);
}

void set_sound_timer_to_VX_FX18(unsigned short opcode) {
    unsigned short X = (opcode & 0xF00) >> 8;
    printf("LD ST, V%X\n", X);
}

void add_VX_to_I_FX1E(unsigned short opcode) {
    unsigned short X = (opcode & 0xF00) >> 8;
    printf("ADD I, V%X\n", X);
}

void set_I_to_addr_of_VX_sprite_FX29(unsigned short opcode) {
    unsigned short X = (opcode & 0xF00) >> 8;
    printf("LD F, V%X", X);
}

void store_VX_as_BCD_at_I_FX33(unsigned short opcode) {
    unsigned short X = (opcode & 0xF00) >> 8;
    printf("LD B, V%X\n",X);
}

void store_V0_to_VX_in_I_FX55(unsigned short opcode) {
    unsigned short X = (opcode & 0xF00) >> 8;
    printf("LD [I], V%X",X);
}

void set_V0_to_VX_to_I_FX65(unsigned short opcode) {
    unsigned short X = (opcode & 0xF00) >> 8;
    printf("LD V%X, [I]\n",X);
}

// Initialization Functions


void load_process_image(unsigned char* memory, char* rom_path) {
    FILE* rom_fd;
    unsigned int rom_size;
    unsigned int bytes_read;
    if (access(rom_path, R_OK) != 0) {
        printf("Error: Cannot read ROM at path %s.\n", rom_path);
        exit(1);
    }
    // load rom into chip8 memory
    rom_fd = fopen(rom_path, "r");
    if (!rom_fd) {
        printf("Error: Could not open ROM at path %s.\n", rom_path);
        exit(1);
    }
    fseek(rom_fd, 0L, SEEK_END); // go to end of file
    rom_size  = ftell(rom_fd);
    rewind(rom_fd);
    if (rom_size > 4096-512) {
        printf("Error: ROM is of size %d bytes and exceeds capacity of 4KB memory.\n",rom_size);
        fclose(rom_fd);
        exit(1);
    }
    bytes_read = fread(memory,rom_size,1,rom_fd)*rom_size;
    if (bytes_read != rom_size) {
        printf("Error: Failed to read complete ROM into memory. Read %d, expected %d\n", bytes_read);
        fclose(rom_fd);
        exit(1);
    }
    fclose(rom_fd);
}


void decode_instruction(unsigned short opcode) {
    // looking up instruction via case statement
    switch((opcode&0xF000) >> 12) { 
        case 0x0:
            if (opcode == 0x00E0)
                clear_screen_00E0(opcode);
            else if (opcode == 0x00EE)
                return_00EE(opcode);
            else
                // 0NNN
                printf("Instruction is not implemented : %04X\n",opcode);
            break;
        case 0x1:
            jump_to_1NNN(opcode);
            break;
        case 0x2:
            execute_subroutine_2NNN(opcode);
            break;
        case 0x3:
            skip_if_VX_equals_NN_3XNN(opcode);
            break;
        case 0x4:
            skip_if_not_VX_equal_NN_4XNN(opcode);
            break;
        case 0x5:
            skip_if_VX_equal_VY_5XY0(opcode);
            break;
        case 0x6:
            load_NN_into_VX_6XNN(opcode);
            break;
        case 0x7:
            add_NN_to_VX_7XNN(opcode);
            break;
        case 0x8:
            switch(opcode & 0xF) {
                case 0x0: 
                    mov_VX_to_VY_8XY0(opcode);
                    break;
                case 0x1: 
                    set_VX_to_VX_OR_VY_8XY1(opcode);
                    break;
                case 0x2: 
                    set_VX_to_VX_AND_VY_8XY2(opcode);
                    break;
                case 0x3: 
                    set_VX_to_VX_XOR_VY_8XY3(opcode);
                    break;
                case 0x4: 
                    add_VY_to_VX_8XY4(opcode);
                    break;
                case 0x5: 
                    sub_VY_from_VX_8XY5(opcode);
                    break;
                case 0x6: 
                    right_shift_VY_store_in_VX_8XY6(opcode);
                    break;
                case 0x7: 
                    set_VX_to_VY_minus_VX_8XY7(opcode); 
                    break;
                case 0xE: 
                    left_shift_VY_store_in_VX_8XYE(opcode);
                    break;
                default:
                    printf("Instruction is not implemented (undocumented) : %04X\n", opcode);
            }
            break;
        case 0x9:
            if ((opcode & 0xF) == 0x0)
                skip_if_VX_not_equal_VY_9XY0(opcode);
            else
                printf("Instruction is not implemented (undocumented) : %04X\n", opcode);
            break;
        case 0xA:
            store_NNN_in_I_ANNN(opcode);
            break;
        case 0xB:
            jump_to_NNN_plus_V0_BNNN(opcode);
            break;
        case 0xC:
            set_VX_to_random_with_mask_NN_CXNN(opcode);
            break;
        case 0xD:
            draw_N_sprite_at_VX_VY_DXYN( opcode);
            break;
        case 0xE:
            if ((opcode & 0xFF) == 0x9E)
                skip_if_VX_key_pressed_EX9E(opcode);
            else if ((opcode & 0xFF) == 0xA1)
                skip_if_VX_not_pressed_EXA1(opcode);
            else
                printf("Instruction is not implemented (undocumented) : %04X\n", opcode);
            break;
        case 0xF:
            switch(opcode & 0xFF) {
                case 0x07:
                    store_delay_timer_in_VX_FX07(opcode);
                    break;
                case 0x0A:
                    store_keypress_in_VX_FX0A(opcode); 
                    break;
                case 0x15:
                    set_delay_timer_to_VX_FX15(opcode);
                    break;
                case 0x18:
                    set_sound_timer_to_VX_FX18(opcode);
                    break;
                case 0x1E:
                    add_VX_to_I_FX1E(opcode);
                    break;
                case 0x29:
                    set_I_to_addr_of_VX_sprite_FX29(opcode);
                    break;
                case 0x33:
                    store_VX_as_BCD_at_I_FX33(opcode);
                    break;
                case 0x55:
                    store_V0_to_VX_in_I_FX55(opcode);
                    break;
                case 0x65:
                    set_V0_to_VX_to_I_FX65(opcode);
                    break;
                default:
                    printf("Instruction is not implemented (undocumented) : %04X\n", opcode);
            }
            break;
        default:
            printf("[*] An error has been made by the author : %04X\n", opcode);
    }
 }

// main function 

int main(int argc, char* argv[]) {
    int i, zero_count;
    char* rom_path;
    unsigned char memory[MEM_SIZE];
    unsigned short opcode;
    if (argc < 2){
        printf("Error: No ROM specified.");
        printf("Usage: chip8_emulator <location of ROM>\n");
        exit(EXIT_FAILURE);
    }

    memset(memory, 0, sizeof(memory));
    rom_path = argv[1];
    load_process_image(memory, rom_path);

    // Iterate over opcodes in the file until end of memory
    zero_count = 0;
    for (i = 0; i < MEM_SIZE; i += 2) {
        opcode = (((unsigned short) memory[i]) << 8) + ((unsigned short) memory[i+1]); // reverse the byte order to little endian
        if (opcode == 0 && i != MEM_SIZE-2){
            zero_count++;
        }
        else if(zero_count) {
            printf("[%d NULL instructions 0000]\n", zero_count);
            zero_count = 0;
        } 
        else {
            decode_instruction(opcode);
        }
    }
    return 0;
}
