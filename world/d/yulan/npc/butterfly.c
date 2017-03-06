// master.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
	set_name("������", ({ "butterfly" }) );

	set("nickname", HIR"����Ů��"NOR);
	set("gender", "Ů��");
	set("age", 26);
	set("long",
		"�����ɵڶ������ӡ�\n"
            );
	set("attitude", "peaceful");

	set("str", 30);
	set("int", 24);
	set("cor", 30);
	set("cps", 30);
        set("per", 30);

	set("force", 1000);
	set("max_force", 500);
	set("force_factor", 10);

	set("combat_exp", 500);
	set("score", 500);
	set("env/wimpy", 50);
	
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: consider :),
	}) );

	set_skill("unarmed", 50);
        set_skill("iceforce",50);
	set_skill("force", 50);
	set_skill("parry", 50);
	set_skill("dodge", 50);
	set_skill("perception", 150);
	set_skill("stealing", 50);
        set_skill("stormdance",50);
        set_skill("tenderzhi",50);
        set_skill("literate",50);
	map_skill("unarmed", "tenderzhi");
	map_skill("force", "iceforce");
        map_skill("dodge","stormdance");
       
        create_family("������", 2, "����");

	setup();
        carry_object("/d/snow/obj/pink_cloth")->wear();
}


void attempt_apprentice(object me)
{
        if(me->query("combat_exp")<500){
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


