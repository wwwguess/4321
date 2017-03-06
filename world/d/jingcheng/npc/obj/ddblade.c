// dblade.c                         
#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name(YEL"¶àÇéµ¶"NOR, ({ "wuqing blade", "blade" }) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", "½ğÉ«µÄµ¶Éí·¢³öÑ£Ä¿µÄ¹âÃ¢,ÕæÊÇÒ»°ÑºÃµ¶!£/\n");
		set("value", 4000);
		set("material", "greysteel");
		set("wield_msg", YEL"$N³¤Ì¾Ò»Éù£¬´Ó¿ÕÖĞ°Ñ³öÒ»°Ñ½ğ¹â
ËÄÉäµÄ±¦µ¶½ÓÔÚÊÖÖĞ¡£\n" NOR);
		set("unwield_msg",YEL"$N½«ÊÖÖĞµÄ¶àÇéµ¶²å»ØÑü¼ä¡£\n" NOR);
	}
	init_blade(50);
	setup();
}
