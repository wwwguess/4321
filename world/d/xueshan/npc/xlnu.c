//room: /d/fgszhuang/npc/xlnu.c
//by dwolf
//97.11.9

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(MAG"小龙女"NOR, ({ "xiao longnu", "xiao" }) );
        set("title", "世外美女");
        set("gender", "女性" );
        set("age", 32);
        set("long", "她从小住在古墓中，后来和杨过相遇，可惜后来又失散了。\n");
	set("str", 20);
	set("per", 40);      
	set("int", 25); 
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 150);
        set("combat_exp", 2000000);
        set("attitude", "peaceful");
        set_skill("unarmed", 100);
        set_skill("parry", 200);
        set_skill("dodge", 200);
	set_skill("sword", 200);
	set_skill("force", 200);      
	set_skill("jiuyin", 200);
	set_skill("zhuifeng-liushi", 200);
	map_skill("dodge", "zhuifeng-liushi"); 
	map_skill("force", "jiuyin");

        set("inquiry", ([
		"杨过" : "过儿？你莫非知道过儿在哪儿？你能让我们见面吗？\n",
	]));
	
	create_family("古墓派", 3, "弟子"); 
	
	setup();
	carry_object("/obj/cloth/cloth")->wear();
	carry_object("/obj/weapon/gangjian")->wield();

}

void init()
{                                     
	add_action("do_pray", "pray");
}     

int do_pray(string arg)
{                 
	object me,obj,ob;
	me = this_player();
	obj = this_object(); 
	
	if( !arg || arg=="" ) return 0;  
	
	if(query_temp("mark/been_done"))
	{      
		remove_call_out("done");
		call_out("done", 1, me); 
		command("waggle");
		return notify_fail("你太贪婪了，你呼唤不出杨过了。\n");
	}  

        if( arg=="有情人皆成眷属" ||  arg=="神雕侠侣") 
	{
		message("vision", RED"你合手祈祷：“愿天下有情人都成眷属。\n"NOR, me);
		command("thank");
		ob = new(__DIR__"yguo2");
		ob->move("/d/xueshan/jqgdi");
		me->add("combat_exp", 2000);
		set_temp("mark/been_done", 1);
		tell_room("/d/xueshan/jqgdi", YEL"杨过忽然从天而降。小龙女惊喜地迎了上去。\n"NOR); 
		return 1;      
	}
}
                                 
void done(object me)
{
	command("thank");
}               
