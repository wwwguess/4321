// Filename : /u/ysgl/obj/clothes/hat.c
// Created by diablo (1997.10.31)
// The latest changed by diablo

#include <armor.h>           
inherit F_AUTOLOAD;            
inherit BOOTS;
void create()
{
	set_name("������", ({ "order" , "shoes" }));
	set("weight", 200);
        set("no_get",1);
        set("no_drop",1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
		set("value", 500);
		set("material", "leather");
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
