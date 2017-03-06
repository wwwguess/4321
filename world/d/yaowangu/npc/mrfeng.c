//mrfeng.c
//by dwolf
//97.11.9

#include <ansi.h>
inherit NPC;
string ask_me();

void create()
{
	set_name(GRN"苗人凤"NOR, ({ "miao renfeng","miao" }) );
	set("gender", "男性" );
	set("age", 53);
	set("title",RED"飞剑客"NOR);
	set("long", "他就是当代大侠苗人凤，也就是吹雪山庄的庄主，他看上去神色黯然。\n");

	set("combat_exp", 2000000);
	set("attitude", "peaceful");
	set("rank_info/respect", "大侠");    
	set("inquiry", ([
		"苗若兰" : "正是小女，你可知道她在哪儿？",
	]));

	setup();
	add_money("gold", 10);
}       

void init()
{       
        object ob; 
        mapping myfam; 

        ob = this_player();

        ::init();
        remove_call_out("greeting"); 
	call_out("greeting", 1, ob);    
	add_action("do_swear", "swear");
}
int accept_object(object me, object what)
{                                 
        if( !me->query("mark/玉佩") ) return 0;
    	command("xixi");
        command("say 你既然帮了我，我就让你到宝库中取一样宝物吧。你且发誓(swear)只拿一件。\n");  
	me->delete("mark/玉佩");
        remove_call_out("dest");
        call_out("dest", 1, what);
        return 1;                   
}
void greeting(object ob) 
{       
        if( !ob || environment(ob) != environment() ) return; 
	command("say 小兄弟找到这儿，可有小女的消息？\n");
}                                   


int accept_fight(object me)
{
        command	("say 原来你是来这儿捣乱来的？");
        command("chat 各位，这位" + RANK_D->query_respect(me) + "想到吹雪山庄来捣乱，我就不客气了。\n"); 
        command("hehe");
        kill_ob(me);
        return 1;        
}              

int do_swear(string arg)
{                 
	object ob,me;
	me = this_player();

	if( !arg || arg=="" ) return 0;    

        if( arg=="只拿一件"
	||  arg=="守诺言") 
	{
		command("haha");
		message("vision", MAG"苗人凤不知怎么把$N弄得不见了。\n"NOR, me);
		me->move("/d/xueshan/llou2");
		tell_room("/d/xueshan/llou2", RED"$N忽然从天而降。\n"NOR,me); 
		destruct(this_object());
		return 1;      
	}
}
                      

