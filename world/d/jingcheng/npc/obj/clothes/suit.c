// Filename : /u/ysgl/obj/clothes/hat.c
// Created by diablo (1997.10.31)
// The latest changed by diablo

#include <armor.h>           
inherit F_AUTOLOAD;            
inherit CLOTH;
void create()
{
	set_name("������", ({ "order" , "cloth" }));
	set("weight", 300);
        set("no_get",1);
        set("no_drop",1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1000);
		set("material", "cloth");
		set("armor_prop/armor", 100);
	}
	setup();
}	

void init()
{                  
 	seteuid(geteuid());                  
}                          

int query_autoload()
{
	if( this_player()->query("id") == "xkx" )
		return 1;
	return 0;
}
