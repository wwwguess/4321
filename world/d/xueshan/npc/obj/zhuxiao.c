//OBJECT: /d/fgszhuang/npc/obj/xiao.c
//by dwolf                   
//97.11.7

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name( GRN"竹萧"NOR, ({ "xiao", "zhu xiao" }) );  
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
		set("long", MAG"一只竹箫。可以吹。"NOR);
                set("value", 10000);
        }
        setup();
}                                                    

void init()
{                            
	add_action("do_chui", "chui");
}

int do_chui(string arg)
{                         
	object me;  
	object obj;
	object ob;
	me = this_player();      
        
  	if ( ((int)me->query("kee") > 200) ||
             ((int)me->query("gin") < 200 ) )
             { 
       		tell_object(me, YEL"你拿出一只竹萧，吹了起来，箫声如怨如恕，让人感伤不已。\n"NOR); 
		return 1;
	     }
	message_vision(YEL"$N愉快地吹着竹箫。\n"NOR, me);
        me->add("kee", 10);
	me->receive_damage("gin", 10);   
		   
        if ( random(3) == 0 ) {
                message_vision(RED"$N微微一笑，拿出竹箫开始吹，箫声旋律优美，让人叹为观止。\n"NOR,me);
                me->add("kee", 50);
		me->receive_damage("gin", 50);
                return(1);
        }
        return(1);  
}
  

                 
