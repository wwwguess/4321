// dmlzh.c 达摩老祖
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_me();
void create()
{
	set_name("达摩老祖", ({ "da mo lao zu", "da","lao zu" }));
	//set("nickname", "少林派祖师");
        set("title",HIR "少"+HIB"林"+HIY "派" NOR + "祖师");
	set("long", "这是少林派的开山祖师达摩老祖\n
		他身材高大,看起来不知有多大年纪,目光如炬,神光湛然.\n");
	set("gender","男性");
	set("age", 100);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 50);
	set("int", 50);
	set("con", 50);
	set("dex", 50);
	
	set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                ("\n"+ RED "达摩老祖说道：你武功虽然不错, 但要谨记练武乃济世扶民之用!\n\n" NOR),
                (: exert_function, "hunyuan-yiqi" :),
		(: exert_function, "recover" :),
        }) );

	set("max_kee", 7000);
	set("max_gin", 7000);
	set("force", 10000);
	set("max_force", 7000);
	set("force_factor", 150);
	set("combat_exp", 3000000);
	set("score", 0);

	set_skill("force", 220);
	set_skill("hunyuan-yiqi", 220);
	set_skill("dodge", 220);
	set_skill("cuff", 220);
	set_skill("jingang-quan", 220);
	set_skill("sword", 220);
	set_skill("parry", 220);
	set_skill("damo-jian", 220);
	set_skill("literate", 300);
   set_skill("shaolin-shenfa",220);
 /*    set_skill("yijing-xinfa",200); */

	map_skill("force", "hunyuan-yiqi");
	map_skill("cuff", "jingang-quan");
	map_skill("parry", "jingang-quan");
	map_skill("sword", "damo-jian");
	map_skill("dodge", "shaolin-shenfa");

	prepare_skill("cuff", "jingang-quan");

	create_family("少林派", 1, "祖师");
	setup();

           carry_object("/d/shaolin/obj/jingang-zhao")->wear();
	


	set("inquiry", ([
		"舍利子"     : (: ask_me :),
	]));

	set("count", 1);

	setup();

}

void init()
{
	object me, ob;
	mapping fam;

	me = this_player();
	ob = this_object();

	::init();
	if( interactive(me) ) 
	{
		if ( mapp(fam = me->query("family")) && fam["family_name"] == "少林派" 
                && fam["generation"] == 35 ) 
		{
	                me->set_temp("fighter", 1);
			return;
		}

		if ( mapp(fam = me->query("family")) && fam["family_name"] == "少林派" 
		&& fam["generation"] > 35 		
		&& me->query("kee") < 50 ) 
		{
			me->move("/d/shaolin/damodong");
			me->unconcious();
			return;
		}

		COMBAT_D->do_attack(ob, me, query_temp("weapon") );
		
		me->set_temp("fighter", 1);

		ob->fight_ob(me);
		me->fight_ob(ob);

		call_out("halt", 10);

		return;
	}

	return;
}

void halt()
{
	command("say 好吧，大家住手！ 看这家伙有什么话要说！");
	command("halt");
}

string ask_me()
{
	mapping fam; 
	object ob;
	
	if ( !this_player()->query_temp("fighter") 
	||    this_player()->query("combat_exp") < 50000 )
	{
		command("say 大胆鼠辈，乳臭未干，竟敢闯入本寺圣地，且让老衲来超度与你！");
		this_object()->kill_ob(this_player());
		this_player()->kill_ob(this_object());
	}

	if ( present("she lizi", this_player()) )
		return RANK_D->query_respect(this_player()) + 
               "你身上不是已经有舍利子吗，真是贪得无餍！";
	if (query("count") < 1)
		return "抱歉，你来晚了，舍利子已经给人取走了。";

	ob = new("/d/shaolin/obj/she-lizi");
	ob->move(this_player());

	add("count", -1);

	message_vision("\n达摩点点头，从怀里取出舍利子交给$N。\n\n", this_player());

	return "你既然能找到我,也算是造化了,这舍利子乃我佛释伽牟尼的遗物,你可要好好珍惜.";
}
#include "/class/shaolin/damo.h"
