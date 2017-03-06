// master.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
	set_name("��������", ({ "zwei" }) );

	set("nickname", HIR"����Ů��"NOR);
	set("gender", "Ů��");
	set("age", 26);
	set("long",
		"���������ڽ��������߶��꣬���������˾����书��\n"
		"���������˶������Ϊʦ�������гɹ��ߡ�\n"
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
       
	create_family("������", 1, "����");

	setup();
        carry_object("/d/snow/obj/pink_cloth")->wear();
}


void attempt_apprentice(object me)
{
        if ((int)me->query("shen") <30000) {
                command("say ѧ��֮�ˣ�����Ϊ�ȣ�����ĸߵ͵�������Ρ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(me) +
                        "�Ƿ����ò�����");
                return;
        }
        else if(me->query("combat_exp")<40000){
          command("say ��ľ��黹�������ٶ���Щ��ɡ�");
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


