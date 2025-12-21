#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include "esp_log.h"
#include "esp_event.h"
#include "driver/spi_master.h"
#include "driver/gpio.h"
#include "esp_lcd_types.h"

#if CONFIG_MPYTHON_PRO_BOARD
    #define BOARD_LCD_MOSI 37
    #define BOARD_LCD_MISO -1
    #define BOARD_LCD_SCK 36
    #define BOARD_LCD_CS 34
    #define BOARD_LCD_DC 35
    #define BOARD_LCD_RST -1
    #define BOARD_LCD_BL 33
    #define BOARD_LCD_PIXEL_CLOCK_HZ (60 * 1000 * 1000)
    #define BOARD_LCD_BK_LIGHT_ON_LEVEL 0
    #define BOARD_LCD_BK_LIGHT_OFF_LEVEL !BOARD_LCD_BK_LIGHT_ON_LEVEL
    #define BOARD_LCD_H_RES 320
    #define BOARD_LCD_V_RES 172
    #define BOARD_LCD_CMD_BITS 8
    #define BOARD_LCD_PARAM_BITS 8
    #define BOARD_LCD_RGB_ELE_ORDER LCD_RGB_ENDIAN_BGR
    #define BOARD_LCD_SWAP_XY    true
    #define BOARD_LCD_MIRROR_X   true
    #define BOARD_LCD_MIRROR_Y   true
    #define BOARD_LCD_GAP_X      0
    #define BOARD_LCD_GAP_Y      34
    #define BOARD_LCD_INVERT     false
#elif CONFIG_LABPLUS_LEDONG_V2_BOARD
    #define BOARD_LCD_MOSI 37
    #define BOARD_LCD_MISO -1
    #define BOARD_LCD_SCK 36
    #define BOARD_LCD_CS -1
    #define BOARD_LCD_DC 35
    #define BOARD_LCD_RST -1
    #define BOARD_LCD_BL -1
    #define BOARD_LCD_PIXEL_CLOCK_HZ (60 * 1000 * 1000)
    #define BOARD_LCD_BK_LIGHT_ON_LEVEL 0
    #define BOARD_LCD_BK_LIGHT_OFF_LEVEL !BOARD_LCD_BK_LIGHT_ON_LEVEL
    #define BOARD_LCD_H_RES 320
    #define BOARD_LCD_V_RES 172
    #define BOARD_LCD_CMD_BITS 8
    #define BOARD_LCD_PARAM_BITS 8
    #define BOARD_LCD_RGB_ELE_ORDER LCD_RGB_ENDIAN_BGR
    #define BOARD_LCD_SWAP_XY    true
    #define BOARD_LCD_MIRROR_X   true
    #define BOARD_LCD_MIRROR_Y   true
    #define BOARD_LCD_GAP_X      0
    #define BOARD_LCD_GAP_Y      34
    #define BOARD_LCD_INVERT     false
    #define BOARD_STM8_ADDR 17
    #define BOARD_STM8_CMD 4
#elif CONFIG_LABPLUS_XUNFEI_JS_PRIMARY_BOARD
    #define BOARD_LCD_MOSI 37
    #define BOARD_LCD_MISO -1
    #define BOARD_LCD_SCK 36
    #define BOARD_LCD_CS -1
    #define BOARD_LCD_DC 35
    #define BOARD_LCD_RST -1
    #define BOARD_LCD_BL 34
    #define BOARD_LCD_PIXEL_CLOCK_HZ (60 * 1000 * 1000)
    #define BOARD_LCD_BK_LIGHT_ON_LEVEL 1
    #define BOARD_LCD_BK_LIGHT_OFF_LEVEL !BOARD_LCD_BK_LIGHT_ON_LEVEL
    #define BOARD_LCD_H_RES 320
    #define BOARD_LCD_V_RES 172
    #define BOARD_LCD_CMD_BITS 8
    #define BOARD_LCD_PARAM_BITS 8
    #define BOARD_LCD_RGB_ELE_ORDER LCD_RGB_ENDIAN_BGR
    #define BOARD_LCD_SWAP_XY    true
    #define BOARD_LCD_MIRROR_X   true
    #define BOARD_LCD_MIRROR_Y   true
    #define BOARD_LCD_GAP_X      0
    #define BOARD_LCD_GAP_Y      34
    #define BOARD_LCD_INVERT     false
    #define BOARD_STM8_ADDR 15
    #define BOARD_STM8_CMD 8
#elif CONFIG_LABPLUS_XUNFEI_JS_MIDDLE_BOARD
    #define BOARD_LCD_MOSI 37
    #define BOARD_LCD_MISO -1
    #define BOARD_LCD_SCK 36
    #define BOARD_LCD_CS 34
    #define BOARD_LCD_DC 35
    #define BOARD_LCD_RST 47
    #define BOARD_LCD_BL 33
    #define BOARD_LCD_PIXEL_CLOCK_HZ (60 * 1000 * 1000)
    #define BOARD_LCD_BK_LIGHT_ON_LEVEL 1
    #define BOARD_LCD_BK_LIGHT_OFF_LEVEL !BOARD_LCD_BK_LIGHT_ON_LEVEL
    #define BOARD_LCD_H_RES 320
    #define BOARD_LCD_V_RES 172
    #define BOARD_LCD_CMD_BITS 8
    #define BOARD_LCD_PARAM_BITS 8
    #define BOARD_LCD_RGB_ELE_ORDER LCD_RGB_ENDIAN_BGR
    #define BOARD_LCD_SWAP_XY    true
    #define BOARD_LCD_MIRROR_X   true
    #define BOARD_LCD_MIRROR_Y   true
    #define BOARD_LCD_GAP_X      0
    #define BOARD_LCD_GAP_Y      34
    #define BOARD_LCD_INVERT     false
#endif

//---------------------颜色表--------------------
/*
aliceblue	    #f0f8ff	0xefbf	61375
antiquewhite	#faebd7	0xf75a	63322
aqua	        #00ffff	0x07ff	2047
aquamarine  	#7fffd4	0x7ffa	32762
azure       	#f0ffff	0xefff	61439
beige	        #f5f5dc	0xf7bb	63419
bisque	        #ffe4c4	0xff18	65304
black       	#000000	0x0000	0
blanchedalmond	#ffebcd	0xff59	65369
blue	        #0000ff	0x001f	31
blueviolet   	#8a2be2	0x897b	35195
brown       	#a52a2a	0xa145	41285
burlywood	    #deb887	0xddb0	56752
cadetblue	    #5f9ea0	0x64f3	25843
chartreuse    	#7fff00	0x7fe0	32736
chocolate	    #d2691e	0xd344	54084
coral       	#ff7f50	0xfbea	64490
cornflowerblue 	#6495ed	0x64bd	25789
cornsilk	    #fff8dc	0xffbb	65467
crimson     	#dc143c	0xd8a7	55463
cyan	        #00ffff	0x07ff	2047
darkblue	    #00008b	0x0011	17
darkcyan    	#008b8b	0x0451	1105
darkgoldenrod	#b8860b	0xb421	46113
darkgray	    #a9a9a9	0xad55	44373
darkgreen	    #006400	0x0320	800
darkgrey	    #a9a9a9	0xad55	44373
darkkhaki	    #bdb76b	0xbdad	48557
darkmagenta 	#8b008b	0x8811	34833
darkolivegreen	#556b2f	0x5346	21318
darkorange  	#ff8c00	0xfc60	64608
darkorchid  	#9932cc	0x9999	39321
darkred     	#8b0000	0x8800	34816
darksalmon  	#e9967a	0xe4af	58543
darkseagreen	#8fbc8f	0x8dd1	36305
darkslateblue	#483d8b	0x49f1	18929
darkslategray	#2f4f4f	0x328a	12938
darkslategrey	#2f4f4f	0x328a	12938
darkturquoise	#00ced1	0x0679	1657
darkviolet	    #9400d3	0x901a	36890
deeppink	    #ff1493	0xf8b2	63666
deepskyblue  	#00bfff	0x05ff	1535
dimgray     	#696969	0x6b4d	27469
dimgrey     	#696969	0x6b4d	27469
dodgerblue  	#1e90ff	0x249f	9375
firebrick	    #b22222	0xb104	45316
floralwhite  	#fffaf0	0xffdd	65501
forestgreen 	#228b22	0x2444	9284
fuchsia	        #ff00ff	0xf81f	63519
gainsboro   	#dcdcdc	0xdedb	57051
ghostwhite  	#f8f8ff	0xf7bf	63423
gold        	#ffd700	0xfea0	65184
goldenrod   	#daa520	0xdd24	56612
gray	        #808080	0x8410	33808
green	        #008000	0x0400	1024
greenyellow 	#adff2f	0xafe6	45030
grey	        #808080	0x8410	33808
honeydew	    #f0fff0	0xeffd	61437
hotpink	        #ff69b4	0xfb56	64342
indianred   	#cd5c5c	0xcaeb	51947
indigo      	#4b0082	0x4810	18448
ivory       	#fffff0	0xfffd	65533
khaki       	#f0e68c	0xef31	61233
lavender	    #e6e6fa	0xe73e	59198
lavenderblush	#fff0f5	0xff7e	65406
lawngreen	    #7cfc00	0x7fc0	32704
lemonchiffon	#fffacd	0xffd9	65497
lightblue   	#add8e6	0xaebc	44732
lightcoral  	#f08080	0xec10	60432
lightcyan   	#e0ffff	0xdfff	57343
lightgoldenrodyellow	#fafad2	0xf7da	63450
lightgray   	#d3d3d3	0xd69a	54938
lightgreen  	#90ee90	0x9772	38770
lightgrey   	#d3d3d3	0xd69a	54938
lightpink   	#ffb6c1	0xfdb7	64951
lightsalmon 	#ffa07a	0xfd0f	64783
lightseagreen	#20b2aa	0x2595	9621
lightskyblue	#87cefa	0x867e	34430
lightslategray	#778899	0x7453	29779
lightslategrey	#778899	0x7453	29779
lightsteelblue	#b0c4de	0xae1b	44571
lightyellow     #ffffe0	0xfffb	65531
lime	        #00ff00	0x07e0	2016
limegreen	    #32cd32	0x3666	13926
linen       	#faf0e6	0xf77c	63356
magenta     	#ff00ff	0xf81f	63519
maroon      	#800000	0x8000	32768
mediumaquamarine#66cdaa	0x6675	26229
mediumblue  	#0000cd	0x0019	25
mediumorchid	#ba55d3	0xbaba	47802
mediumpurple	#9370db	0x939b	37787
mediumseagreen	#3cb371	0x3d8e	15758
mediumslateblue	#7b68ee	0x7b5d	31581
mediumspringgreen	#00fa9a	0x07d3	2003
mediumturquoise	#48d1cc	0x4e99	20121
mediumvioletred	#c71585	0xc0b0	49328
midnightblue	#191970	0x18ce	6350
mintcream   	#f5fffa	0xf7fe	63486
mistyrose   	#ffe4e1	0xff1b	65307
moccasin    	#ffe4b5	0xff16	65302
navajowhite  	#ffdead	0xfef5	65269
navy	        #000080	0x0010	16
oldlace     	#fdf5e6	0xffbc	65468
olive       	#808000	0x8400	33792
olivedrab   	#6b8e23	0x6c64	27748
orange      	#ffa500	0xfd20	64800
orangered   	#ff4500	0xfa20	64032
orchid      	#da70d6	0xdb9a	56218
palegoldenrod	#eee8aa	0xef35	61237
palegreen   	#98fb98	0x97d2	38866
paleturquoise	#afeeee	0xaf7d	44925
palevioletred	#db7093	0xdb92	56210
papayawhip  	#ffefd5	0xff7a	65402
peachpuff   	#ffdab9	0xfed6	65238
peru        	#cd853f	0xcc28	52264
pink         	#ffc0cb	0xfdf9	65017
plum        	#dda0dd	0xdd1b	56603
powderblue   	#b0e0e6	0xaefc	44796
purple      	#800080	0x8010	32784
red         	#ff0000	0xf800	63488
rosybrown   	#bc8f8f	0xbc71	48241
royalblue   	#4169e1	0x435b	17243
saddlebrown 	#8b4513	0x8a22	35362
salmon      	#fa8072	0xf40e	62478
sandybrown   	#f4a460	0xf52c	62764
seagreen    	#2e8b57	0x344b	13387
seashell    	#fff5ee	0xffbd	65469
sienna      	#a0522d	0x9a85	39557
silver      	#c0c0c0	0xbdf7	48631
skyblue     	#87ceeb	0x867d	34429
slateblue    	#6a5acd	0x6ad9	27353
slategray   	#708090	0x7412	29714
slategrey   	#708090	0x7412	29714
snow        	#fffafa	0xffde	65502
springgreen  	#00ff7f	0x07ef	2031
steelblue   	#4682b4	0x4c16	19478
tan         	#d2b48c	0xd591	54673
teal       	    #008080	0x0410	1040
thistle     	#d8bfd8	0xd5fa	54778
tomato      	#ff6347	0xfb09	64265
turquoise   	#40e0d0	0x46f9	18169
viole       t	#ee82ee	0xec1d	60445
wheat       	#f5deb3	0xf6f6	63222
white       	#ffffff	0xffff	65535
whitesmoke   	#f5f5f5	0xf7be	63422
yellow      	#ffff00	0xffe0	65504
yellowgreen  	#9acd32	0x9e66	40550
*/
#define GUI_HotPink		            0xfb56		//热情的粉红
#define GUI_DeepPink		        0xF8B2		//深粉色
#define GUI_Purple		            0x8010		//紫色
#define GUI_Blue		            0x001F		//纯蓝
#define GUI_MediumBlue		        0x0019		//适中的蓝色
#define GUI_DarkBlue		        0x0011		//深蓝色
#define GUI_LightSkyBlue		    0x867e		//淡蓝色
#define GUI_SkyBlue		            0x867d		//天蓝色
#define GUI_DeepSkyBlue		        0x05ff		//深天蓝
#define GUI_LightBLue		        0xaebc		//淡蓝
#define GUI_LightCyan		        0xdfff		//淡青色
#define GUI_Cyan		            0x07ff		//青色
#define GUI_DarkCyan		        0x0451		//深青色
#define GUI_SpringGreen		        0x07ef		//春天的绿色
#define GUI_LightGreen		        0x9772		//淡绿色
#define GUI_Green		            0x0400		//纯绿
#define GUI_DarkGreen		        0x0320		//深绿色
#define GUI_GreenYellow		        0xafe6		//绿黄色
#define GUI_LightYellow		        0xfffb		//浅黄色
#define GUI_Yellow		            0xffe0		//纯黄
#define GUI_Gold		            0xfea0		//金
#define GUI_Orange		            0xfd20		//橙色
#define GUI_DarkOrange		        0xfc60		//深橙色
#define GUI_Red			            0xf800		//纯红
#define GUI_DarkRed		            0x8800		//深红色
#define GUI_Pink		            0xfdf9		//粉红
#define GUI_Brown		            0xa145		//棕色
#define GUI_White		            0xFFFF		//纯白
#define GUI_LightGray		        0xd69a		//浅灰色
#define GUI_DarkGray	            0xad55		//深灰色
#define GUI_Gray		            0x8410		//灰色
#define GUI_Black		            0x0000		//纯黑

typedef void (*transfer_done_cb_t)(void *);

typedef struct _lcd_t
{
    bool bus_initialized;

    transfer_done_cb_t transfer_done_cb;
    void *transfer_done_user_data;

    esp_lcd_panel_handle_t panel;
    esp_lcd_panel_io_handle_t io_handle;
    SemaphoreHandle_t dma_finish_sem;
    void *lcd_buf;
} lcd_t;

esp_err_t lcd_init(void);
esp_err_t lcd_deinit(void);
void lcd_draw_logo(void);
void lcd_set_color(int color);
void lcd_draw_image(int x, int y, int width, int height, const void *buff);
lcd_t *get_lcd_handle(void);
esp_err_t register_lcd(const QueueHandle_t frame_i, const QueueHandle_t frame_o, const bool return_fb);
void lcd_flush(const void *buff);

#ifdef __cplusplus
}
#endif
