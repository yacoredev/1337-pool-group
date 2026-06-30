/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 21:27:36 by ybaadi            #+#    #+#             */
/*   Updated: 2026/06/11 16:43:36 by ybaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
    Output format
    [address]: [hex content] [ascii content]
---------------------------------------------------------------------------------
    idea:
    char str[] = "hello";

    void *add = str;

    long curr_addr = (long *)add;
    unsigned char *ptrToBytesOfaddr = (unsigned char *)&curr_addr;
    *//*
        curr_addr = current value of address (8bytes) as a decimal number
        but ghayb9a ychof gher 1byte mn dik 8bytes li mkhzen
        fiha address (&str[i])

        (dak decimal number kaytkhzan fl memory as a hexa mfar9a 3la 8bytes)

        next pointer of (e)
        add++;
    *//*

    printf("%p\n", &str[0]);          // 0x 00 00 7f fe ea 1a 8f 42
    printf("%p", *ptrToBytesOfaddr);  // 0x 42

---------------------------------------------------------------------------------
    How it works:

    exp: &str[0]  = 00 00 7f ff a3 17 bc 02
    add = &str[0] = 00 00 7f ff a3 17 bc 02

    bytes_of_addr = add = 00 00 7f ff a3 17 bc 02
    hna khezzant value dyal add (address of str[0]) ka number Decimal
    had number kaytstora fi 8bytes bdabt dakchi lach drt type dyal variable
    long bach yhez dik 8bytes kolha.

    *ptr_to_addr = bytes_of_addr = 02
    pointer 3la value of bytes_of_addr (li hya nit l'address of &str[0])
    but ghayb9a ychof gher 1byte mn dik 8bytes because type
    of ptr_to_addr is (unsigned char *)

    Imp:
    hna sta3malt (unsigned char *) 7it kan9ra raw bytes mn memory so dak byte
    momkin tkon fih FF li hya 255. but kon drt char li range dyalo 7tal 127
    ila 9rit byte li fih FF ghadi yw93 over flow y3ti -1
    donc kaywli t3bir ghalt, base[-1 / 16]
*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void    ft_print_hexa(unsigned char c)
{
    char    *hexaBAse = "0123456789abcdef";

    ft_putchar(hexaBAse[c/16]);
    ft_putchar(hexaBAse[c%16]);
}

void    *ft_print_memory(void *addr, unsigned int size)
{
    unsigned long            start_line_addr;
    unsigned char   *ptr_to_bytes;
    unsigned char   *element_of_array;
    int             i;
    int             k;

    if (!size)
    {
        return (addr);
    }

    i = 0;
    while (i < size)
    {
        start_line_addr = (unsigned long)addr + i;
        ptr_to_bytes = (unsigned char *)&start_line_addr;  // access to current address byte by byte
        element_of_array = (unsigned char *)addr;

        /*
            Step 1: print address of pointer (start_line_addr) byte by byte
            lpointer addr kayhaz 8bytes y3ni khasni nmtal kol 1byte b 2digits fl hexa.
            indexing of bytes:  0--> 00 00 00 01 0a 16 1f 40 <--7
        */
        k = sizeof(void *) - 1;
        while (k >= 0)
        {
            // send last byte, ft_print_hexa(decimal number) ...
            ft_print_hexa(ptr_to_bytes[k--]);
        }
        ft_putchar(':');
        ft_putchar(' ');

        // Step 2: print line (16 elements) in hexadecimal
        k = i;
        while (k < i + 16)
        {
            /*
                kaloopi 3la 16 bytes kol mrra (k < i + 16).

                madam ba9i mawsltch end of array (k < size) b9a tprinti dik 16bytes,
                ila tsalat array w ba9i maprintit 16bytes kamla fline lkhrani,
                kandoz lnext condition:
                3mmar blast kol byte b 2space 7ta nkmal 16bytes.

                -> mabin kol two bytes kandir space.
            */
            if (k < size)
                // kola 1byte kanmtlo b 2 digits
                ft_print_hexa(element_of_array[k]);
            else
            {
                // else kola 1byte kanmtlo b 2 space
                ft_putchar(' ');
                ft_putchar(' ');
            }
            if (k % 2)
                ft_putchar(' ');
            k++;
        }

        // Step 3: print line (16 elements) as ascii characters
        k = i;
        while (k < i + 16 && k < size)
        {
            // replace non-printable character with a dot
            if (element_of_array[k] >= ' ' && element_of_array[k] <= '~')
                ft_putchar(element_of_array[k]);
            else
                ft_putchar('.');
            k++;
        }

        /*
            7it i katincrement b 16 y3ni flakhir i ghatfot size b 16,

            donc kola line kanzido 16 w kanchof ila khrjt 3la size y3ni hadak
            akher line fl array.
        */
        if (i + 16 < size)
            ft_putchar('\n');
        i += 16;
    }
    return (addr);
}

#include <stdio.h>
int     main(void)
{
    char s[] = "Bonjour les aminches\t\n\tc\7 est fou\t"
            "tout\tce qu on peut faire avec\t\t\n"
            "print_memory\n\n\n\tlol.lol\n ";

    // printf("%p\n", (s+16));
    // printf("%c\n", *(s+16));

    ft_print_memory(s, sizeof(s));
    ft_putchar('\n');

    return (0);
}