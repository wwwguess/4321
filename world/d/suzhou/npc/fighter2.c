//NPC:/d/suzhou/npc/fighter2.c 
//by dwolf
//97.11.4
         
#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIW"�ھֵ���"NOR, ({ "biaoju dizi", "dizi", "fighter" }));
	set("age", 22);
	set("gender", "����");
	set("long", "�����ھֵĵ��ӣ������ڷ����䡣\n");
	set("attitude", "heroism");

	set("str", 24);
	set("dex", 22);
	set("combat_exp", 10000);
	set("shen_type", 1);

	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_skill("parry", 20);
	set_skill("blade", 20);
	set_skill("force", 20);
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 10);
	set_temp("apply/armor", 20);
              
	setup();
	carry_object(__DIR__"obj/zhudao")->wield();
	carry_object(__DIR__"obj/cloth")->wear();
}

