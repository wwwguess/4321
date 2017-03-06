//NPC:/d/suzhou/npc/furen.c
//by dwolf
//97.11.4
       
#include <ansi.h>
inherit NPC;

void create()
{
        set_name(MAG"����"NOR, ({"fu ren", "ren" }));
	set("long",
	"���Ǳ��صĸ��ˣ����ҽ���ͷ����,����������ʱ��������������֮�ġ�\n"
	);

	set("gender", "����");
	set("attitude", "peaceful");
	
	set("age", 45);
	set("shen_type", -1);
	set("str", 15);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
	set("per", 17);
	set("max_kee", 200);
	set("max_gin", 100);
	set("force", 50);
	set("max_force", 50);
	set("force_factor", 0);
	set("combat_exp", 10000);
	set("score", 10);
	set("apply/attack",  10);
	set("apply/defense", 10);

	set_skill("force", 20);
	set_skill("blade", 20);
	set_skill("dodge", 20);
	set_skill("parry", 20);
              
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
        add_money("gold", 2);
}

