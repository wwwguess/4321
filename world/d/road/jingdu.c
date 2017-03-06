// Room: /d/road/jingdu.c

inherit ROOM;

void create()
{
	set("short", "¾©¶¼ÄÏæäÕ¾");
	set("long", @LONG
ÄãÀ´µ½ÁË¾©³ÇÍâ¡£²»Ô¶´¦¿ÉÒÔ¿´µ½¸ßËÊµÄ³ÇÇ½ºÍ×Ï½û³ÇµÄÎİéÜ¡£³ÇÃÅ¿Ú
ºÜ¶àÓùÁÖ¾üÔÚÅÌ²éĞĞÈË¡£½üÀ´³¯Í¢¶Ô½­ºşÈËÎïÏŞÖÆºÜÑÏ£¬»¹ÊÇ²»Òªµ½Ìì×Ó
½ÅÏÂµ·ÂÒµÄºÃ¡£
    ÔÙÍù±±×ß¾Íµ½ÁË¾©Ê¦µÄÄÏÃÅ¡£¶«±±·½Ïòµ½É½º£¹Ø,Î÷ÄÏ·½Ïòµ½±£¶¨¡¢
¿ª·âµÈÄÏ·½¡£Ï.
LONG
	);
	set("exits", ([ /* sizeof() == 5 */
		"southwest" : __DIR__"rdktojd4",
		"southeast" : __DIR__"rjdtodk0",
		"north" : "/d/city/sroad1",
//		"west" : __DIR__"rjdtoly0",
		"northeast" : __DIR__"rjdtoshg0",
]));

	setup();
	replace_program(ROOM);
}
