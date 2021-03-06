//NPC:/d/suzhou/npc/jin.c
//by dwolf
//97.11.5
         
#include <ansi.h>
inherit NPC;            

string ask_me();

void create()
{
	set_name(HIW"金庸"NOR, ({ "jin yong", "jin" }));
	set("long", "金先生被称为当世第一大小说家，我们能在这儿玩mud，\n多亏他写的小说。 他身上仿佛藏着许多秘密。\n");
	set("gender", "男性");
	set("per", 33);      
	set("int", 50);
        set("age",45);
    
	set_skill("literate", 300);
	set_skill("leadership", 300);

	set_skill("iron-cloth",800);
	set_skill("unarmed", 500);
	set_skill("dodge", 500);
	set_skill("parry", 500);
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 300);
	set_temp("apply/damage", 150);

	set("combat_exp", 10000000);
	set("shen_type", 10);        
	set("inquiry", ([
		"小说" : (: ask_me :),	
	]));   
	add("count", 1);
	setup();
        
	add_money("gold", 10);
	carry_object(__DIR__"obj/jchmap");
}                                   

string ask_me()
{
	return command("haha") + "我的小说都送给杨知府他们了。你如果想看，可以去他们那儿。";
}                             


int recognize_apprentice(object ob)
{
	if (ob->query("family/family_name")=="朝廷")
		return 1;
	if (!(int)ob->query_temp("mark/金"))
		return 0; 
	ob->add_temp("mark/金", -1);
	return 1;
}                   



int accept_object(object who, object ob)
{
/*  lock this func dao 971206 
	if (!(int)who->query_temp("mark/金"))
		who->set_temp("mark/金", 0);
	if (ob->query("money_id") && ob->value() >= 1000) {
		message_vision("金庸同意指点$N一些读书写字的问题。\n", who);
		who->add_temp("mark/金", ob->value() / 50);
		return 1;
	}
*/
	return 0;
}      

void init()
{
	add_action("give_talk", "talk"); 
	add_action("do_wonder", "wonder");
	::init();
}

int give_talk()
{       
        mapping fam;
        object me;
        me = this_player();

        if ((int)me->query_skill("literate") < 100)  
                return command(RED"say 小兄弟知识太贫乏，老夫也无法为你提高潜能，呵呵.\n"NOR); 
        
        if (query("count") < 1)
                return command("sigh");
        
        add("count", -1);

        me->add("potential", 50);
        write(YEL"你和金老先生的谈话让你的潜能提高了。\n"NOR);
        return 1;
}

int do_wonder(string arg)
{                 
	object ob,me;
	me = this_player();

	if( !arg || arg=="" ) return 0;    
	
	if (query("count") < 1)
                return command("?");
        
        add("count", -1);

	if( arg=="绝情谷底"
	||  arg=="绝情谷") 
	{
		command("haha");
		message("vision", RED"金庸笑呵呵地拿出一块光碟给你。\n"NOR, me);
		ob = new("/d/suzhou/npc/obj/guangdie");
		ob ->move(me);

		return 1;      
	}
}
