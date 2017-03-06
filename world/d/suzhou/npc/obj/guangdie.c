//OBJECT: /d/suzhou/npc/obj/guangdie.c
//by dwolf                   
//97.11.7

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name( GRN"���"NOR, ({ "guang die", "die" }) );  
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
		set("long", YEL"��ӹ��������һƬ�������֪����ʲô�á�\n"NOR);
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
		 return notify_fail("һ���������ֹ�����֮����̾Ͳ����ˡ�\n");   
        }
        if( arg=="���"
	||  arg=="����") 
	{
		message("vision", GRN"���д���һ�����һ���ɷ磬��������˽�ӹ��ߣ����\n"NOR, me);
		me->move("/d/suzhou/shuyuan");
		tell_room("/d/suzhou/shuyuan", YEL"$N��һ���ɷ������\n"NOR,me);      
		set_temp("mark/been_used",1);
	        	return 1;      
	}
}                           

void dest(object ob)
{
	destruct(ob);
}
                        
