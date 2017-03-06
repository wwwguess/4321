
inherit ROOM;

void create()
{
	set("short", "É½º£¹Ø");
	set("long", @LONG
Õâ¾ÍÊÇºÅ³Æ¡°ÌìÏÂµÚÒ»¹Ø¡±µÄÉ½º£¹ØÁË¡£É½º£¹ØÊÇÍòÀï³¤³ÇµÄ×î¶«¶Ë£¬
ÕâÀïÒÀÉ½°øº££¬µØÊÆÏÕÒª£¬ÊÇ½ø³ö¶«±±µÄÃÅ»§¡£Òò´ËÉ½º£¹Ø×Ô¹ÅÒÔÀ´¾ÍÊÇ
±ø¼Ò±ØÕùÖ®µØ¡ ¶«Ãæ¾ÍÊÇ¶óÊØÉ½º£¹ØµÄ±øÓª£¬ÓÉÕò±±´ó½«¾üÎâËÄ¹ó°ÑÊØ¡££
±±Ãæ¾ÍÍ¨Íù¶«±±µØÇøÁË¡£
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/rshgtoft0",
	"southwest" : "/d/road/rjdtoshg4",
	"east" 		: "/d/shhg/camp1",
]));

	setup();
	replace_program(ROOM);
}
