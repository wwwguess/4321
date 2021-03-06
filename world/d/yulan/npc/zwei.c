// master.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
	set_name("悲愤云烟", ({ "zwei" }) );

	set("nickname", HIR"烈焰女侠"NOR);
	set("gender", "女性");
	set("age", 26);
	set("long",
		"悲愤云烟在江湖中游走多年，终于练成了绝世武功。\n"
		"武林中人人都想拜她为师，可少有成功者。\n"
            );
	set("attitude", "peaceful");

	set("str", 30);
	set("int", 24);
	set("cor", 30);
	set("cps", 30);
        set("per", 30);

	set("force", 10000);
	set("max_force", 5000);
	set("force_factor", 100);

	set("combat_exp", 13000000);
	set("score", 130000);
	set("env/wimpy", 50);
	
	//set("chat_chance", 30);
//	set("chat_msg", ({
//		(: random_move :)
//	}) );

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: consider :),
	}) );

	set_skill("unarmed", 130);
        set_skill("iceforce",130);
	set_skill("blade", 130);
	set_skill("throwing", 130);
	set_skill("force", 130);
	set_skill("parry", 130);
	set_skill("dodge", 130);
	set_skill("perception", 150);
	set_skill("stealing", 130);
        set_skill("stormdance",130);
        set_skill("tenderzhi",130);
	set_skill("spicyclaw", 130);
        set_skill("celestial",130);
     set_skill("spring-blade",130);
     set_skill("fonxansword",130);
        set_skill("celestrike",130);
        set_skill("mysterrier",130);
      set_skill("sword",130);
	set_skill("serpentforce", 100);
        set_skill("necromancy",130);
        set_skill("literate",130);
	map_skill("unarmed", "tenderzhi");
	map_skill("force", "iceforce");
        map_skill("dodge","stormdance");
       
	create_family("云烟派", 1, "掌门");

	setup();
        carry_object("/d/snow/obj/pink_cloth")->wear();
}


void attempt_apprentice(object me)
{
        if ((int)me->query("shen") <30000) {
                command("say 学武之人，德义为先，功夫的高低倒还在其次。");
                command("say 在德行方面，" + RANK_D->query_respect(me) +
                        "是否还做得不够？");
                return;
        }
        else if(me->query("combat_exp")<40000){
          command("say 你的经验还不够，再多练些年吧。");
          return;
        }else {
               command("smile");
               command("recruit "+me->query("id"));
          me->set("betrayer",0);
               return;
               }  

}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "legend");
}


