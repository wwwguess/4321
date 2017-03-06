// dblade.c                         
#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name(RED"ÎŞÇéµ¶"NOR, ({ "wuqing blade", "blade" }) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", "±ùÀäµÄµ¶Éí·¢³öÈÃÈËµ¨º®µÄÇà¹â,ÈÃÈË²»º®¶øÀõ£/\n");
		set("value", 40000);
		set("material", "greysteel");
		set("wield_msg", RED"$NÀäĞ¦Ò»Éù£¬´Ó¿ÕÖĞ°Ñ³öÒ»°Ñº®¹â
ËÄÉäµÄ±¦µ¶½ÓÔÚÊÖÖĞ¡£\n" NOR);
		set("unwield_msg",RED"$N½«ÊÖÖĞµÄÎŞÇéµ¶²å»ØÑü¼ä¡£\n" NOR);
	}
	init_blade(50);
	setup();
}
