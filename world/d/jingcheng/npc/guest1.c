//guest1.c
//by dwolf 

#include <ansi.h>

inherit NPC;

void create()
{
        set_name(YEL"����"NOR, ({ "ke ren", "ren" }));
	set("shen_type", 0);

	set("str", 25);
	set("gender", "����");
	set("age", 30);
	set("long", "һ�����������Ѱ���ˡ�������ȥû��ʲô�ر�ġ�\n");
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
                YEL"��ط��治������̬��Ҳ�á��һ�Ҫ����ˡ�\n"NOR, 
		YEL"���֣������Ҳ������Ҽ�������졣\n"NOR,
        }) );

	add_money("coin", 50);
}

