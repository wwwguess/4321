//liver.c
//by dwolf 

#include <ansi.h>

inherit NPC;

void create()
{
        set_name(YEL"������"NOR, ({ "nan zhu ren", "ren" }));
	set("shen_type", 1);

	set("str", 25);
	set("gender", "����");
	set("age", 30);
	set("long", "һ����ƽ���ĳ��о���\n");
	set("combat_exp", 1000);
        set("kee", 150);
        set("max_kee", 150);
	set("attitude", "friendly");
	set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_temp("apply/attack", 5);
        set_temp("apply/defense", 5);
	   
        setup();
	set("chat_chance", 10);
        set("chat_msg", ({
                YEL"��Ȣ��������һ�������ӣ���κ���\n"NOR, 
		YEL"����ķ������������ɡ��Ǻǣ���\n"NOR,
        }) );

	add_money("coin", 50);
}

