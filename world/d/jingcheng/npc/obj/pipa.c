// pipa.c
// Made by ysgl (1997.10.23)

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("°×ÓñÅıÅÃ", ({ "baiyu pipa", "pipa", "°×ÓñÅıÅÃ"}) );
        set_weight(8000);
        set_max_encumbrance(8000);
        set("no_shown", 1);
	set("skill", ([
                "name":                 "music",
                "exp_required": 	5000,                
                "sen_cost":             40,     
                "difficulty":   50,            
                "max_skill":    50,           
        ]) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("prep", "on");
                set("unit", "ÕÅ");
                set("long", "Ò»ÕÅ°×ÓñÅıÅÃ£¬¹ÅÉ«¹ÅÏã£¬½ĞÈË°®²»ÊÍÊÖ¡£\n");
                set("value", 5000);
                set("material", "jade");
        }
}             

int is_container() { return 1; }

void owner_is_killed() 
{ 
        remove_call_out("dest");
        call_out("dest", 1, this_object());
}

void dest(object ob)
{
	destruct(ob);
}
