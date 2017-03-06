//OBJECT: /d/suzhou/npc/obj/guangdie.c
//by dwolf                   
//97.11.7

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name( GRN"光碟"NOR, ({ "guang die", "die" }) );  
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
		set("long", YEL"金庸先生给的一片光碟，不知道有什么用。\n"NOR);
                set("value", 10000);
        }
        setup();
}                                                    

void init()
{                            
	add_action("do_use", "use");
}

int do_use(string arg)
{                 
	object ob,me;
	me = this_player();   
	ob = this_object();

	if( !arg || arg=="" ) return 0;  

	if(query_temp("mark/been_used"))      
	{	
		 remove_call_out("dest");
		 call_out("dest", 1, ob);
		 return notify_fail("一阵烟雾笼罩过来，之后光盘就不见了。\n");   
        }
        if( arg=="光碟"
	||  arg=="光盘") 
	{
		message("vision", GRN"空中传来一阵刮来一阵仙风，把你带到了金庸身边！！盶n"NOR, me);
		me->move("/d/suzhou/shuyuan");
		tell_room("/d/suzhou/shuyuan", YEL"$N被一阵仙风带来。\n"NOR,me);      
		set_temp("mark/been_used",1);
	        	return 1;      
	}
}                           

void dest(object ob)
{
	destruct(ob);
}
                        
