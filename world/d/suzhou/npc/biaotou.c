//NPC:/d/suzhou/npc/biaotou.c 
//by dwolf
//97.11.4
         
#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIM"��ͷ"NOR, ({ "biao tou", "tou" }));
	set("age", 42);
	set("gender", "Ů��");
	set("long", "�����ǰ�������������ˣ����ھֵ���ͷ������ָ���������䡣\n");
	set("attitude", "heroism");

	set("str", 24);
	set("dex", 22);      
	set("per", 30);
	set("combat_exp", 100000);
	set("shen_type", 2);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("sword", 60);
	set_skill("force", 60);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 60);
	set_temp("apply/damage", 30);
	set_temp("apply/armor", 30);
              
	setup();
	carry_object(__DIR__"obj/gangjian")->wield();
	carry_object(__DIR__"obj/cloth")->wear();
}

