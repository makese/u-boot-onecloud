/*

 *
 */

#ifndef _CPU_H
#define _CPU_H
#if CONFIG_AML_MESON==0
#error please define CONFIG_AML_MESON
#endif
#if CONFIG_M1==0
#error please define CONFIG_M1
#endif
//U boot code control
#define CONFIG_SYS_NO_FLASH 1
#define CONFIG_NR_DRAM_BANKS 1

#define CONFIG_BAUDRATE                 115200
#define CONFIG_SYS_BAUDRATE_TABLE       { 9600, 19200, 38400, 57600, 115200}

#define CONFIG_SYS_SDRAM_BASE   0x80000000

#define CONFIG_SYS_INIT_SP_ADDR (CONFIG_SYS_SDRAM_BASE+0x8F800000)
#define CONFIG_SYS_TEXT_BASE    0x8F800000
#define CONFIG_SYS_MALLOC_LEN   (4<<20)
#define CONFIG_ENV_SIZE         (16 * 1024)
#define CONFIG_SYS_MAXARGS      16

#define CONFIG_ENV_IS_NOWHERE    1
#define CONFIG_SYS_LOAD_ADDR    0x82000000
#define CONFIG_SYS_CBSIZE          1024
#define CONFIG_SYS_PBSIZE (CONFIG_SYS_CBSIZE+sizeof(CONFIG_SYS_PROMPT)+16) /* Print Buffer Size */

/** Internal storage setting **/

#ifdef CONFIG_CMD_NAND
#define CONFIG_NAND_AML_M1 1
#define CONFIG_SYS_MAX_NAND_DEVICE	1		/* Max number of */
#define CONFIG_SYS_NAND_MAX_CHIPS	4
#endif

#ifdef CONFIG_CMD_SF
#define CONFIG_AMLOGIC_SPI_FLASH    1
#define CONFIG_SPI_FLASH            1
#define SPI_FLASH_CACHELINE         64 //amlogic special setting. in M1 , SPI_A for SPI flash
#define CONFIG_SPI_FLASH_MACRONIX   1
//#define CONFIG_SPI_FLASH_SPANSION   1
#define CONFIG_SPI_FLASH_SST        1
//#define CONFIG_SPI_FLASH_STMICRO    1
#define CONFIG_SPI_FLASH_WINBOND    1

#endif

#if CONFIG_NAND_AML_M1 || CONFIG_AMLOGIC_SPI_FLASH
#define CONFIG_MTD_DEVICE     1
#define CONFIG_MTD_PARTITIONS 1
#define CONFIG_CMD_MTDPARTS   1
#endif

#define CONFIG_AML_ROMBOOT    1
#define SPI_MEM_BASE                                0x40000000
#define AHB_SRAM_BASE                               0x49000000  // AHB-SRAM-BASE


#ifdef CONFIG_AML_ROMBOOT_SPL
#define SPL_STATIC_FUNC     static
#define SPL_STATIC_VAR      static
#else
#define SPL_STATIC_FUNC     
#define SPL_STATIC_VAR      
#endif
#endif /* _CPU_H */