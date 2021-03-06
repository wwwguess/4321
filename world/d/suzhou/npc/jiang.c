//NPC:/d/suzhou/npc/jiang.c
//by dwolf
//97.11.4
//changed by tlang
//97.12.4

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(YEL"江小川"NOR, ({"jiang xiaochuan", "jiang" }));
	set("title", HIW"副总镖头"NOR);
	set("long",
	"他是镖局的副总镖头，由于总镖头年纪太大，现在镖局基本上由他掌管。\n"
	);

	set("gender", "男性");
	set("attitude", "heroism");
	
	set("age", 25);
	set("shen_type", 10);
	set("str", 35);
	set("int", 30);
	set("con", 30);
	set("dex", 25);
	set("per", 27);
	set("max_kee", 800);
	set("max_gin", 300);
	set("force", 800);
	set("max_force", 800);
	set("force_factor", 40);
	set("combat_exp", 200000);
	set("score", 10000);
	set("apply/attack",  40);
	set("apply/defense", 40);

	set_skill("force", 80);
	set_skill("blade", 90);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_skill("shaolin-shenfa", 80);
	set_skill("cibei-dao", 80);
	set_skill("hunyuan-yiqi", 80);
        set_skill("strike", 80);
	set_skill("sanhua-zhang", 80);

        map_skill("strike", "sanhua-zhang");
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("blade", "cibei-dao");
	map_skill("parry", "cibei-dao");

        prepare_skill("strike", "sanhua-zhang");


	setup();
	carry_object(__DIR__"obj/gangdao")->wield();
	carry_object(__DIR__"obj/cloth")->wear();
	add_money("gold", 1);
}

void init()
{
	object ob, me;
	me=this_player();

	 ::init();
        remove_call_out("greeting"); 
        call_out("greeting", 1, me); 
	add_action("do_accept", "accept");
	add_action("do_report", "report");

/*	if(!( ob = find_living("longwu")) )
	ob = load_object("/d/suzhou/npc/longwu");
	message_vision(HIY "$N躬身对龙五行礼：总镖头好！\n" NOR, this_object());*/
}

void greeting(object me)
{
	if( !me || environment(me) != environment() || !me->query("mark/护镖") ) return;
       	command("say 我为你找到一分好差事，护送左小姐到广州，你可同意(accept)？\n");
}

int do_accept()
{
	object me, ob, obj;
	me=this_player();
	
	if( !me->query("mark/护镖") ) return 0;
	else {
	if( me->query("mark/开始") )
		return notify_fail("你怎么还不快办这件事？\n");
	command("haha");
	command("say 这就是江南豪富左轻候的千金.你可先到门口带上两位趟子手。\n");
	ob=new("/d/suzhou/npc/gsnan");
	/*obj=new("/d/suzhou/npc/fighter");*/
	ob->move("/d/suzhou/bjdting");
	/*obj->move("/d/suzhou/bjdting");
	me->set("mark/开始", 1);*/
		return 1;
	}
	return 1;	
}

int do_report()
{
	object me,ob;
	me=this_player();

	if( !me->query("mark/成功") )
		return notify_fail("你还没有完成任务，报告什么啊。。。\n");
	command("haha");
	command("say 好样的。这是给你的俸金。\n");
	ob=new("obj/money/gold.c");
	ob->move(me);
	me->add("combat_exp", 1000);
	me->delete("mark/成功");
		return 1;
}	
		 