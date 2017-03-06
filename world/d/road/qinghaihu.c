
inherit ROOM;

void create()
{
	set("short", "Çàº£ºş");
	set("long", @LONG 
ÕâÀï¾ÍÊÇÖĞ¹ú×î´óµÄÄÚÂ½ºş²´£ºÇàº£ºş¡£ÕâÀïµÄºşË®ºÜÏÌ£¬
ÊÇÎŞ·¨ºÈµÄ¡£Ô¶Ô¶ÏòºşÃæÍûÈ¥£¬²¨ÌÎµãµã£¬µ«ÎŞÊ²Ã´¶¯¾²¡£
Î÷ÄÏ·½Ïò¾ÍÊÇÍ¨Íù½­ºşÈËÊ¿Ì¸»¢É«±äµÄĞÇËŞº£¡ Î÷±ßÔòÒªµ½À¥ÂØÉ½ÁË¡£
ËäÈ»ºÜÔ¶£¬µ«Ò²ÄÜÒÀÏ¡¿´µ½Î¡Î¡À¥ÂØÉ½µÄ°¨°¨°×Ñ©¡£
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"southeast" : "/d/xingxiu/rqhhtolz0",
	"southwest" : "/d/road/rqhhtoxsh0",
	"west" : "/d/road/rqhhtokl0",
]));

	setup();
	replace_program(ROOM);
}
