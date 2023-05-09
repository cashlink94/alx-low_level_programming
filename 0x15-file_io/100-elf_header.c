#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

void print_error(char *error_message);

/**
 * main - displays the information contained in the ELF header
 * of an ELF file.
 * @argc: argument count.
 * @argv: argument vector.
 *
 * Return: 0 on success, 98 on failure.
 */
int main(int argc, char **argv)
{
	int fd, i;
	Elf64_Ehdr *ehdr;
	char magic[4] = {0x7f, 'E', 'L', 'F'};

	if (argc != 2)
		print_error("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("Error: Cannot read file");

	ehdr = malloc(sizeof(Elf64_Ehdr));
	if (!ehdr)
		print_error("Error: malloc failed");

	if (read(fd, ehdr, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
		print_error("Error: Cannot read ELF header");

	for (i = 0; i < 4; i++)
		if (ehdr->e_ident[i] != magic[i])
			print_error("Error: Not an ELF file");

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", ehdr->e_ident[i], i == EI_NIDENT - 1 ? '\n' : ' ');

	printf("  Class:                             %s\n",
			ehdr->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" :
			ehdr->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" :
			"Invalid class");

	printf("  Data:                              %s\n",
			ehdr->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
			ehdr->e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" :
			"Invalid data encoding");

	printf("  Version:                           %d (current)\n",
			ehdr->e_ident[EI_VERSION]);

	printf("  OS/ABI:                            %s\n",
			ehdr->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" :
			ehdr->e_ident[EI_OSABI] == ELFOSABI_LINUX ? "UNIX - Linux" :
			ehdr->e_ident[EI_OSABI] == ELFOSABI_SOLARIS ? "UNIX - Solaris" :
			"Other");

	printf("  ABI Version:                       %d\n",
			ehdr->e_ident[EI_ABIVERSION]);

	printf("  Type:                              %s\n",
			ehdr->e_type == ET_NONE ? "NONE (No file type)" :
			ehdr->e_type == ET_REL ? "REL (Relocatable file)" :
			ehdr->e_type == ET_EXEC ? "EXEC (Executable file)" :
			ehdr->e_type == ET_DYN ? "DYN (Shared object file)" :
			ehdr->e_type == ET_CORE ? "CORE (Core file)" :
			"Unknown");

	printf("  Entry point address:               %p\n",
			(void *)(uintptr_t)ehdr->e_entry);

	free(ehdr);


